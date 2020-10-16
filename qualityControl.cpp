#include <iostream>
#include <cmath>
using namespace std;

float computeMean(float*, int);
float computeStdev(float*, int);
float computeMedian(float*, int);
void top2scores(float*, int, float&, float&);
void sortArray(float*, int);

int main(void) {
  //  Array for storing the test results
  cout << "How many test objects do you have? " ;
  int n;
  cin >> n;
  float* res = new float[n] ;   // dynamically allocated memory for the res[] array

  //  Read in the test results
  cout << "Enter the " << n << " test results: ";
  for (int i=0; i<n; i++)
    cin >> res[i] ;

  //  Print out
  cout << "Summary test scores:" << endl ;
  cout << "  mean   = " << computeMean(res, n) << endl ;
  cout << "  stdev  = " << computeStdev(res, n) << endl ;
  cout << "  median = " << computeMedian(res, n) << endl ;
  float bestScore, secondBestScore;
  top2scores(res, n, bestScore, secondBestScore) ;
  cout << "  top-2  = " << bestScore << " " << secondBestScore << endl ;

  return 0;
}


float computeMean(float* x, int n) {
  float avg=0;
  for (int i=0; i<n; i++)
    avg += x[i];
  return (avg/n) ;
}

float computeStdev(float* x, int n) {
  float avg = computeMean(x,n) ;
  float sum=0;
  for (int i=0; i<n; i++)
    sum += pow( x[i] - avg , 2) ;
  return sqrt(sum/(n-1)) ;
}

float computeMedian(float *x, int n) {
  //  sort the array to allow for calculation of the median
  sortArray(x,n) ;

  //  now extract the median
  float med;
  if ( n%2 == 0 ) {   // n is even -- see below for alternative ways to check whether n is even
    int i1 = n/2-1 ;
    int i2 = n/2 ;
    med = 0.5*( x[i1] + x[i2] ) ;
  }
  else {   // n is odd
    int i = (n-1)/2 ;
    med = x[i] ;
  }

  return med ;

  //  There are many ways to check if a number n is even:
  //  - the % operator is the remainder in an integer division, so n%2==0 if even and n%2==1 if odd
  //  - this is basically the same as n-2*(n/2) -- note that the parentheses are crucial here
  //  - you could do 2*(n/2)==n (true if even, false if odd)
  //  - moving beyond one-line if-statements, you could use a while-loop in this way:
  //      int n_tmp=n;
  //      while (n_tmp>1) n_tmp-=2;   // keep subtracting 2 until n_tmp is either 0 or 1
  //      if (n_tmp==0) then n is even...
  //  - and I'm sure you can think of other ways...
}

void top2scores(float* x, int n, float& top, float& second) {
  //  make sure the array is sorted -- we don't know whether it is or isn't from inside this function!
  sortArray(x,n) ;

  //  since it's now sorted in increasing order...
  top = x[n-1] ;
  second = x[n-2] ;
}



//  This function is taken from the extra problems in lecture on 11/15 -- re-using code is smart!
void sortArray(float* f, int N) {
  int done=0;
  while (!done) {
    done=1;
    //  loop through the array, swapping neighbors as appropriate
    for (int i=1; i<N; i++) {
      if ( f[i] < f[i-1] ) {
        float tmp = f[i] ;
        f[i] = f[i-1] ;
        f[i-1] = tmp ;
        done=0;
      }
    }
  }
}

