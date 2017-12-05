#include <iostream>

using namespace std;

int main()
{
    //my variables. My nouns.
    int CHOICE=0;                     // Choice variable for user
    const int GOLD_MEMBER     = 1;    // membership for gold member
    const int SILVER_MEMBER   = 2;    // membership for silver member
    const int BRONZE_MEMBER   = 3;    // membership for bronze member
    const int QUIT_PROGRAM    = 4;    // Option to quit program
    const float GOLD_APR      = 0.01; // The precent of interest that will be added to the yearly fee. In thise case 1%
    const float SILVER_APR    = 0.02; // The precent of interest that will be added to the yearly fee. In this case 2%
    const float BRONZE_APR    = 0.04; // The precent of interest that will be added to the yearly fee. In this case 4%
    float YEARLY_FEE          = 1200; // Yearly fee starts at 1200
    
    const float CALCULATED_GOLD = YEARLY_FEE * GOLD_APR; // Yearly fee based on gold
    const float CALCULATED_SILVER = YEARLY_FEE * SILVER_APR; // Yearly fee based on silver
    const float CALCULATED_BRONZE = YEARLY_FEE * BRONZE_APR; // Yearly fee based on bronze
    
    //The display menu that will be shown to the user
    cout<<"Welcome to Rhonda's Strikeforce Gym.\n";
    cout<<"x----------------------------------x\n";
    
    cout<<"Membership fee calculator\n";
    cout<<"1. Gold\n";
    cout<<"2. Silver\n";
    cout<<"3. Bronze\n";
    cout<<"4. Quit\n";
    
    cout<<"Please enter your membership level.\n";
    cin >> CHOICE;
    
    
    while (CHOICE < 1 || CHOICE > 4) // between 1-4, error checks CHOICE
    {
        cout << "Invalid reponse please pick between 1-4" << endl;
        cin.clear(); // clears input
        cin.ignore(10000,'\n'); // ignores the current input line then says start on new line
        cin >> CHOICE;
    }   
    
    //A loop that will calculate your yearly fee and display cost for 10 years of membership. The yearly fee + the precent of interest for each membership.

		if (CHOICE == 4){
   		return 0;
    }

	  cout<<"Your membership fee for the next 10 years will be\n";

    for (int year = 0; year < 10; year++) // runs 10 times
    {
        if (CHOICE == 1) // gold member
        {
           YEARLY_FEE += CALCULATED_GOLD;
           cout << YEARLY_FEE << endl;
        }
        else if (CHOICE == 2) // silver member
        {
          YEARLY_FEE += CALCULATED_SILVER;
          cout << YEARLY_FEE << endl;
        }
        else if (CHOICE ==3) // bronze member
        {
          YEARLY_FEE += CALCULATED_BRONZE;
          cout << YEARLY_FEE << endl;
        }
    }

  return 0;
  }