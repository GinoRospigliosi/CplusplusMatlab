#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct DataPoint {
  float x, y;
};

struct Line {
  float k, m;
};

Line findRegressionLine(DataPoint*, int);
float computeSSR(DataPoint*, int, Line);

int main(void) {

  //  Open the data file
  ifstream fin("data.txt");
  if ( ! fin.is_open() ) {
    cout << "Error: could not open the input file..." << endl ;
    return 1 ;
  }

  //  Read the number of data points and allocate the array
  int N ;
  fin >> N ;
  DataPoint* data = new DataPoint[N] ;

  //  Read all the parts into the array
  cout << "Reading " << N << " data points from file" << endl ;
  for (int k=0; k<N; k++) {
    fin >> data[k].x >> data[k].y ;
  }

  //  Compute the coefficients of the regression line
  Line regressionline = findRegressionLine(data, N) ;
  cout << "Regression line: y = " << regressionline.k << "*x + " << regressionline.m << endl ;

  //  Compute the SSR
  float SSR = computeSSR(data, N, regressionline) ;
  cout << "Regression SSR = " << SSR << endl ;

  return 0;
}

Line findRegressionLine(DataPoint* mydata, int n) {
  float xavg=0, yavg=0, sumxy=0, sumxx=0;
  for (int k=0; k<n; k++) {
    xavg += mydata[k].x ;
    yavg += mydata[k].y ;
    sumxy += mydata[k].x * mydata[k].y ;
    sumxx += mydata[k].x * mydata[k].x ;
  }
  xavg /= n ;
  yavg /= n ;
  sumxy -= n * xavg * yavg ;
  sumxx -= n * xavg * xavg ;
  //  Compute the coefficients for the line, and store in myline
  Line myline;
  myline.k = sumxy / sumxx ;
  myline.m = yavg - myline.k * xavg ;
  return myline;
}

float computeSSR(DataPoint* mydata, int n, Line myline) {
  //  CODE HERE
}


