#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Inicialización de la matriz dp
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 15;  // Capacidad de la mochila
    vector<int> wt = {3, 7, 4, 2, 1, 6};  // Pesos de los objetos
    vector<int> val = {12, 3, 7, 4, 3, 8};  // Valores de los objetos
    int n = wt.size();

    cout << "El valor máximo que se puede obtener es: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
