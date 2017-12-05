//Nicolas Lotruglio
//COP2000
//HW 2
#include <iostream>

#include <iomanip>

using namespace std;

int main()
{
    //defining my variables
    int choice = 0; //placeholder until the user makes their choice later on
    bool checker = true; //used to make sure input is correct
    const int Square_Room = 1;
    const int Rectangle_Room = 2;
    const int Round_Room = 3;
    const int Quit_Program = 4;
    
    float room_length, room_width, room_radius, area_of_room ;
    float PIE = 3.14;
    
    //This is the menu display that the user will see and choose from
    	cout << "Haverly's Room Calculator" << endl;
    	cout << "*************************" << endl;
    	cout << endl;
    	cout << "1. Square Room." << endl;
    	cout << "2. Rectangle Room" << endl;
    	cout << "3. Round Room" <<endl;
    	cout << "4. Quit" << endl;
    
   	 	cout << "Please enter the number of the room type you wish to measure." << endl;
   	 	cin>>choice;
    
    while (checker) {
      if (cin.fail()) { // checks to make sure input is valid, can't put text inside an int
        cin.clear(); // clears the input stream
        cin.ignore(10000, '\n'); // just for technicality, ignores the current input line for any other inputs. go to next line
        cout << "Please input a number between 1-4" << endl; // prompt the user again because original input failed
        cin>>choice; // get the input again
      } else {
        switch(choice) {
          //First case. If the user puts in '1' for a square room
        	case 1:
        	checker = false;
    	    cout<<"Please enter width of square room.";
        	cin>>room_width;

        	area_of_room = room_width*room_width; //the calculation
        	cout<<"The area of the room is "<< area_of_room << endl; //the final display of the area of the room
        	break;
    
        	//second case. If the user puts in '2' for a rectangle room
        	case 2:
        	checker = false;
        	cout<<"Please enter the width of the rectangle room.";
        	cin>>room_width;
        	cout<<"Please enter the length of the rectangle room.";
        	cin>>room_length;
        	area_of_room = room_width*room_length;
   	    	cout<<"The area of the room is "<< area_of_room << endl;
   	    	break;
    
    	    //third case for if the user puts in a '3' for a round room
    	    case 3:
    	    checker = false;
    	    cout<<"Please enter the radius of the room.";
    	    cin>>room_radius;
    	    area_of_room = PIE*(room_radius*room_radius);
    	    cout<<"The area of the room is "<< area_of_room << endl;
    	    break;
    
    	    //fourth case for if the user puts in a '4' and quits the program
    	    case 4:
        	checker = false;
        	cout<<"Thank you for using Haverly’s Room Calculator! " << endl;
        	break;
    
   	      //my catch all for if the user inputs anything else that isn't a choice
   		    default:
    	    cout << "Invalid choice" << endl;
    	    cout << "please try again: " << endl;
    	    cin >> choice;
    	    continue;
   	  }
    }
  };

  return 0;
}
