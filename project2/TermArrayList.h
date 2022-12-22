// Source Cited:
/*//////////////////////////////////////////////////////////////////////////////
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
    Due Date:       October 25, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #2
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
    public:
        // Function Name:  TermArrayList
        // Description:    Serves as the constructor for TermArrayList
        // Parameters:     N/A
        // Return Value:   N/A
        TermArrayList();

        // Function Name:  readIntoList
        // Description:    Reads the data from the file to an array of objects
        // Parameters:     string - filename: name of the file to read the data
        //                                    in from
        //Return Value:    N/A
        void readIntoList(string filename);

        // Function Name:  printIteratively
        // Description:    Prints the data in the array iteratively
        // Parameters:     N/A
        // Return Value:   N/A
        void printIteratively();

        // Function Name:  printPtr
        // Description:    Prints the data in the array with a pointer
        // Parameters:     N/A
        // Return Value:   N/A
        void printPtr();

        // Function Name:  operator()
        // Description:    Evaluates the polynomial by adding up each result when
        //                 the x value is plugged into each term
        // Parameters:     double - xToEvaluate: the value for x to plug into each
        //                                       term
        // Return Value:   N/A
        virtual double operator()(double xToEvaluate) const;

    private:
        //Data Members

        //An array made up of terms with a maximum number of terms
        Term ThePoly[MAXTERMS];

        //The numbers of terms in the array
        int numTerms;

};//end class TermArrayList

#endif
