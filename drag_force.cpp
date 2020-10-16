#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//  Function prototype
float Cd(float);

//  Main program
int main(void) {

  //  Properties of air, and pi
  float rho = 1.2 ;
  float mu = 1.8e-5 ;
  float pi = 4.0*atan(1.0) ;

  //  Read diameter and velocity
  cout << "Enter diameter (in mm) and velocity (in m/s): " ;
  float D, V ;
  cin >> D >> V ;
  //  Immediately transform into SI units before we forget!
  D *= 0.001 ;

  //  Keep doing as long as the diameter is positive
  while ( D > 0.0 ) {

    //  Compute Reynolds number
    float Re = rho * V * D / mu ;

    //  Compute drag force
    float area = pi * pow(D/2.0,2) ;
    float Fd = Cd(Re) * 0.5 * rho * area * pow(V,2) ;

    //  Output to screen
    cout << "  drag force = " << Fd << " N" << endl ;

    //  Read the next diameter and velocity
    cout << "Enter diameter (in mm) and velocity (in m/s): " ; 
    cin >> D >> V ; 
    //  Immediately transform into SI units before we forget!
    D *= 0.001 ; 
  }

  return 0;
}

//  Actual function implementation
float Cd(float Re) {
  float term1 = 24.0/Re * pow( 1.0 + 0.27*Re , 0.43 ) ;
  float term2 = 0.47*( 1.0 - exp(-0.04*pow(Re,0.38)) ) ;
  return term1 + term2 ;
}


//  To check the code, using 10 200 as input should produce "drag force = 0.891225 N"
