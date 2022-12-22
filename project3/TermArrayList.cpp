/*!
\file TermArrayList.cpp
\brief TermList subclass implementation for storing terms in an array

This file serves as the implementation for the functions for
TermArrayList. It implements the constructor and respective
virtual functions inherited from TermList, the pure virtual
functions being readIntoList, printIteratively,
printRecursively, and operator() as well as the nonpure
virutal function printPtr and the helper function
printRecurivelyHelper.
*/
/*
    Author:         Julia Moran
    Major:          Computer Science
    Retrieved Date: October 13, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #3
    Filename:       TermArrayList.cpp
    Purpose:        This file serves as the implementation for the functions for
                    TermArrayList. It implements the constructor and respective
                    virtual functions inherited from TermList, the pure virtual
                    functions being readIntoList, printIteratively,
                    printRecursively, and operator() as well as the nonpure
                    virutal function printPtr and the helper function
                    printRevurivelyHelper.
*/
// Source Cited:
/*
///////////////////////////////////////////////////////////////////////////////
    Author:         Dr. Spiegel
    Filename:       TermArrayList.h
    Date:           October 2, 2022
    Date retrieved: October 13, 2022
    Purpose:        Container of TermArray objects.
                    Implementations of member functions including inherited pure virtual fns.
    Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/TermArrayList.cpp
*///////////////////////////////////////////////////////////////////////////////

/* Citation Source: This file was based off of the file retrieved from
    Dr. Spiegel's website at
    https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/TermArrayList.cpp
    All functions used the file authored by Dr. Spiegel as a guide.
*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermArrayList.h"
#include <algorithm>

using namespace std;

/*
    Function Name:  TermArrayList
    Description:    Serves as the constructor for TermArrayList
    Parameters:     N/A
    Return Value:   N/A
*/
TermArrayList::TermArrayList()
{
    //Set the number of terms in the array to zero
    numTerms = 0;
}//end constructor

/*
    Function Name:  readIntoList
    Description:    Reads the data from the file into an array of objects in
                    which terms with the same exponent are combined and the
                    terms are sorted
    Parameters:     string - filename: name of the file to read from
    Return Value:   N/A
*/
void TermArrayList::readIntoList(string filename)
{
    //Variables
    ifstream source(filename.c_str()); //input file stream
    double coefficient;
    int exponent;
    bool equivalent = false; //set if a term in the array with the same exponent as the term coming in was found

    //Read the first term from the file
    source >> coefficient >> exponent;
    Term firstTerm(coefficient,exponent);
    ThePoly[0] = firstTerm;
    numTerms++;

    //Read the remaining terms in the file
    while(source >> coefficient >> exponent)
    {
        for(int arrayIndex = 0; arrayIndex < numTerms; arrayIndex++)
        {
            //Check if there is a term in the array with the same exponent as
            //the term being inserted. If there is, replace the term in the
            //array with the two terms combined
            if(exponent == ThePoly[arrayIndex].getExponent() && equivalent == false)
            {
                //Make a new term made of the combined coefficients of the two
                //terms and the shared exponent
                Term combinedTerm(ThePoly[arrayIndex].getCoefficient() + coefficient, exponent);
                ThePoly[arrayIndex] = combinedTerm;

                equivalent = true;

                break;
            }//end if
        }//end for

        //Insert a new term made of the coefficient and exponent read in from
        //the file to the end of the array if there were no terms with the same
        //exponent found
        if(equivalent == false && numTerms < MAXTERMS)
        {
            //Make a new term from the coefficient and exponent read from the file
            Term newTerm(coefficient, exponent);
            ThePoly[numTerms++] = newTerm;
        }//end if

        equivalent = false;
    }//end while

    //Sort the array
    sort(ThePoly, ThePoly + numTerms);

    //Rewind the file
    source.seekg(0, ios::beg);
    //Close the file
    source.close();
    //Clear the file
    source.clear();
}//end function readIntoList

/*
    Function Name:  printIteratively
    Description:    Prints the contents from the array of objects through
                    iteration
    Parameters:     N/A
    Return Value:   N/A
*/
void TermArrayList::printIteratively()
{
    //Print the header
    cout << "---------------------------------" << endl;
    cout << "|Object  Array  Iterative       |" << endl;
    cout << "---------------------------------" << endl;

    //Print each term in the array of objects in descending order
    for(int arrayIndex = numTerms - 1; arrayIndex >= 0; arrayIndex--)
    {
        cout <<  ThePoly[arrayIndex] << (arrayIndex > 0 ? " + ": " ");
    }//end for

    cout << endl << endl;
}//end function printIteratively

/*
    Function Name:  printRecursivelyHelper
    Description:    Performs the recursion for the printRecursively function
                    for the array using an index
    Parameters:     int - index: current index of the term being printed
    Return Value:   N/A
*/
void TermArrayList::printRecursivelyHelper(int index)
{
    //Base Case: Print the first term in the array without a plus sign
    if(index == 0)
    {
        cout << ThePoly[index] << endl << endl;
    }//end if

    //Recursive Step: Print the remaining terms in the array with a plus sign
    else
    {
        cout << ThePoly[index] << " + ";
        index--;
        printRecursivelyHelper(index);
    }//end else
}//end function printRecursivelyHelper

/*
    Function Name:  printRecursively
    Description:    Prints the header and calls the recursive helper function
                    to print the terms in the array recursively
    Parameters:     int - index: index of the current object in the array
    Return Value:   N/A
*/
void TermArrayList::printRecursively()
{
    //Print the header
    cout << "---------------------------------" << endl;
    cout << "|Object  Array  Recursive       |" << endl;
    cout << "---------------------------------" << endl;

    //Call the recurive helper to perform the recursion
    printRecursivelyHelper(numTerms - 1);
}//end function printRecursively

/*
    Function Name:  printPtr
    Description:    Prints the data in the array of objects using a pointer
    Parameters:     N/A
    Return Value:   N/A
*/
void TermArrayList::printPtr()
{
    //Print the header
    cout << "---------------------------------" << endl;
    cout << "|Object  Array  Pointer         |" << endl;
    cout << "---------------------------------" << endl;

    //Set the pointer at the end of the array
    Term *now = begin(ThePoly) + numTerms - 1;

    //Print each term in the array of objects in descending order
    for(int numTermsPrinted = numTerms - 1; numTermsPrinted >= 0; numTermsPrinted--)
    {
        cout << *(now--)  << (numTermsPrinted > 0 ? " + " : "");
    }//end for

    cout << endl << endl;
}//end function printPtr

/*
    Function Name:  operator()
    Description:    Evaluates the polynomial using a given x value
    Parameters:     double - xToEvaluate: x value to evaluate the polynomial with
    Return Value:   double - result: the result after plugging the x value into
                                     the polynomial
*/
double TermArrayList::operator()(double xToEvaluate) const
{
    double result = 0.0; //return value

    //Sum up the result after plugging in the x value to each term in the
    //polynomial
    for (int arrayIndex = 0; arrayIndex < numTerms; arrayIndex++)
    {
        result += ThePoly[arrayIndex](xToEvaluate);
    }//end for

    return(result);
}//end function operator()
