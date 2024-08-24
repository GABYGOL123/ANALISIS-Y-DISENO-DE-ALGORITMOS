#include <iostream>
using namespace std;

float Addition(float a, float b){ return a+b;}
float Subtraction(float a, float b){return a-b;}
float Multiplication(float a, float b){return a*b;}
float Division(float a, float b){return a/b;}

int main() { 
  typedef float (*lpfnOperation)(float, float);
  lpfnOperation vpf[4] = {&Addition, &Subtraction,&Multiplication, &Division};
  float a, b, c=0; int opt;
  // enter the operands
  cin >> a >> b;
  // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
  cin >> opt;
  // The next line replaces the switch and replaces the whole switch
  c = (*vpf[opt])(a, b);
  cout<<c;

}
