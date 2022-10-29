//Source Cited:
/***************************************************************
Author:         Dr. Spiegel
Filename:       Term.h
Purpose:        A Term holds one term of a polynomial. A term
        can be created, evaluated, compared, and printed
***************************************************************/
/*
Retrieved By:   Julia Moran
Major:          Computer Science
Retrieved Date: September 15, 2022
Due Date:       September 22, 2022
Course:         CSC237 010
Professor Name: Dr. Spiegel
Assignment:     #1
Filename:       term.h
Retrieved From: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project1/term.h
Purpuse:        Header file for the term class
*/

/*Citation source: This makefile was retrieved from Dr. Spiegel's website at
https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project1/term.h on
September 15, 2022. All content was authored by Dr. Spiegel */

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
