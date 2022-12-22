/*!
\file TermDblLinkList.h
\brief TermList subclass declaration for storing terms in a doubly linked list

This subclass of the TermList class changes the abstract class to utilize a doubly
linked list to store, display, and evaluate terms in a polynomial. It contains the the
prototypes for the constructor, destructor, the respective pure virtual functions
inherited from TermList, those being readIntoList, printIteratively, printRecursivelyHelper,
printRecursively, and operator(). It has a DblLink object as a data member.
*/
/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  October 16, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #3
    Filename:       TermDblLinkList.h
    Purpose:        This file serves as the header file for the TermDblLinkList.
                    It contains the prototypes for the constructor, destructor,
                    the respective pure virtual functions inherited from
                    TermList, those being readIntoList, printIteratively,
                    printRecursivelyHelper, printRecursively and operator(),
                    It has a DblLink object as a data member.
*/

#ifndef TERMDBLLINKLIST_H
#define TERMDBLLINKLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include "TermList.h"
#include "Term.h"
#include "DblLink.h"

using namespace std;

class TermDblLinkList : public TermList
{
/*!
    \class TermDblLinkList
    \brief TermList subclass that implements the polynomial using a doubly linked list

    \n This subclass of the TermList class changes the abstract class to
       utilize a doubly linked list to store, display, and evaluate terms in a
       polynomial. It contains the the prototypes for the constructor,
       destructor, the respective pure virtual functions inherited from
       TermList, those being readIntoList, printIteratively,
       printRecursivelyHelper, printRecursively, and operator().
       It has a DblLink object as a data member.
*/
    public:
        /*!
            \fn TermDblLinkList
            \brief Constructor for TermDblLinkList
            \n This function serves as the constructor for the TermDblLinkList
               object, a doubly linked list.
            \param N/A
            \return N/A
        */
        TermDblLinkList();

        /*!
            \fn ~TermDblLinkList
            \brief Desctructor for TermDblLinkList
            \n This function serves as the destructor for the TermDblLinkList
               object, a doubly linked list.
            \param N/A
            \return N/A
        */
        ~TermDblLinkList();

        /*!
            \fn readIntoList
            \brief Reads the data to a doubly linked list
            \n The readIntoList function reads the data from the file to a
               doubly linked list.
            \param filename Name of the file to read the data in from (string).
            \return N/A
        */
        void readIntoList(string filename);

        /*!
            \fn printIteratively
            \brief Iteratively prints the data
            \n The printIteratively function prints the contents of the doubly
               linked list iteratively.
            \param N/A
            \return N/A
        */
        void printIteratively();

        /*!
            \fn printRecursivelyHelper
            \brief Helps to recursively print the data
            \n The printRecursivelyHelper function performs the recursion for
               the printRecursively function for the doubly linked list using
               an iterator created from the DblLinkItr template class.
            \param itr Iterator used to traverse the doubly linked list
                       (DblLinkItr<Term>).
            \return N/A
        */
        void printRecursivelyHelper(DblLinkItr<Term> &itr);

        /*!
            \fn printRecursively
            \brief Prints the data recursively
            \n The printRecursively function prints the header of the recursive
               option and calls the recursive helper function to print the
               terms in the doubly linked list recursively.
            \param N/A
            \return N/A
        */
        void printRecursively();

        // Function Name:  operator()
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

        //A doubly linked list made of Term objects
        DblLink<Term> ThePoly;

};//end class TermDblLinkList

#endif
