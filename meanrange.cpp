#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

  // Read 10 numbers, place into array a[]
  cout << "Enter a list of 10 numbers: ";
  float a[10];
  for (int k=0;k<10;k++) cin >> a[k];

  // Read the range
  cout << "Enter a range (min and max): ";
  float amin, amax;
  cin >> amin >> amax;

  // Compute the mean by adding up the numbers in the list
  float sum=0;
  for (int k=0;k<10;k++) sum+=a[k];
  float mean = sum/10;
  cout << "The mean is: " << mean << endl;

  // Show the list elements within the specified range
  cout << "Elements in specified range: ";
  for (int k=0;k<10;k++) {
    if ( (a[k]>=amin) && (a[k]<=amax) ) {
      cout << a[k] << " ";
    }
  }
  cout << endl;

  return 0;
}

// Check with:
// a= 8 -6 4 -2 0 -1 3 5 -7 -9
// amin = -2.1, max = 5
//  Should give:
// mean = -0.5
// Elements in range: 4 -2 0 -1 3 5
 
