/*!
\file Term.h
\brief Class to create a Term object

This class creates a Term object that contains a coefficient and an exponent.
It contains a constructor and functions that set and get the coefficient and
exponent of the term. It also contains various operators to compare terms and
exponents, combine terms with the same exponent, evaluate a term, update a
term's exponent, and stream insert a term. It has a double coefficient value
and an integer exponent as data members.
*/
//Source Cited
/***************************************************************
Author:         Dr. Spiegel - Modified by Patrick Stelmach
Filename:       Term.h
Date:           November 26, 2019
Date retrieved: November 28, 2022
Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/Term.h
Purpose:        A Term holds one term of a polynomial. A term 
        		can be created, evaluated, compared, and printed
***************************************************************/
///////////////////////////////////////////////////////////////////////////////
/*
    Retrieved by:   Julia Moran
    Major:          Computer Science
    Retrieved Date: November 28, 2022
    Due Date:       December 4, 2022
    Course:         CSC237 010
    Professor Name: Dr. Speigel
    Assignment:     #4
    Filename:       Term.h
    Purpose:        This class creates a Term object that contains a coefficient
                    and an exponent. It contains a constructor and functions
                    that set and get the coefficient and exponent of the term.
                    It also contains various operators to compare terms and
                    exponents, combine terms with the same exponent, evaluate
                    a term, update a term's exponent, and stream insert a term.
                    It has a double coefficient value and an integer exponent
                    as data members.
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
    https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/Term.h
    All content was authored by Dr. Spiegel */

#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

/*!
    \class Term
    \brief A Term holds one term of a polynomial.

    The term can be created, evaluated, compared, and printed. Created by Dr. Spiegel.
*/
class Term
{
public:
	///Constructor
	Term(double=0, int=0); 	//default value of 0x^0

	///Gets - returns the coefficient
	double getCoefficient() const;
	///Gets - returns the exponent
	int getExponent() const;

	///Sets the coefficient
	double setCoefficient(double coeff) ;

	///Sets the exponent
	int setExponent(int expn);

	///evaluation of term
	double operator()(double x) const;

	//other
	/// updates the exponent 
	bool operator=(int value); //Note signature ==(Term&,int)
	/// does exponent match the parameter? 
	bool operator==(int value); //Note signature ==(Term&,int)
	/// does exponent match that of the param?  
	bool operator==(const Term &right); //Signature: ==(Term,Term)
	/// adds the term coefficents and updates this coefficient
	bool operator+=(const Term &right); //Signature: +=(Term,Term)
	/// does exponent match that of the param?  
	bool operator!=(int value); //Note signature !=(Term&,int)
	/// does exponent match that of the param?  
	bool operator!=(const Term &right); //Signature: !=(Term,Term)
	/// is this term's exponent less than right? 
	bool operator<(const Term &right) const;//Signature <(Term&,Term&)
	/// is this term's exponent less than right? 
	bool operator<(int right);//Signature: <(Term&,int)

private:
	double coefficient; //holds the coefficient value
	int exponent; //holds the exponent value

};
	/// Stream insert a term
	ostream &operator<<(ostream &output,const Term &term); 
#endif
