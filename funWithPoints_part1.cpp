#include <iostream>
#include <cmath>
using namespace std;

struct Point {
  float x, y;
  float m;
};

ostream& operator<<(ostream&, Point);

int main(void) {

  //  Define 4 points at the corners of a square
  Point p1={0,0,1};
  Point p2={1,0,2};
  Point p3={0,1,3};
  Point p4={1,1,4};
  cout << "Point 1: " << p1 << endl ;
  cout << "Point 2: " << p2 << endl ;
  cout << "Point 3: " << p3 << endl ;
  cout << "Point 4: " << p4 << endl ;

  return 0;
}

ostream& operator<<(ostream& o, Point p) {
  o << "mass=" << p.m << " at (x,y)=(" << p.x << "," << p.y << ")" ;
  return o;
}

