#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//  Function prototype
float Cd(float);

//  Main program
int main(void) {
  cout << "Re         Cd" << endl ;
  cout << scientific << setprecision(3) ;

  for (float Re=0.1; Re < 2e5 ; Re*=10.0) {
    cout << Re << "  " << Cd(Re) << endl ;
  }

  return 0;
}

//  Actual function implementation
float Cd(float Re) {
  float term1 = 24.0/Re * pow( 1.0 + 0.27*Re , 0.43 ) ;
  float term2 = 0.47*( 1.0 - exp(-0.04*pow(Re,0.38)) ) ;
  return term1 + term2 ;
}

