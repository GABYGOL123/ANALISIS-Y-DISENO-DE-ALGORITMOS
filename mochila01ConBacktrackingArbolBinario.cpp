// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mochilaBinario(vector<int>&pesos,vector<int>&valores,int capacidad, int n, int i, int pesoActual, int valorActual, int & max_valor){
    
    if(i>n || pesoActual>capacidad){return;}
    max_valor = max(max_valor,valorActual);
    mochilaBinario(pesos,valores,capacidad,n,i+1,pesoActual+ pesos[i],valorActual + valores[i],max_valor);
    mochilaBinario(pesos,valores,capacidad,n,i+1,pesoActual,valorActual,max_valor);
    
}

int main() {
    vector<int> pesos = {1, 3, 4, 5};
    vector<int> valores = {1, 4, 5, 7};
    int capacidad = 7;
    int n = pesos.size();
    int max_valor = 0;

    mochilaBinario(pesos, valores, capacidad, n, 0, 0, 0, max_valor);

    cout << "Valor máximo: " << max_valor << endl;

    return 0;
}
