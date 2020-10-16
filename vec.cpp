#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

  float v[3], w[3];

  cout << "Enter v: ";
  cin >> v[0] >> v[1] >> v[2];

  cout << "Enter w: ";
  cin >> w[0] >> w[1] >> w[2];
  cout << endl ;

  // dot(v,w)
  float dot_v_w=0;
  for (int i=0;i<3;i++) dot_v_w += w[i]*v[i];
  cout << " dot(v,w) = " << dot_v_w << endl;

  // y = cross(v,w)
  float y[3];
  y[0] = v[1]*w[2]-v[2]*w[1];
  y[1] = v[2]*w[0]-v[0]*w[2];
  y[2] = v[0]*w[1]-v[1]*w[0];
  cout << " cross(v,w) = ";
  for (int i=0;i<3;i++) {
    cout << y[i] << " ";
  }
  cout << endl;

  // dot(y,v)
  float dot_y_v=0;
  for (int i=0;i<3;i++) {
    dot_y_v += v[i]*y[i];
  }
  cout << " dot(y,v) = " << dot_y_v << endl;

  // cross(y,v)
  float z[3];
  z[0] = y[1]*v[2]-y[2]*v[1];
  z[1] = y[2]*v[0]-y[0]*v[2];
  z[2] = y[0]*v[1]-y[1]*v[0];
  cout << " cross(y,v) = ";
  for (int i=0;i<3;i++) {
    cout << z[i] << " ";
  }
  cout << endl;

  return 0;
}

// Check with:

// Enter v: 1 1 1
// Enter w: -1 2 -3
//  dot(w,v) = -2
//  v x w = -5  2  3  
//  dot(v,y) = 0
//  y x v = -1  8  -7 

