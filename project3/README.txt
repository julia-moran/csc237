Link to Doxygen Web Page:
https://csit.kutztown.edu/~jmora678/csc237/project3/

Assignment Instructions:

For this project, you will update Project 2 by placing a recursive pure virtual function in TermList that
will be implemented in its subclasses. Then, you will measure and analyze actual execution times of
implementations of the TermList containers.

The new recursive function should be named printRecursively(). You may write any any helper functions needed to
implement the recursive print. Update the application's menu to give the user the option to print iteratively or
recursively (Item 2) and also via a pointer for those data structures that had this feature in Project 2. The options to
evaluate the polynomial and exit will be updated to accommodate the new print method (i.e. for the object array,
the menu items for evaluate and exit will be updated to be numbered 4 and 5, respectively. For the other data
structures they will be Items 3 and 4. The batch mode routine should also be updated to call the recursive prints.

Update your application to time the print calls and report the time to print the TermList in microseconds. This is
accomplished by finding the difference between the system clock when the print function is called and when it
returns. To do this, you must use the high_resolution_clock, available in the chrono library
