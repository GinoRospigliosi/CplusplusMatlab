//Gino Rospigliosi
//HW3
//Section 0201
#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
float g = 9.81 ;
//80 kB worth for each array of 20000 elements
float x[20000], v[20000], t[20000];
//Read the value of the angle theta from the keyboard
float theta ;
cout << "Enter the value of theta in degrees: " ;
cin >> theta ;
float pi = acos(-1) ;
//Theta to radians
theta = theta* pi / 180 ;    
//Initial Conditions
t[0]=0; x[0]=0; v[0]=0;
float dt = 0.01 ;
int i=0;
while ( v[i] >= 0 ) {
float mu = 0.15 + tanh( x[i] - 2 )/10 ;
float accel = g*sin(theta) - mu*g*cos(theta) ;
t[i+1] = t[i] + dt ;
x[i+1] = x[i] + dt * v[i] ;
v[i+1] = v[i] + dt * accel ;
i++ ;
}
cout << "Final position:" << endl ;
cout << "  t = " << t[i] << endl ;
cout << "  x = " << x[i] << endl ;
cout << "  v = " << v[i] << endl ;
//Find peak velocity 
int step_at_vmax = -1 ;
float vmax = -1 ;
for (int j=0; j <i ; j++) {   
//Step loaction in the array 
if ( v[j] > vmax ) {
step_at_vmax = j ;
vmax = v[j] ;
}
}
cout << "Peak velocity = " << vmax << " at time " << t[step_at_vmax] << endl ;
//Print out data within .001 of the peak velocity
cout << "Data when velocity is within 0.001 m/s of the max:" << endl ;
for (int j=0; j < i; j++) {
if ( v[j] > vmax - 0.001 ) {
cout << "  t=" << t[j] ;
cout << "  x=" << x[j] ;
cout << "  v=" << v[j] ;
cout << endl ;
}
}
return 0;
}

