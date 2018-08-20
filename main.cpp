/*
 * Created by Matthew Chesser
 * https://github.com/chesserm
 * Last edited 8/20/2018
*/

#include <iostream>
#include <string>
#include "findDate.h"
using namespace std;


// REQUIRES: Nothing
// MODIFIES: Nothing
// EFFECTS:  Prints out the necessary information to greet and instruct
//			 the user. Returns nothing.
void introduction()
{
	cout << "                                      Find a Date" << endl;
	cout << "This program calculates the date which is x days before (or after) the specified date." << endl;
	cout << "=======================================================================================" << endl;
	cout << endl;
	cout << "The program will first ask you to enter a target date in the order of day, month, year." << endl;
	cout << "For example, June 15, 2018 would be entered as:" << endl;
	cout << "Day:    15" << endl;
	cout << "Month:  5" << endl;
	cout << "Year:   2018" << endl;
	cout << endl;
	cout << "Lastly, just enter the amount of days before/after the date you want to calculate." << endl;
	cout << "======================================================================================="
	cout << endl;
}


// REQUIRES: Nothing.
// MODIFIES: Nothing.
// EFFECTS:  Gathers necessary data and calls calculateDate() to
//           find result and print it.
void gatherUserInput()
{
	cout << "Please enter the known date." << endl;
	cout << "Day:   ";

	int intKnownDay;
	cin >> intKnownDay;

	cout << "Month: ";

	int intKnownMonth;
	cin >> intKnownMonth;

	cout << "Year:  ";

	int intKnownYear;
	cin >> intKnownYear;

	cout << endl;  //Formatting

	// Determining if the entered year is a leap year (and if date is valid)
	bool isLeapYear = intKnownYear % 4 == 0;
    // If it's not a leapyear and a day in April is greater than 28
    bool isAprilCase1 = !isLeapYear && intKnownMonth == 2 && intKnownDay > 28;
    // If it is a leapyear and a day in April is greater than 29
    bool isAprilCase2 = isLeapYear && intKnownMonth == 2 && intKnownDay > 29;

    // Input testing
    while (isAprilCase1 || isAprilCase2 || intKnownMonth > 12 || intKnownMonth < 1 || intKnownDay < 1 || intKnownDay > 31 || intKnownYear < 0)
    {
    	cout << "Invalid date entered." << endl;

    	cout << "Please enter the known date." << endl;
		cout << "Day:   ";
		cin >> intKnownDay;

		cout << "Month: ";
		cin >> intKnownMonth;

		cout << "Year:  ";
		cin >> intKnownYear;

		cout << endl;  //Formatting
    }

	cout << "Would you like to find a new date before or after the entered date? ";
	string strBeforeAfter;
	cin >> strBeforeAfter;
	
	// Testing user input
	while (strBeforeAfter.tolower() != "before" || strBeforeAfter.tolower() != "after")
	{
		cout << "Please enter either \"before\" or \"after\"." << endl;
		cout << "Would you like to find a new date before or after the entered date? ";
		cin >> strBeforeAfter;
	}
	
	cout << "How many days " << strBeforeAfter << " the entered date would you like to calculate? ";
	int intTotalDays;
	cin >> intTotalDays;

	// Formatting and ouputting the results
	cout << "";
	cout << "========================================================================================" << endl;
	cout << "The date " << intTotalDays << " days " << strBeforeAfter << " " << findMonthString(intKnownMonth) << ", " << intKnownYear << "is: ";

	// Ouput of the desired date is handled within the calculateDate() function
	calculateDate(intKnownDay, intKnownMonth, intKnownYear, intTotalDays, strBeforeAfter); 

}


// REQURIES: valid ints and string values
// MODIFIES: Nothing.
// EFFECTS:  Calculates and ouputs desired date
void calculateDate(int intKnownDay, int intKnownMonth, int intKnownYear, int intTotalDays, string& strBeforeAfter)
{

	// Increment to target date
    // Note: O(n) runtime
    while (intTotalDays > 0)
    {
        // Wanting to find a date before entered day
        if (strBeforeAfter.tolower() == "before")
        {
            // If the known day is not 1
            if (intKnownDay > 1)
            {
            	intKnownDay -= 1;
            }
            // The known is 1, therefore the month needs to change
            else
            {
                // If the current month is January (1)
                if (intKnownMonth == 1)
                {
                    // Known day is set to last day of prev month
                    intKnownDay = daysOfPreviousMonth(intKnownMonth, intKnownYear);
                    
                    // Known Month is set to December of previous year
                    intKnownMonth = 12;

                    // Known year is set to last year
                    --intKnownYear;
                }
                // Known month is not January
                else
                {

                    intKnownDay = daysOfPreviousMonth(intKnownMonth, intKnownYear);
                    intKnownMonth -= 1;

                }
            }
        }
        // Wanting to find a date after the entered date
        else
        {
            // If the known day is not the max of that month
            if (intKnownDay != daysOfCurrentMonth(intKnownMonth, intKnownYear))
            {
                ++intKnownDay;
            }
            // If the known day is the max of that month
            else
            {
                // If the known month is December, change year and month
                if (intKnownMonth == 12)
                {
                    intKnownDay = 1;
                    intKnownMonth = 1;
                    ++intKnownYear;
                }
                // Known month isn't December, but month needs to change
                else
                {
                    intKnownDay = 1;
                    ++intKnownMonth;
                }
            }
        }

        --intTotalDays;
    }

    // Ouput result
    cout << findMonthString(intKnownMonth) << " " << intKnownDay << ", " << intKnownYear << " (" << intKnownMonth << "/" << intKnownDay << "/" << intKnownYear << ")." << endl;

}


// Main function
int main()
{
	introduction();

	// calculateDate() is called from within gatherUserInput()
	gatherUserInput();

	return 0;
}
