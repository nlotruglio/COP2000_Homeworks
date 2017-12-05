#include <iostream>
#include <string>
using namespace std;

void getRaceTimes(string& racerName, float& racerTime) {
  
  cout << "Please enter the racer's first name: ";
  cin >> racerName;
  cout << endl;
  
  cout << "Please enter the racer's time: ";
  cin >> racerTime;
  cout << endl;
  
  if (racerTime <= 0){
    cin.clear();
    cin.ignore(10000,'\n');
    
    bool checker = true;
    
    while(checker){
      cout << "Please enter a value greater than 0" << endl;
      cin >> racerTime;
      
      if (racerTime > 0){
        checker= false; // user has input correct answer
      }
    }
  }
}

void announceTie(string firstName, string secondName, float time){
  // extra function just so you dont have to type out every case in findWinners output
  cout << "We have a TIE " + firstName + " and " + secondName + " win!!" << endl;
  cout << "***** Your winning time is " + to_string(time) + " *****" << endl;
}

void announceWinner(string name, float time){
  cout << "Congratulations " + name +"!!!  You are the winner!!" << endl;
  cout << "***** Your winning time is " + to_string(time) + " *****" << endl;
  
}

void findWinner(string racerOneName, string racerTwoName, string racerThreeName, int racerOneTime, int racerTwoTime, int racerThreeTime){
  
  // this can and should be replaced with a switch statement, written this way due to time constraints and I understand ifs better than switches
  if (racerOneTime == racerTwoTime && racerOneTime == racerThreeTime){
    // three way tie
    cout << "We have a 3 way TIE!! No Winner for this Race...\n\n";
  } else if (racerTwoTime == racerThreeTime){
    // see if racer two ties with racer three
    announceTie(racerTwoName, racerThreeName, racerTwoTime);
  } else if (racerOneTime == racerTwoTime || racerOneTime == racerThreeTime){
    // see if racer one ties with any others
    if (racerOneTime == racerTwoTime){
      announceTie(racerOneName, racerTwoName, racerOneTime);
    } else {
      announceTie(racerOneName, racerThreeName, racerOneTime);
    }
  } else if (racerOneTime > racerTwoTime && racerOneTime > racerThreeTime){
    // racer one wins
    announceWinner(racerOneName, racerOneTime);
  } else if (racerTwoTime > racerOneTime && racerTwoTime > racerThreeTime){
    // racer two wins
    announceWinner(racerTwoName, racerTwoTime);
  } else if (racerThreeTime > racerOneTime && racerThreeTime > racerTwoTime){
    // racer three wins
    announceWinner(racerThreeName, racerThreeTime);
  }
}

void welcome() {
  cout << "*****************************************************************\n"
          "Welcome to Race Results Program\n"
          "You are asked to enter the Three Racers Names\n"
          "and their Associated Race Time.\n"
          "Please enter a real number for Race Time (the Race Time Must be > 0).\n"
          "Program Developed by: Nicolas Lotruglio\n"
          "*****************************************************************\n\n";
}

float raceAverage(float raceOne, float raceTwo, float raceThree){
  return (raceOne+raceTwo+raceThree) / 3;
}

int main () {
  string racerOneName;
  string racerTwoName;
  string racerThreeName;
  float racerOneTime;
  float racerTwoTime;
  float racerThreeTime;
  float averageTime;
  
  
  welcome(); // intro text
  
  getRaceTimes(racerOneName, racerOneTime); // undefined, passing by reference modifies main variables
  getRaceTimes(racerTwoName, racerTwoTime);
  getRaceTimes(racerThreeName, racerThreeTime);
  
  findWinner(racerOneName, racerTwoName, racerThreeName, racerOneTime, racerTwoTime, racerThreeTime);
  
  averageTime = raceAverage(racerOneTime, racerTwoTime, racerThreeTime);
  
  cout << "\n\n";
  
  cout << "Overall Race Time Average: " + to_string(averageTime) << endl;
  
  
  return 0;
}