#include <iostream>
#include <string>
#include <iomanip>

using std ::setw;
using namespace std;

//Just here to explain to the player how to play.
void gameInstructions()
{
    cout<< "****************************************\n";
    cout<< "--------MISSING NUMBER GAME-------------\n";
    cout<< "A fun brain game (not really)\n";
    cout<< "Please enter a whole number to guess the missing number.\n";
    cout<< "Program developed by Nicolas Lotruglio\n";
    cout<< "*****************************************\n";
}

void displayBoard(int Board0[][3], int Board1[][3], int Board2[][3])
{
  srand(time(NULL));
  int randBoardNum = (rand() % 3) + 1; // random number between 0-2, in with while loop
  
  if (randBoardNum == 1){
    displayGrid(Board0);
  } else if (randBoardNum == 2){
    displayGrid(Board1);
  } else {
    displayGrid(Board2);
  }
}

void displayGrid(int arr[][3])
{
  for (int x = 0; x < 4; x++)
  {
    for (int y = 0; y < 3; y++){
      cout << arr[x][y] << " " << endl;
    }
  }
}
                         
int main()
{
   // board "0"
    int Board0[4][3] = { 38, 11, 83, 
                         15, 6, 33,
                         10, 2, 20,
                         86, NULL, 95};
    
    // board "1"
    int Board1[4][3] = { 28, 10, 55, 
                         89, 17, 98,
                         22, 4, 31,
                         69, NULL, 78};
    
    // board "2" 
    int Board2[4][3] = { 90, 9, 45, 
                         66, 12, 48,
                         34, 7, 70,
                         44, NULL, 26};
                         
  gameInstructions(); // intro text

  displayBoard(Board0,Board1,Board2); // displays board based on rand number
  
   return 0;
}
