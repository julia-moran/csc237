/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  October 16, 2022
    Due Date:       October 25, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #2
    Filename:       TermSTLObjList.cpp
    Purpose:        This program contains the implementations of the functions
                    for the TermSTLObjList. It implements the constructor and
                    respective pure virtual functions inherited from TermList.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "TermSTLObjList.h"

using namespace std;

/*
    Function Name:  TermSTLObjList
    Description:    Serves as the constructor for the TermSTLObjList
    Parameters:     N/A
    Return Value:   N/A
*/
TermSTLObjList::TermSTLObjList() {}

/*
    Function Name:  TermSTLObject
    Description:    Reads in the data from the file to a vector
    Parameters:     string - filename: name of the file to read the data from
    Return Value:   N/A
*/
void TermSTLObjList::readIntoList(string filename)
{
    //Variables
    ifstream source(filename.c_str()); //input file stream
    double coefficient;
    int exponent;
    bool equivalent = false; //set if a term in the vector with the same exponent was found

    //Set the iterator at the beginning of the vector
    vector<Term>::iterator itr = ThePoly.begin();

    //Read in the first term to the vector
    source >> coefficient >> exponent;
    Term firstTerm(coefficient, exponent);
    ThePoly.insert(ThePoly.begin(), firstTerm);

    //Read the remaining terms to the vector
    while(source >> coefficient >> exponent)
    {
        //Read the coefficient and exponent from the file into a Term object
        Term readTerm(coefficient, exponent);
        equivalent = false;

        for(itr = ThePoly.begin(); itr != ThePoly.end(); itr++)
        {
            equivalent = false;

            //Check if there exists a term in the vector that has the same
            //exponent as the term read in from the file
            if(readTerm == *itr)
            {
                //Create a new term with the coefficients from the two terms
                //combined and their shared exponent
                Term tempTerm(((*itr).getCoefficient() + readTerm.getCoefficient()), readTerm.getExponent());

                //Replace the current term in the vector with the new combined
                //term
                *itr = tempTerm;
                equivalent = true;
                break;
            }//end if
        }//end for

        //Insert the read in term at the end of the vector if there are no terms
        //in the vector with the same exponent
        if(equivalent == false)
        {
            ThePoly.insert(itr++, readTerm);
        }//end if
    }//end while

    //Sort the vector
    sort(ThePoly.begin(), ThePoly.end());

    //Close the file
    source.close();
    //Rewind the file
    source.seekg(ios::beg);
    //Clear the file
    source.clear();
}//end function readIntoList

/*
    Function Name:  printIteratively
    Description:    Prints the terms in the vector using an iterator
    Parameters:     N/A
    Return Value:   N/A
*/
void TermSTLObjList::printIteratively()
{
    //Print header
    cout << "---------------------------------" << endl;
    cout << "|STL    Object  Iterative       |" << endl;
    cout << "---------------------------------" << endl;

    //Set the iterator at the end of the vector
    vector<Term>::iterator itr = ThePoly.end() - 1;

    //Print out the last term in the vector
    cout << *itr;

    //Print out the remaining terms in the vector in descending order
    for(itr = ThePoly.end() - 2; itr >= ThePoly.begin(); itr--)
    {
        cout << " + " << *itr;
    }//end for loop

    cout << endl << endl;
}//end function printIteratively

/*
    Function Name:  operator()
    Description:    Evaluates the polynomial using the x value
    Parameters:     double - xToEvaluate: the x value to plug into the equation
    Return Value:   double - result: the result after the x value is plugged
                                     into the each polynomial and summed up
*/
double TermSTLObjList::operator()(double xToEvaluate) const
{
    //Variables
    double result = 0.0; //return value
    int termPosition = 0; //position in the vector the term is at

    //Plug in the x value into each of the terms
    for(termPosition; termPosition < ThePoly.size(); termPosition++)
    {
        //Add each evaluated term to the result
        result = ThePoly[termPosition](xToEvaluate) + result;
    }//end for loop

    //Add the last term to the result
    result = ThePoly[termPosition](xToEvaluate) + result;

    return (result);
}//end function operator()
