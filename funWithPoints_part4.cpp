#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Point {
  float x, y;
  float m;
};

ostream& operator<<(ostream&, Point);
Point operator+(Point, Point);

int main(void) {

  //  Open the data file
  ifstream fin("points.txt");
  if ( ! fin.is_open() ) {
    cout << "Error: could not open the input file..." << endl ;
    return 1 ;
  }

  //  Read the number of data points and allocate the array
  int N ;
  fin >> N ;
  Point* p = new Point[N] ;

  //  Read all the parts into the array
  cout << "Reading " << N << " points from file" << endl ;
  for (int k=0; k<N; k++) {
    fin >> p[k].x >> p[k].y >> p[k].m ;
  }

  //  Print points
  cout << "Points from file:" << endl ;
  for (int k=0; k<N; k++)
    cout << "  point " << k+1 << ": " << p[k] << endl ;

  //  Add all points together
  Point pcg={0,0,0};
  for (int k=0; k<N; k++)
    pcg = pcg + p[k] ;

  cout << "Total CG: " << pcg << endl ;

  return 0;
}

ostream& operator<<(ostream& o, Point p) {
  o << "mass=" << p.m << " at (x,y)=(" << p.x << "," << p.y << ")" ;
  return o;
}

Point operator+(Point p1, Point p2) {
  Point p_new;
  p_new.m = p1.m + p2.m ;
  p_new.x = ( p1.m*p1.x + p2.m*p2.x ) / p_new.m ;
  p_new.y = ( p1.m*p1.y + p2.m*p2.y ) / p_new.m ;
  return p_new;
}


/*  Should produce, with points.txt, this output:
Reading 12 points from file
Points from file:
  point 1: mass=3.9109 at (x,y)=(0.6787,3.8755)
  point 2: mass=5.607 at (x,y)=(0.7577,3.8307)
  point 3: mass=3.7993 at (x,y)=(0.7431,4.0315)
  point 4: mass=5.9799 at (x,y)=(0.3922,3.4426)
  point 5: mass=6.4787 at (x,y)=(0.6555,3.8142)
  point 6: mass=8.4238 at (x,y)=(0.1712,3.4128)
  point 7: mass=4.6118 at (x,y)=(0.706,3.8968)
  point 8: mass=0.7233 at (x,y)=(0.0318,3.3568)
  point 9: mass=3.3208 at (x,y)=(0.2769,3.4351)
  point 10: mass=7.7092 at (x,y)=(0.0462,3.3339)
  point 11: mass=2.8557 at (x,y)=(0.0971,3.3612)
  point 12: mass=6.9219 at (x,y)=(0.8235,4.0215)
Total CG: mass=60.3423 at (x,y)=(0.468865,3.66147)
*/

