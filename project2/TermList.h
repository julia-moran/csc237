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
    Due Date:       October 25, 2022
    Professor Name: Dr. Spiegel
    Assignment:     #2
    Filename:       TermList.h
    Purpose:        Defines the virtual functions for the use of TermArrayList,
                    TermDblLinkList, and STLObjList
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
   https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/TermList.h
   All content was authored by Dr. Spiegel
*/
#ifndef TERMLIST_H
#define TERMLIST_H

#include <fstream>
#include <string>

using namespace std;

class TermList {
public:
  // Function Name:  readIntoList
  // Description:    Place the line of text into the data structure
  // Parameters:     string - filename: name of the file to read from
  // Return Value:   N/A
  virtual void readIntoList(string filename)=0;

  // Function Name: printIteratively
  // Description:   Print the data iteratively
  // Parameters:    N/A
  // Return Value:  N/A
  virtual void printIteratively()=0;

  // Function Name:  printPtr
  // Description:    Print the data Iteratively with a pointer
  // Parameters:     N/A
  // Return Value:   N/A
  virtual void printPtr() {}   // not pure virtual; why? -> not overloaded in other subclasses, only used in TermArrayList

  // Function Name:  operator()
  // Description:    Evaluate the Polynomial
  // Parameters:     double - x: x value to evaluate the polynomial with
  // Return Value:   N/A
  virtual double operator()(double x) const=0;
    
};
  
#endif
