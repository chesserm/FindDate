# Find a Date Program

### Simple C++ terminal program to find a desired date x days before, or after, the specified date.

### When the program starts, it gives you a short example of how to use the calculator. Make sure you enter month's numerically (i.e. 8 for August), or else you'll crash the program. 

### IMPORTANT NOTE: While the program is accurate for up to about 99999 days before/after the entered date, anything larger than this enters undefined territory. This is caused by the use of ints to store the data. If the ints that hold the data are replaced with GNU bignum objects, then the accuracy can be further extended. I may even try to create my own bignum equivalent class in the future. For now, it seems unnecessary to implement.
