/*!
\file TermList.h
\brief Defines virtual functions for subclasses TermArrayList, TermSTLObjList, and TermDblLinkList

This class defines the pure virtual functions readIntoList, printIteratively,
printRevursively, and the () operator for the use of TermArrayList, TermSTLObjList,
and TermDblLinkList. It also contains the nonpure virtual function printPtr for the
TermArrayList subclass.
*/
// Source Cited:
/*//////////////////////////////////////////////////////////////////////////////
    Author:         Dr. Spiegel
    Filename:       TermList.h
    Date:           October 16, 2016
    Date retrieved: October 13, 2022
    Purpose:        Abstract base class for containers of Terms
                    Known subclasses:
                        TermArray
                    Coming soon: ParallelArrayTermList, TermVectorList, ...
    Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/TermList.h
*///////////////////////////////////////////////////////////////////////////////
/*
    Retrieved by:   Julia Moran
    Major:          Computer Science
    Retrieved Date: October 13, 2022
    Due Date:       November 11, 2022
    Professor Name: Dr. Spiegel
    Assignment:     #3
    Filename:       TermList.h
    Purpose:        Defines the virtual functions for the use of TermArrayList,
                    TermDblLinkList, and STLObjList
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
   https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/TermList.h
   All content except the printRecursively() function was authored by Dr. Spiegel
*/
#ifndef TERMLIST_H
#define TERMLIST_H

#include <fstream>
#include <string>

using namespace std;

class TermList {
/*!
    \class TermList
    \brief TermList class that defines virtual functions for subclasses

    \n This class declares the pure virtual functions readIntoList,
       printIteratively, printRevursively, and the () operator for the use of
       TermArrayList, TermSTLObjList, and TermDblLinkList. It also contains the
       nonpure virtual function printPtr for the TermArrayList subclass.
*/
public:
    /*!
        \fn readIntoList
        \brief Reads the data to a data container
        \n The readIntoList function reads in the data from the file to
           a data container of objects of the type Term.
        \param filename Name of the file to read the data in from (string).
        \return N/A
    */
  virtual void readIntoList(string filename)=0;

    /*!
        \fn printIteratively
        \brief Iteratively prints the data
        \n The printIteratively function prints the data in the data structure iteratively.
        \param N/A
        \return N/A
    */
  virtual void printIteratively()=0;

    /*!
        \fn printRecursively
        \brief Prints the data recursively
        \n The printRecursively function prints the header of the recursive print
           option and calls the recursive helper function to print the terms in the
           data structure recursively.
        \param N/A
        \return N/A
    */
  virtual void printRecursively() = 0;

    /*!
        \fn printPtr
        \brief Prints the with a pointer
        \n The printPtr function prints the terms in the array using a pointer.
        \param N/A
        \return N/A
    */
  virtual void printPtr() {}   // not pure virtual; why? -> not overloaded in other subclasses, only used in TermArrayList

    //Function Name: operator()
    /*!
        \brief Evaluates the polynomial
        \n The () operator evaluates the polynomial by adding up each result when
        the x value is plugged into each term.
        \param x The value for x to plug into each term (double).
        \return answer The end result when x is plugged into the polynomial (double).
    */
  virtual double operator()(double x) const=0;

};

#endif
