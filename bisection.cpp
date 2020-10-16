// Gino Rospigliosi
//Section 0201
//HW2
//Did not use cmath function
#include <iostream>
using namespace std;
int main(void) {
float C, xl, xu, xguess,f, fxl, fxu;
cout << "Enter the value of C: ";
//Take value C for fucntion
cin >> C;

xl = -10.0;
xu = 10.0;
//Function Estimation
fxl = xl*xl*xl+C*xl-10.0;
fxu = xu*xu*xu+C*xu-10.0;
//Range for 10E-4
while ((xu-xl) > 0.0001) {
xguess = (xl+xu)/2.0;
f = xguess*xguess*xguess+C*xguess-10.0;
//Flip if not in range
if (f > 0.0) {
xu = xguess; }

if (f< 0.0) {
xl = xguess; }

}
//Return root of function
cout << "Found root x =" << (xl+xu)/2.0 << endl;
return 0;
}

