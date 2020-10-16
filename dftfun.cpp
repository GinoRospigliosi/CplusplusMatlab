//Gino Rospigliosi
//Homework 4
//Section 0201
#include <iostream>
#include <cmath>
using namespace std;
//Function protoypes return nothing
void signal(float*, float*, float, float);
void dft(float*, float*, float*, float*);
void peak(float*, float*, float&, float&);
//Main
int main(void) {
#define PI 3.14159
#define N 2000
float freq, A;
float t[N], y[N], f[N], Y[N], Yreal[N], Yimag[N], Ykreal[N], Ykimag[N];
float phi, max, maxfreq;
cout << "Enter the signal frequency (Hz) and amplitude: ";
cin >> freq >>A;
//Function call
signal(y,t,freq,A);
dft(y,t,f,Y);
peak(f,Y,max,maxfreq);
//Output max amplitude and max frequency
cout << "Y(f) reports a peak amplitude of " << max << " at a frequency of " <<maxfreq <<" Hz";
return 0;
}

void signal(float* y, float* t ,float freq, float A){
  //Create time and y domain
for (int i=0; i<N; i++) 
{
  t[i] = 0.001*i;
  y[i] = A*sin(2*PI*freq*t[i]);
}
}


void dft(float* y, float* t ,float* f, float* Y){
 float Yreal[N], Yimag[N], Ykreal[N],Ykimag[N], phi;
  for (int k=0; k<(N/2); k++){
//F array for each index k
  f[k]=(k-1)/t[N-1];
//Inner loop
  for (int r=0; r<N; r++){
//Phi value for index r and k
  phi=2*PI*(r-1)*(k-1)/N;
//Summation value for index r and k
  Yreal[r]= y[r]*cos(phi);
  Yimag[r]= y[r]*sin(phi);
  Ykreal[k] += Yreal[r];
  Ykimag[k] -= Yimag[r];
}
//Magnitude of imaginary and real using cmath
  Y[k]=(2/(float)N)*sqrt(pow(Ykreal[k],2.0)+pow(Ykimag[k],2.0));
}
}

//Pass max amplitude and max freq by reference
void peak(float* f, float* Y, float& max, float& maxfreq){
//compare Y to max an find freq at max
  for (int j=0; j<N; j++){
  if (Y[j]>max){
  max= Y[j];
  maxfreq= f[j];
}
}
}
