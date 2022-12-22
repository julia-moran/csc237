/*!
\file TermArrayList.h
\brief TermList subclass declaration for storing terms in an array

This subclass of the TermList class changes the abstract class to utilize an array to
store, evaluate, and display terms in a polynomial. It contains the prototypes for the constructor,
and respective virtual functions inherited from TermList. It contains an array of Term
objects and the number of terms in the array as data members.
*/
// Source Cited:
/*
/////////////////////////////////////////////////////////////////////////////////
    Author:         Dr. Spiegel
    Filename:       TermArrayList.h
    Date:           October 2, 2022
    Date retrieved: October 13, 2022
    Purpose:        Container of TermArray objects.
    Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/TermList.h
*///////////////////////////////////////////////////////////////////////////////
/*
    Retrieved by:   Julia Moran
    Major:          Computer Science
    Retrieved Date: October 13, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #3
    Filename:       TermArrayList.h
    Purpose:        This file serves as the header file for a TermArrayList. It
                    contains the prototypes for the constructor, and respective
                    virtual functions inherited from TermList. It contains an
                    array of Term objects and the number of terms in the array as
                    data members
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
    https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/TermList.h
    All content was authored by Dr. Spiegel */

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "Term.h"

using namespace std;

const int MAXTERMS = 10;

class TermArrayList : public TermList {
/*!
    \class TermArrayList
    \brief TermList subclass that implements the polynomial using an array

    \n This subclass of the TermList class changes the abstract class to
    utilize an array to store, evaluate, and display terms in a polynomial. It
    contains the prototypes for the constructor, and respective
    virtual functions inherited from TermList. It contains an
    array of Term objects and the number of terms in the array as
    data members.
*/
    public:
        /*!
           \fn TermArrayList
           \brief Constructor
           \n This function serves as the constructor for TermArrayList
           \param N/A
           \return N/A
        */
        TermArrayList();

        /*!
            \fn readIntoList
            \brief Reads the data to an array
            \n The readIntoList function reads in the data from the file to
            an array of objects of the type Term.
            \param filename Name of the file to read the data in from (string).
            \return N/A
        */
        void readIntoList(string filename);

        /*!
            \fn printIteratively
            \brief Iteratively prints the data
            \n The printIteratively function prints the data in the array iteratively.
            \param N/A
            \return N/A
        */
        void printIteratively();

        /*!
            \fn printRecursivelyHelper
            \brief Helps to recursively print the data
            \n The printRecursivelyHelper function performs the recursion for the
            printRecursively function for the array using an index.
            \param index Current index of the term being printed (int).
            \return N/A
        */
        void printRecursivelyHelper(int index);

        /*!
            \fn printRecursively
            \brief Prints the data recursively
            \n The printRecursively function prints the header of the recursive print
            option and calls the recursive helper function to print the terms in the
            array recursively.
            \param N/A
            \return N/A
        */
        void printRecursively();

        /*!
            \fn printPtr
            \brief Prints the with a pointer
            \n The printPtr function prints the terms in the array using a pointer.
            \param N/A
            \return N/A
        */
        void printPtr();

        //Function Name: operator()
        /*!
            \brief Evaluates the polynomial
            \n The () operator evaluates the polynomial by adding up each result when
            the x value is plugged into each term.
            \param xToEvaluate The value for x to plug into each term (double).
            \return answer The end result when x is plugged into the polynomial (double).
        */
        virtual double operator()(double xToEvaluate) const;

    private:
        //Data Members

        //An array made up of terms with a maximum number of terms
        Term ThePoly[MAXTERMS];

        //The numbers of terms in the array
        int numTerms;

};//end class TermArrayList

#endif
