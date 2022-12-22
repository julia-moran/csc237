/*!
\file TermDblLinkList.cpp
\brief TermList subclass implementation for storing terms in a doubly linked list

This file serves as the implementation of TermDblLinkList.h.
It contains the implementations of the constructor, destructor,
and the respective pure virtual functions inherited from
TermList, those being readIntoList, printIteratively,
printRecursively, and operator(), as well as the helper function
printRecursivelyHelper
*/
/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  October 15, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #3
    Filename:       TermDblLinkList.cpp
    Purpose:        This file serves as the implementation of TermDblLinkList.h.
                    It contains the implementations of the constructor, destructor,
                    and the respective pure virtual functions inherited from
                    TermList, those being readIntoList, printIteratively,
                    printRecursively, and operator(), as well as the helper
                    function printRecursivelyHelper.
*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Term.h"
#include "TermList.h"
#include "TermDblLinkList.h"

using namespace std;

/*
    Function Name:  TermDblLinkList
    Description:    Serves as the constructor for a TermDblLinkList
    Parameters:     N/A
    Return Value:   N/A
*/
TermDblLinkList::TermDblLinkList() {}//end constructor

/*
    Function Name:  ~TermDblLinkList
    Description:    Serves as the destructor for a TermDblLinkList
    Parameters:     N/A
    Return Value:   N/A
*/
TermDblLinkList::~TermDblLinkList() {}//end destructor

/*
    Function Name:  readIntoList
    Description:    Reads the content from the file to the doubly linked list
    Parameters:     string - filename: the name of the file to read from
    Return Value:   N/A
*/
void TermDblLinkList::readIntoList(string filename)
{
    //Variables
    ifstream source(filename.c_str()); //input file stream
    double coefficient;
    int exponent;
    bool equivalent; //set if a term in the list with the same exponent as the term coming in was found

    //Create the iterator to traverse the doubly linked list
    DblLinkItr<Term> itr(ThePoly);

    //Read the first term into the list
    source >> coefficient >> exponent;
    Term firstTerm(coefficient, exponent);
    ThePoly.insert(firstTerm);

    //Read the remaining terms into the list
    while (source >> coefficient >> exponent)
    {
        //Check if the list is empty
        if(itr.isEmpty() == false)
        {
            //Check if there exists another term in the list with the same
            //exponent as the term being read from the file
            for(itr.start(); itr.isLastNode() == false; ++itr)
            {
                if((*itr).getExponent() == exponent && equivalent == false)
                {
                    //Create a new term that combines the coefficient of the
                    //term being read from the file and the term with the
                    //same exponent
                    Term CombinedTerm(coefficient + (*itr).getCoefficient(), exponent);

                    //Remove the term with the same exponent as the read term
                    Term TermToRemove((*itr).getCoefficient(), exponent);
                    ThePoly.remove(TermToRemove);

                    //Replace the removed term with the combined term
                    ThePoly.insert(CombinedTerm);

                    equivalent = true;

                    break;
                }//end if
            }//end for loop

            //Check if the last node in the list has the same exponent as the
            //term read from the file
            if((*itr).getExponent() == exponent && equivalent == false)
            {
                //Combine terms if their exponents are equivalent
                Term CombinedTerm(coefficient + (*itr).getCoefficient(), exponent);

                //Remove the term in the list with the same exponent as the read term
                Term TermToRemove((*itr).getCoefficient(), exponent);
                ThePoly.remove(TermToRemove);

                //Insert the combined term
                ThePoly.insert(CombinedTerm);

                equivalent = true;
            }//end if
            //Insert the new term at the end of the list if no terms with the
            //same exponent are currently in the list
            else if(equivalent == false)
            {
                Term termToInsert(coefficient, exponent);
                ThePoly.insert(termToInsert);
            }//end else if

            equivalent = false;
        }//end if
    }//end while

    //Close the file
    source.close();
    //Rewind the file
    source.seekg(ios::beg);
    //Clear the file
    source.clear();
}//end function readIntoList

/*
    Function Name:  printRecursivelyHelper
    Description:    Performs the recursion for the printRecursively function
                    for the doubly linked list option
    Parameters:     DblLinkItr<Term> - itr: iterator for the doubly linked list
*/
void TermDblLinkList::printRecursivelyHelper(DblLinkItr<Term> &itr)
{
    //Base Case: Print the first term in the list without a plus sign
    if(itr.isFirstNode())
    {
        cout << *itr << endl << endl;
    }//end if

    //Recursive Step: Print the remaining terms in the list backwards with a
    //plus sign
    else
    {
        cout << *itr << " + ";
        --itr;
        printRecursivelyHelper(itr);
        cout << "test" << endl;
    }//end else
}//end function printRecursivelyHelper

/*
    Function Name:  printRecursively
    Description:    Prints the header of the recursive option and calls the
                    recursive helper function to print the terms in the doubly
                    linked list recursively
    Parameters:     N/A
    Return Value:   N/A
*/

void TermDblLinkList::printRecursively()
{
    //Create the iterator to traverse the polynomial using the DblLinkItr class
    DblLinkItr<Term> itr(ThePoly);

    //Print the header
    cout << "---------------------------------" << endl;
    cout << "|Doubly  Linked  List  Recursive|" << endl;
    cout << "---------------------------------" << endl;

    //Set the iterator to be at the last node in the doubly linked list
    for(itr.start(); itr.isLastNode() == false; ++itr);

    //Call the recursive helper function
    printRecursivelyHelper(itr);
}//end function printRecursively

/*
    Function Name:  printIteratively
    Description:    Prints the contents of the doubly linked list using an
                    iterator from DblLink.h
    Parameters:     N/A
    Return Value:   N/A
*/
void TermDblLinkList::printIteratively()
{
    //Create an iterator to traverse the list using the DblLinkItr class
    DblLinkItr<Term> itr(ThePoly);

    //Print header
    cout << "---------------------------------" << endl;
    cout << "|Doubly  Linked  List  Iterative|" << endl;
    cout <<"---------------------------------" << endl;

    //Print the remaining items in the list
    if(itr.isEmpty() == false)
    {
        //Start the iterator at the last node in the list
        for(itr.start(); itr.isLastNode() == false; ++itr);

        //Print the terms in the list backwards so they are in descending order
        for(; itr.isFirstNode() == false; --itr)
        {
            cout << *itr << " + ";
        }//end for loop

        //Print the first term in the list
        cout << *itr << endl << endl;
    }//end if
}//end function printIteratively

/*
    Function Name:  operator()
    Description:    Evaluates the polynomial by adding up each result when the x
                    value is plugged into a term
    Parameters:     double - xToEvaluate: value for x that will be plugged into
                                          each term
    Return Value:   double - result: sum of all the evaluated terms
*/
double TermDblLinkList::operator()(double xToEvaluate) const
{
    double result = 0.0; //return value

    //Create an iterator to traverse the list
    DblLinkItr<Term> itr(ThePoly);

    if(itr.isEmpty() == false)
    {
        for(itr.start(); itr.isLastNode() == false; ++itr)
        {
            //Create a term object for the item the iterator is pointing at
            Term currentTerm((*itr).getCoefficient(), (*itr).getExponent());
            //Evaluate the term and add it to the result
            result  = result + currentTerm(xToEvaluate);
        }//end for loop

        //Add the last term in the list
        Term lastTerm((*itr).getCoefficient(), (*itr).getExponent());
        result = result + lastTerm(xToEvaluate);
    }//end if

    //Return the result
    return (result);
}//end function operator()
