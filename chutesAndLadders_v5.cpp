//
//  Code for tracking movements in Chutes and Ladders game
//  Version 5, automatic die rolls
//

#include <iostream>
using namespace std;

int main(void) {

  cout << "Chutes and Ladders -- version 5" << endl << "-----" << endl;

  int position = 0 ;
  int move = 0 ;

  srand (time(NULL));   // create a new rand() seed

  while ( position < 50 ) {    // keep playing until we reach at least 20

    move += 1 ;    //  Count the moves

    //  Roll the dice
    int dieRoll = rand() % 6 + 1;   // random int between 1-6
    dieRoll += rand() % 6 + 1;   // add another random int between 1-6

    cout << "Dice roll: " << dieRoll << endl;

    position = position + dieRoll;    //  Make the move

    //  Check the chutes and ladders
    if ( position == 7 ) {
      cout << "  You hit a ladder!" << endl ;
      position = 12;
    }
    else if ( position == 16 ) {
      cout << "  You hit a ladder!" << endl ;
      position = 25;
    }
    else if ( position == 22 ) {
      cout << "  You hit a ladder!" << endl ;
      position = 39;
    }
    else if ( position == 34 ) {
      cout << "  You hit a ladder!" << endl ;
      position = 45;
    }
    else if ( position == 13 ) {
      cout << "  You hit a chute!" << endl ;
      position = 9;
    }
    else if ( position == 27 ) {
      cout << "  You hit a chute!" << endl ;
      position = 12;
    }
    else if ( position == 38 ) {
      cout << "  You hit a chute!" << endl ;
      position = 30;
    }
    else if ( position == 48 ) {
      cout << "  You hit a chute!" << endl ;
      position = 33;
    }


    //  Print out the move and the current position
    cout << "  After move " << move << ", your position is now " << position << endl ;
  }

  //  Print out the final statement
  cout << "You finished in " << move << " moves" << endl ;

  return 0;
}


