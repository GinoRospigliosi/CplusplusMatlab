#include <iostream>
#include <cmath>
using namespace std;

struct Point {
  float x, y;
  float m;
};

ostream& operator<<(ostream&, Point);
Point operator+(Point, Point);

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
  Point p12 = p1 + p2 ;
  Point p34 = p3 + p4 ;
  cout << "Point 12 (1+2): " << p12 << endl ;
  cout << "Point 34 (3+4): " << p34 << endl ;

  //  Add again
  Point p1234 = p12 + p34 ;
  cout << "Point 1234 (12+34): " << p1234 << endl ;

  //  Try a different addition
  Point p1234_alt = p1 + p2 + p3 + p4 ;
  cout << "Point 1234 (1+2+3+4): " << p1234_alt << endl ;

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

//  Should produce the additional output:
//  Point 1234 (12+34): mass=10 at (x,y)=(0.6,0.7)
//  Point 1234 (1+2+3+4): mass=10 at (x,y)=(0.6,0.7)

