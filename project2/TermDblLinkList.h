/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  October 16, 2022
    Due Date:       October 25, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #2
    Filename:       TermDblLinkList.h
    Purpose:        This file serves as the header file for the TermDblLinkList.
                    It contains the prototypes for the constructor, destructor,
                    and the respective pure virtual functions inherited from
                    TermList. It has a DblLink object as a data member.
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
    public:
        //Function Prototypes

        // Function Name:  TermDblLinkList
        // Description:    Serves as the constructor of the TermDblLinkList
        // Parameters:     N/A
        // Return Value:   N/A
        TermDblLinkList();

        // Function Name:  ~TermDblLinkList
        // Description:    Serves as the destructor of the TermDblLinkList
        // Parameters:     N/A
        // Return Value:   N/A
        ~TermDblLinkList();

        // Function Name:  readIntoList
        // Description:    Reads the data from the file into the doubly linked list
        // Parameters:     string - filename: name of the file to read the data
        //                                    in from
        // Return Value:   N/A
        void readIntoList(string filename);

        // Function Name:  printIteratively
        // Description:    Prints the contents of a doubly linked list using an
        //                 iterator
        // Parameters:     N/A
        // Return Value:   N/A
        void printIteratively();

        // Function Name:  operator()
        // Description:    Evaluates the polynomial by adding up each result when
        //                 the x value is plugged into each term
        // Parameters:     double - xToEvaluate: the value for x to plug into each
        //                                       term
        // Return Value:   N/A
        virtual double operator()(double xToEvaluate) const;

    private:
        //Data Members

        //A doubly linked list made of Term objects
        DblLink<Term> ThePoly;

};//end class TermDblLinkList

#endif
