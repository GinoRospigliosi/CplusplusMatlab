#include <iostream>
#include <cmath>

using namespace std;

float myfcn(float) ;

int main(void) {
  //  Declare x array of sufficiently large length
  float x[1000];

  //  Read number of points from the keyboard
  cout << "Enter how many segments you want to use: " ;
  int N ;
  cin >> N ;   // note that N is the number of segments, and thus we have N+1 points!

  //  Check that we can fit these in our array
  if ( N+1 > 1000 ) {
    cout << "Error: N = " << N << " is too large!" << endl ;
    exit(-1) ;
  }

  //  Populate the x array with evenly spaced points
  float dx = 2.0 / N ;    // note that you need the "2.0" here to avoid integer division
  for (int i=0; i<=N; i++) {
    x[i] = dx*i - 1 ;
  }

  //  Compute the integral
  float totalArea = 0.0 ;
  for (int k=0; k<N; k++) {
    float x_width = x[k+1] - x[k] ;                       // width of the segment in x
    float y_avg = 0.5*( myfcn(x[k]) + myfcn(x[k+1]) ) ;   // average value of y over the segment
    float area = x_width * y_avg ;                        // area of this particular segment
    totalArea += area ;                                   // sum up all segment areas
  }

  //  Print out result
  cout << "With " << N << " segments, the integral is approximately " << totalArea << endl ;

  //  Optional: print out the error
  //cout << "Error = " << abs(totalArea-2.0*sin(1.0)) << endl ;

  return 0;
}


float myfcn(float x) {
  return  cos(x) ;         // exact integral 1.68294...
  //return  pow(x,4)+2*x ;   // exact integral 0.4
}


//  To check the code, test one or both of:
//   cos(x) with   5 segments => 1.66044
//   cos(x) with 256 segments => 1.68293

