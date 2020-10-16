//Gino Rospigliosi
//Homework 4
//Section 0201
#include<iostream>
#include<cmath>
using namespace std;
#define PI 3.14159
#define N 2000
int main() {
float freq;
float A;
float t[N];
float y[N];
float Fk[N];
float phi;
float Yreal[N];
float Yimag[N];
float Yk[N];

//Take in frequency and amplitude from keyboard
cout << "Enter the signal frequency (Hz) and amplitude: ";
cin >> freq >> A;
//Create time and y domain
for (int i=0; i<N; i++) 
{
  t[i] = 0.001*i;
  y[i] = A*sin(2*PI*freq*t[i]);
}
//Dft algorithm
for (int k=0; k<(N/2); k++) 
{
//Inner loop
for (int r=0; r<N; r++){
//Phi value for index r and k
  phi=2*PI*(k)*(r)/N;
//Summation value for index r and k
  Yreal[k]+= y[r]*cos(phi);
  Yimag[k]-= y[r]*sin(phi);
}
//Magnitude of imaginary and real using cmath
Yk[k]=(2/(float)N)*sqrt(pow(Yreal[k],2.0)+pow(Yimag[k],2.0));
///F array for each index k
Fk[k]=(k)/t[N-1];
}

float max=0;
float maxfreq;
//compare Yk to max anf find freq at max
for (int j=0; j<(N/2); j++){
if (Yk[j]>max){
max= Yk[j];
maxfreq= Fk[j];
}
}
//Output max ampltide and max frequency
cout << "Y(f) reports a peak amplitude of " << max << " at a frequency of " <<maxfreq <<" Hz";

return 0;
}