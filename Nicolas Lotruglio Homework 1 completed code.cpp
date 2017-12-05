//Nicolas Lotruglio
//COP2000 HW 1
#include <iostream>
using namespace std;

//This program will calculate the quantity of ingredients needed for the amount of pie crusts you wish to make.
int main () 
{
  //ingredients for 6 pie crusts
    int crusts = 0; // 0 is just a placeholder, will be replaced with input (just learned that as I was trying to write this)
	const float number_of_pie_crusts = 6;
	float   cups_of_flour = 15 / number_of_pie_crusts;  // dividing each of the variables by 6 gets you the amount needed for 1 crust
	float	tablespoons_of_sugar = 8 / number_of_pie_crusts;
	float	tablespoons_of_salt = 3 / number_of_pie_crusts;
	float	cups_of_butter = 5.25 / number_of_pie_crusts;
	float	large_eggs = 6 / number_of_pie_crusts;
		
	cout << "How many pie crusts do you wish to make?";
	cin >> crusts;
  
  // this block calculates the amount needed per ingredient
  cups_of_flour = cups_of_flour * crusts; // multiplies single serving amount by the amount requested  
  tablespoons_of_sugar = tablespoons_of_sugar * crusts;
  tablespoons_of_salt = tablespoons_of_salt * crusts;
  cups_of_butter = cups_of_butter * crusts;
  large_eggs = large_eggs * crusts;

	 //displaying the final results of the amount of ingredients you'll need
   cout << "You need: " << cups_of_flour << " cups of flour."<<endl;  
   cout << "You need: " << tablespoons_of_sugar << " tablespoons of sugar."<<endl;
   cout << "You need: " << tablespoons_of_salt << " tablespoons of salt."<<endl;
   cout << "You need: " << cups_of_butter << " cups of butter."<<endl;
   cout << "You need: " << large_eggs << " large eggs."<<endl;
  
	 
	return 0;
}
