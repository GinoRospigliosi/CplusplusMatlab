#include <iostream>
#include <cmath>
using namespace std;

struct Point {
  float x, y;
  float m;
};

ostream& operator<<(ostream&, Point);
Point addPoints(Point, Point);

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

  //  Add points in pairs
  Point p12 = addPoints(p1,p2) ;
  Point p34 = addPoints(p3,p4) ;
  cout << "Point 12 (1+2): " << p12 << endl ;
  cout << "Point 34 (3+4): " << p34 << endl ;

  return 0;
}

ostream& operator<<(ostream& o, Point p) {
  o << "mass=" << p.m << " at (x,y)=(" << p.x << "," << p.y << ")" ;
  return o;
}

Point addPoints(Point p1, Point p2) {
  Point p_new;
  p_new.m = p1.m + p2.m ;
  p_new.x = ( p1.m*p1.x + p2.m*p2.x ) / p_new.m ;
  p_new.y = ( p1.m*p1.y + p2.m*p2.y ) / p_new.m ;
  return p_new;
}

//  Should produce the additional output:
//  Point 12 (1+2): mass=3 at (x,y)=(0.666667,0)
//  Point 34 (3+4): mass=7 at (x,y)=(0.571429,1)

