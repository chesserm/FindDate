/*
 * Created by Matthew Chesser
 * https://github.com/chesserm
 * Last edited 8/20/2018
*/

#ifndef FIND_DATE_H
#define FIND_DATE_H


// REQUIRES: currentMonth and currentYear are valid ints
// MODIFIES: Nothing
// EFFECTS:  returns an integer value corresponding to the
//           number of days in the previous month
int daysOfPreviousMonth(int currentMonth, int currentYear) {}


// REQUIRES: currentMonth and currentYear are valid ints
// MODIFIES: Nothing
// EFFECTS:  returns an integer value corresponding to the
//           number of days in the previous month
int daysOfNextMonth(int currentMonth, int currentYear) {}


// REQUIRES: currentMonth and currentYear are valid ints
// MODIFIES: Nothing.
// EFFECTS:  returns an integer value corresponding to the
//           number of days in the current month
int daysOfCurrentMonth(int currentMonth, int currentYear) {}


// REQUIRES: currentMonth is an int between 1-12
// MODIFIES: Nothing
// EFFECTS:  Retruns a string of the month's name
string findMonthString(int currentMonth) {}




#endif