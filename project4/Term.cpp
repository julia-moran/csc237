/*! \file Term.cpp
    \brief  Implementation of the Term class

    \class Term
   
    Capabilities:
		\n - Evaluate itself 
		\n - Multiply coefficient by a scalar
		\n - Increment coefficient by a scalar
		\n - Compare in several ways
		\n - set and get (of course)
*/
//Source Cited
/***************************************************************
Author:         Dr. Spiegel
Filename:       Term.cpp   
Date:           November 26, 2019
Date retrieved: November 28, 2022
Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/Term.cpp
Purpose:        A Term holds a single Term of a Polynomial. Capabilities:
		- Evaluate itself 
		- Multiply coefficient by a scalar
		- Increment coefficient by a scalar
		- Compare in several ways
		- set and get (of course)
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
    Filename:       Term.cpp
    Purpose:        This file serves as the implementation for the Term class.
                    It implements a constructor and functions that set and get
                    the coefficient and exponent of the term. It also implements
                    various operators to compare terms and exponents, combine
                    terms with the same exponent, evaluate a term, update a
                    term's exponent, and stream insert a term.
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
    https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/Term.cpp
    All content was authored by Dr. Spiegel */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "Term.h"

using namespace std;

Term::Term(double coeff, int expn)
{   /*!
    *   \fn  Term
    *   \brief   Constructor
    *   \param double coeff- Coefficient to set the term to
    *   \param int expn- Exponent to set the term to
    *   \return N/A
    *********************************************************************/
	coefficient=coeff; //sets the coefficient
	exponent=expn; //sets the exponent
}

//Gets
double Term::getCoefficient() const //returns the coefficient
{	/*!
	*   \fn  getCoefficient
	*   \brief   retrieves the coefficient
	*   \param n/a
	*                                                                   
	*   \return double- the coefficient at the index
	*********************************************************************/
	return(coefficient); //return  the coefficient 
}

int Term::getExponent() const //returns the exponent
{	/*!
	*   \fn  getExponent
	*   \brief   retrieves the exponent
	*   \param n/a
	*                                                                   
	*   \return int- the exponent at the index
	*********************************************************************/
	return(exponent); //return  the exponent
}

//Sets
double Term::setCoefficient(double coeff) //sets the coefficient
{	/*!
	*   \fn  setCoefficient
	*   \brief   sets the coefficient
	*   \param n/a
	*                                                                   
	*   \return double- the coefficient at the index
	*********************************************************************/
	return(coefficient = coeff);//sets  the coefficient 
}

int Term::setExponent(int expn) //sets the coefficient
{	/*!
	*   \fn  setExponent
	*   \brief   sets the exponent
	*   \param n/a
	*                                                                   
	*   \return int- the exponent at the index
	*********************************************************************/
	return(exponent = expn);//sets  the coefficient 
}
//Other
double Term::operator()(double x) const //evaluates the term with x
{	/*!
	*   \fn  operator()
	*   \brief   Evaluates the term by the input number 
	*   \param double x- the number to evaluate to 
	*                                                                   
	*   \return the sum of the evaluated term
	*********************************************************************/
	return(getCoefficient() * (pow(x, getExponent()))); //returns the evaluation
}

bool Term::operator!=(int value) //compares exponents
{	/*!
	*   \fn  operator!=
	*   \brief  Compares an int against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if doesn't match // false- if match
	*********************************************************************/
	return(!(value == getExponent()));
}

bool Term::operator=(int value) //replaces exponenet
{	/*!
	*   \fn  operator!=
	*   \brief  Compares an int against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if doesn't match // false- if match
	*********************************************************************/
	return(exponent = value);
}

bool Term::operator!=(const Term &right) //compares exponents
{	/*!
	*   \fn  operator!=
	*   \brief  Compares a Term against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if doesn't match // false- if match
	*********************************************************************/
	return(!(getExponent()==right.getExponent()));
}

bool Term::operator==(int value) //compares exponents
{	/*!
	*   \fn  operator==
	*   \brief  Compares an int against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if match // false- if doesn't match
	*********************************************************************/
	return(value == getExponent());
}

bool Term::operator+=(const Term &right) //compares exponents
{	/*!
	*   \fn  operator+=
	*   \brief  adds input term coefficient to coefficient
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if match // false- if doesn't match
	*********************************************************************/
	return(setCoefficient(getCoefficient() + right.getCoefficient()));
}

bool Term::operator==(const Term &right) //compares exponents
{	/*!
	*   \fn  operator==
	*   \brief  Compares a Term against the exponent
	*   \param int value- the number to compare the exponent by
	*                                                                   
	*   \return true- if match // false- if doesn't match
	*********************************************************************/
	return(getExponent()==right.getExponent());
}

bool Term::operator<(const Term &right) const //checks if the incoming value is greater than the exponent
{	/*!
	*   \fn  operator<
	*   \brief  Compares two Terms based on exponent
	*   \param int value- the value to make the comparision to
	*                                                                   
	*   \return according to the comparison
	*********************************************************************/
	return(getExponent() < right.getExponent());
}

bool Term::operator< (int right) //checks if the incoming value is greater than the exponent
{	/*!
	*   \fn  operator<
	*   \brief  Compares Term's exponent to an int
	*   \param int value- the value to make the comparision to
	*                                                                   
	*   \return according to the comparison
	*********************************************************************/
	return(getExponent() < right);
}


ostream &operator<<(ostream &output,const Term &term)
{	/*!
	*   \fn  operator<<
	*   \brief  For output
	*   \param ofstream &ouput- 
	*	\param const Term &t- the term object to be outputted
	*                                                                   
	*   \return output
	*********************************************************************/
	if (term.getCoefficient()!=1)
		output << term.getCoefficient();
	if (term.getExponent() ==1)//if it needs an x^ or x
		output << "x"; // x alone if to the one power
	else if (term.getExponent() > 1)
		output << "x^" << term.getExponent(); 
	return (output); //returns the results //enables cascading
}
