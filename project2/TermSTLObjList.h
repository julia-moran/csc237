/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  October 16, 2022
    Due Date:       October 25, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #2
    Filename:       TermSTLObjList.h
    Purpose:        This file serves as the header file for the TermSTLObjList.
                    It contains the prototypes for the constructor, the
                    respective pure virtual functions inherited from TermList,
                    and has a vector to contain Term objects as a data member.
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
    public:
        //Function Prototypes

        // Function Name:  TermSTLObjList
        // Description:    Serves as the constructor for the TermSTLObjList
        // Parameters:     N/A
        // Return Value:   N/A
        TermSTLObjList();

        // Function Name:  readIntoList
        // Description:    Reads the data from the file to a vector
        // Parameters:     string - filename: name of the file to read the data
        //                                    in from
        // Return Value:   N/A
        void readIntoList(string filename);

        // Function Name:  printIteratively
        // Description:    Prints the contents of the vector using an iterator
        // Parameters:     N/A
        // Return Value:   N/A
        void printIteratively();

        // Function Name:  operator()
        // Description:    Evaluates the polynomial by adding up each result when
        //                 the x value is plugged into each term
        // Parameters:     double - xToEvaluate: the value for x to plug into each
        //                                       term
        // Return Value:   double - result after the x value is plugged into each
        //                          term and added up
        virtual double operator()(double xToEvaluate) const;

    private:
        //Data Members

        //A vector made of Term objects
        vector<Term> ThePoly;
};//end class TermSTLObjList

#endif
