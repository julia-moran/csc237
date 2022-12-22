/*!
\file Term.h
\brief Class to create Term object

This class creates a Term object that contains a coefficient and
an exponent. It also contains various operators to compare terms and exponents.
It has a double coefficient value and an integer exponent as data members.
*/
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
Due Date:       November 11, 2022
Course:         CSC237 010
Professor Name: Dr. Spiegel
Assignment:     #3
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

class Term {
    /*!
        \class Term
        \brief Class that implements the Term class

        \n This class creates a Term object that contains a coefficient and an
           exponent. It also contains various operators to compare terms and
           exponents. It has a double coefficient value and an integer
           exponent as data members.
    */
public:
    /*!
        \fn Term
        \brief Constructor
        \n This function serves as the constructor for the Term class.
        \param coeff The value of the coefficient for the term, default
                     value is 0 (double).
        \param expn The value of the exponent for the term, default value
                    is 0 (int).
        \return N/A
    */
    Term(double=0, int=0);  //default value of 0x^0

    //Gets (No sets in immutable object)
    /*!
        \fn getCoefficient
        \brief Retrieves coefficient
        \n The getCoefficient function returns the current coefficient.
        \param N/A
        \return coefficient The coefficient in the Term object.
    */
    double getCoefficient() const;      //returns the coefficient

     /*!
        \fn getExponent
        \brief Retrieves exponent
        \n The getExponent function returns the current exponent value.
        \param N/A
        \return exponent The exponent in the Term object.
     */
    int getExponent() const;        //returns the exponent

    //evaluate
    //Function Name: operator()
    /*!
        \brief Evaluates the polynomial
        \n The () operator evaluates the polynomial by adding up each result when
        the x value is plugged into each term.
        \param x The value for x to plug into each term (double).
        \return answer The end result when x is plugged into the polynomial (double).
    */
   double operator()(double x) const;  // evaluation of term

    //other
    //Function Name: operator==
    // does exponent match the parameter? Note signature ==(Term&,int)
    /*!
        \brief Compares exponents
        \n This == operator will compare an int against the exponent.
        \param value The number to compare the exponent by (int).
        \return A boolean value, true if the integer matches the exponent,
                                 false otherwise.
    */
    bool operator==(int value);

    //Function Name: operator==
    /*!
        \brief Compares exponents
        \n This == operator will compare a Term against the exponent.
        \param right The term to compare the exponent by (Term).
        \return A boolean value, true if the integer matches the exponent,
                                 false otherwise.
    */
    // does exponent match that of the param?  Signature: ==(Term,Term)
    bool operator==(const Term &right);

    //Function Name: operator <
    /*!
        \brief Compare exponents
        \n The < operator will compare the exponents of two terms to determine
            which one is larger than the other.
        \param right The value to make the comparision to (Term).
        \return A boolean value, true if the left term is less than the right,
                                 false otherwise
    */
    // is this term's exponent less than right's? Signature <(Term&,Term&)
    bool operator<(Term &right);


    // is this term's exponent less than right? Signature: <(Term&,int)
    //Function Name: operator <
    /*!
        \brief Compare exponents
        \n The < operator will compare the exponents of two terms to determine
           which one is larger than the other.
        \param right The value to make the comparision to (int).
        \return A boolean value, true if the left term is less than the right,
                                 false otherwise
    */
    bool operator<(int right);

private:
    double coefficient; //holds the coefficient value
    int exponent; //holds the exponent value

};
    // Stream insert a term
    //Function Name: operator<<
    /*!
        \brief Stream insert a term
        \n The << operator will output a term by correctly formatting the
           coefficient and exponent.
        \param term A Term object containing a coefficient and exponent
                   (Term).
        \param output Output stream object (ostream).
        \return output Output stream object (ostream).
    */
    ostream &operator<<(ostream &output,const Term &term);
#endif
