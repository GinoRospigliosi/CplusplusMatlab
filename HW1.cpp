//Gino Rospigliosi
//HW1
#include <iostream>
using namespace std;
//Assumes entered value is an int
int main(void) {
int a;
int b;

cout << "Enter value for a:";
cin  >> a;

cout << "Enter value for b:";
cin >> b;

cout << a << "+" << b << " = \t\t" << a+b <<endl;
cout << a << "-" << b << " = \t\t" << a-b <<endl;
cout << a << "*" << b << " = \t\t" << a*b <<endl;
//Typecasting for division
float c= (float) a/b;
float d= (float) a/(b-a);
cout << a << "/" << b << " = \t\t" << c <<endl;
cout << a << "/(" << b << "-" << a << ") = \t" << d << endl;
  return 0;
  
}