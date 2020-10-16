#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct Part {
  int id ;
  float mass ;
  float coord[3] ;
};

float findCG(Part*, int, float*);
int findFarthestItem(Part*, int, float*);

int main(void) {

  //  Open the vehicle.prt file
  ifstream fin("vehicle.prt");
  if ( ! fin.is_open() ) {
    cout << "Error: could not open the input file..." << endl ;
    return 1 ;
  }

  //  Read the number of parts and allocate the array
  int N ;
  fin >> N ;
  Part* parts = new Part[N] ;

  //  Read all the parts into the array
  for (int k=0; k<N; k++) {
    fin >> parts[k].id ;
    fin >> parts[k].mass ;
    for (int i=0; i<3; i++)
      fin >> parts[k].coord[i] ;
  }

  //  Do the computations, with the following exact code in the main program
  float xcg[3];
  float totalMass = findCG(parts, N, xcg);
  int part_id = findFarthestItem(parts, N, xcg);

  //  Output to a file
  ofstream fout("results.dat");
  if ( ! fout.is_open() ) {
    cout << "Error: could not open the output file..." << endl ;
    return 2 ;
  }

  fout << "Total mass: " << totalMass << endl ;
  fout << "CG location: " << xcg[0] << " " << xcg[1] << " " << xcg[2] << endl ;
  fout << "Most distant part: " << part_id << endl ;

  return 0;
}


float findCG(Part* array, int n, float* xcg) {
  float total = 0.0 ;
  for (int i=0; i<3; i++)  xcg[i] = 0.0 ;
  for (int k=0; k<n; k++) {
    total += array[k].mass ;
    for (int i=0; i<3; i++)
      xcg[i] += array[k].mass * array[k].coord[i] ;    // this now holds the total sum
  }
  //  Now we scale the total sum to get the center-of-gravity
  for (int i=0; i<3; i++)
    xcg[i] /= total ;

  //  Note how everything with the xcg[3] array must be done for all three elements, since it's a vector

  return total;
}

int findFarthestItem(Part* array, int n, float* xcg) {
  //  Initialize to something that forces the right behavior when we enter the loop
  int farthest_id = -1 ;
  float max_distance = -1 ;
  //  Now loop over all parts
  for (int k=0; k<n; k++) {
    //  Option 1 to compute the distance...
    float dx = array[k].coord[0] - xcg[0] ;
    float dy = array[k].coord[1] - xcg[1] ;
    float dz = array[k].coord[2] - xcg[2] ;
    float distance = sqrt( pow(dx,2) + pow(dy,2) + pow(dz,2) ) ;
    //  And here's another option to compute the distance, if you like loops...
    // float distance = 0 ;
    // for (int i=0; i<3; i++)
    //   distance += pow( array[k].coord[i] - xcg[i] ,2) ;   // summing up the square of the distance
    // distance = sqrt(distance) ;

    //  However we computed the distance, we now check...
    if ( distance > max_distance ) {
      max_distance = distance ;
      farthest_id = array[k].id ;
    }
  }

  return farthest_id ;
}

