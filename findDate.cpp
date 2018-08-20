/*
 * Created by Matthew Chesser
 * https://github.com/chesserm
 * Last edited 8/20/2018
*/

#include "findDate.h"
#include <string>
#include <iostream>
using namespace std;


// REQUIRES: currentMonth and currentYear are valid ints
// MODIFIES: Nothing
// EFFECTS:  returns an integer value corresponding to the
//           number of days in the previous month
int daysOfPreviousMonth(int currentMonth, int currentYear)
{
    switch(currentMonth)
    {
        case 12:
            return 30;
        case 11:
            return 31;
        case 10:
            return 30;
        case 9:
            return 31;
        case 8:
            return 31;
        case 7:
            return 30;
        case 6:
            return 31;
        case 5:
            return 30;
        case 4:
            return 31;
        case 3:
            if (currentYear % 4 == 0)
            {
                return 29;
            }
            return 28;
        case 2:
            return 31;
        case 1:
            return 31;
    }


    return 999999;
}


// REQUIRES: currentMonth and currentYear are valid ints
// MODIFIES: Nothing
// EFFECTS:  returns an integer value corresponding to the
//           number of days in the previous month
int daysOfNextMonth(int currentMonth, int currentYear)
{
    switch(currentMonth)
    {
        case 1:
            if (currentYear % 4 == 0)
            {
                return 29;
            }
            return 28;
        case 2:
            return 31;
        case 3:
            return 30;
        case 4:
            return 31;
        case 5:
            return 30;
        case 6:
            return 31;
        case 7:
            return 31;
        case 8:
            return 30;
        case 9:
            return 31;
        case 10:
            return 30;
        case 11:
            return 31;
        case 12:
            return 31;
    }

    return 9999999;
}


// REQUIRES: currentMonth and currentYear are valid ints
// MODIFIES: Nothing.
// EFFECTS:  returns an integer value corresponding to the
//           number of days in the current month
int daysOfCurrentMonth(int currentMonth, int currentYear)
{
    switch(currentMonth)
    {
        case 1:
            return 31;
        case 2:
            if (currentYear % 4 == 0)
            {
                return 29;
            }
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }

    return 9999999;
}


// REQUIRES: currentMonth is an int between 1-12
// MODIFIES: Nothing
// EFFECTS:  Retruns a string of the month's name
string findMonthString(int currentMonth)
{
    switch(currentMonth)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";

    }

    return "ERROR";
}


