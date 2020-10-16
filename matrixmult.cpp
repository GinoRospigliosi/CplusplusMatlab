#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

  // Ask user to define A:
  float A[3][3];
  for (int i=0; i<3; i++) {
    cout << "Enter A col " << i+1 << ": ";
    cin >> A[0][i] >> A[1][i] >> A[2][i];
  }
  cout << endl;

  // Ask user to define B:
  float B[3][3];
  for (int i=0; i<3; i++) {
    cout << "Enter B col " << i+1 << ": ";
    cin >> B[0][i] >> B[1][i] >> B[2][i];
  }
  cout << endl;

  // Find C = A*B:
  float C[3][3]; 
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + A[i][2]*B[2][j];
    }
  }

  // Display all arrays:
  cout << "A = " << endl;
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  cout << "B = " << endl;
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cout << B[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  cout << "A*B = " << endl;
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cout << C[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

// Test code with:
// A col 1 = 0 1 1
// A col 2 = 0 1 0
// A col 3 = 1 0 0
// B col 1 = 1 1 1
// B col 2 = 1 0 1
// C col 3 = 0 1 1
//
// results:
//
// A =
// 0 0 1
// 1 1 0
// 1 0 0
// 
// B =
// 1 1 0
// 1 0 1
// 1 1 1
// 
// A*B =
// 1 1 1
// 2 1 1
// 1 1 0


