// Source Cited
/***************************************************************
Author:         Dr. Spiegel
Filename:       Term.h
Purpose:        A Term holds one term of a polynomial. A term
                can be created, evaluated, compared, and printed
Date:           September 9, 2022
Date retrieved: October 13, 2022
Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/term.h
***************************************************************/
/*
Retrieved by:   Julia Moran
Major:          Computer Science
Retrieved Date: October 13, 2022
Due Date:       October 25, 2022
Course:         CSC237 010
Professor Name: Dr. Spiegel
Assignment:     #2
Filename:       Term.h
Purpose:        This file serves as the header file for the Term object. It
                contains the prototypes and data members associated with a Term
*/

/* Citation Source: This file was retrieved from Dr. Spiegel's website at
   https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/term.h
    All content was authored by Dr. Spiegel */
#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term
{
public:
    //Constructor
    Term(double=0, int=0);  //default value of 0x^0

    //Gets (No sets in immutable object)
    double getCoefficient() const;      //returns the coefficient
    int getExponent() const;        //returns the exponent

    //evaluate
    double operator()(double x) const;  // evaluation of term

    //other
    // does exponent match the parameter? Note signature ==(Term&,int)
    bool operator==(int value);
    // does exponent match that of the param?  Signature: ==(Term,Term)
    bool operator==(const Term &right);
    // is this term's exponent less than right's? Signature <(Term&,Term&)
    bool operator<(Term &right);
    // is this term's exponent less than right? Signature: <(Term&,int)
    bool operator<(int right);

private:
    double coefficient; //holds the coefficient value
    int exponent; //holds the exponent value

};
    // Stream insert a term
    ostream &operator<<(ostream &output,const Term &term);
#endif
