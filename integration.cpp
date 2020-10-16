#include <iostream>
#include <cmath>

using namespace std;

float integrate(float*, float*, int);

int main(void) {
  //  Declare arrays
  float x[21], y[21];
  int len=21;

  //  Fill the arrays with meaningful values
  for (int i=0; i<len; i++) {
    x[i] = 0.1*i - 1 ;
    y[i] = pow(x[i],2) + 2*x[i] + 2 ;
//    y[i] = pow(x[i],4) + 3*x[i] + 3 ;
  }

  //  Compute the integral
  float result = integrate(x,y,len) ;
  cout << "The integral is " << result << endl ;

  return 0;
}


float integrate(float* X, float* Y, int len) {
  float totalArea = 0.0 ;
  for (int k=1; k<len; k++) {   // NOTE: looping from 1 to len-1, i.e., starting at the SECOND point!
    float X_width = X[k] - X[k-1] ;         // width of the segment in X
    float Y_avg = 0.5*( Y[k] + Y[k-1] ) ;   // average value of Y over the segment
    float area = X_width * Y_avg ;          // area of this particular segment
    totalArea += area ;                     // sum up all segment areas
  }
  return totalArea ;
}



//  To check the code, change the y[] array to instead hold y=x^4 + 3*x + 3, which should produce 6.40666

