// Gino Rospigliosi
//HW2
//Section 0201
#include <iostream>
#include <cstdlib>
using namespace std;
int main(void) { 
  //Set array of 20 integers
  int x[20];
  int temp;
//Set random time 
  srand(time(NULL));
//Generate random array of n=20 integers
  cout << "Unsorted array" << endl;
  for (int i=0; i<20; i++){
    x[i] = rand() % 100 + 1;
    cout << x[i] << " ";  
    }
cout<<endl;
//Boolean Statment
bool done;
//flag
done = false; 
  while(!done){
    done= true;
    //only occurs to n-1=19 since it is pair of elements
    for (int i=0; i<19; i++)
      if (x[i]>x[i+1]){
        //Swap variables in increasing order
        temp=x[i];
        x[i]=x[i+1];
        x[i+1]=temp;
        done= false;
      }
}
//Print out sorted array
cout << "Sorted array" << endl;
  for (int i=0; i<20; i++)
cout << x[i] << " ";
    return 0;
}