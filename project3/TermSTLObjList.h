/*!
\file TermSTLObjList.h
\brief TermList subclass declaration for storing terms in a vector

This subclass of the TermList class changes the abstract class to utilize a vector to
store, evaluate, and display terms in a polynomial. It contains the prototypes for
the constructor, the respective pure virtual functions inherited from TermList,
those being readIntoList, printIteratively, printRecursively, and operator(). It also
contains helper function printRecursivelyHelper and has a vector to contain Term
objects as a data member.
*/
/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  October 16, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #3
    Filename:       TermSTLObjList.h
    Purpose:        This file serves as the header file for the TermSTLObjList.
                    It contains the prototypes for the constructor, the
                    respective pure virtual functions inherited from TermList,
                    the helper function printRecursively, and has a vector to
                    contain Term objects as a data member.
*/


#ifndef TERMSTLOBJLIST_H
#define TERMSTLOBJLIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "Term.h"
#include <vector>

using namespace std;

class TermSTLObjList : public TermList {
/*!
    \class TermSTLObjList
    \brief TermList subclass that implements the polynomial using a vector

    \n This subclass of the TermList class changes the abstract class to
       utilize a vector to store, evaluate, and display terms in a polynomial. It
       contains the prototypes for the constructor, the respective pure virtual
       functions inherited from TermList, those being readIntoList,
       printIteratively, printRecursively, and operator(). It also contains
       helper function printRecursivelyHelper and has a vector to contain Term
       objects as a data member.
*/
    public:
        /*!
            \fn TermSTLObjList
            \brief Constructor for TermSTLObjList
            \n This function serves as the constructor for the TermSTLObjList
               object, a vector of terms in a polynomial.
            \param N/A
            \return N/A
        */
        TermSTLObjList();

        /*!
            \fn readIntoList
            \brief Reads the data to a vector
            \n The readIntoList function reads the data from the file to a
               vector of objects of the type Term.
            \param filename Name of the file to read the data in from (string).
            \return N/A
        */
        void readIntoList(string filename);

        /*!
            \fn printIteratively
            \brief Iteratively prints the data
            \n The printIteratively function prints the contents of the vector
               iteratively.
            \param N/A
            \return N/A
        */
        void printIteratively();

        /*!
            \fn printRecursivelyHelper
            \brief Helps to recursively print the data
            \n The printRecursivelyHelper function performs the recursion for
               the printRecursively function for the vector using an iterator
               object.
            \param itr Iterator to traverse the vector of terms with
                       (vector<Term>::iterator).
            \return N/A
        */
        void printRecursivelyHelper(vector<Term>::iterator &itr);

        /*!
            \fn printRecursively
            \brief Prints the data recursively
            \n The printRecursively function prints the header of the recursive
               option and calls the recursive helper function to print the
               terms in the vector recursively.
            \param N/A
            \return N/A
        */
        void printRecursively();

        // operator()
        /*!
            \brief Evaluates the polynomial
            \n The () operator evaluates the polynomial by adding up each
               result when the x value is plugged into each term.
            \param xToEvaluate The value for x to plug into each term (double).
            \return answer The result after the x value is plugged into each
                           term and added up (double).
        */
        virtual double operator()(double xToEvaluate) const;

    private:
        //Data Members

        //A vector made of Term objects
        vector<Term> ThePoly;
};//end class TermSTLObjList

#endif
