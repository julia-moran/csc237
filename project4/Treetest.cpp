/*!
\file Treetest.cpp
\brief Driver for TermTree

This program will allow a user to insert and delete nodes from a Binary Tree of
Term objects. It will also allow for the user to print the tree as a tree or as
a polynomial, with the terms printed in descending order with a plus sign in
between each term.
*/
//Source Cited
/***************************************************************
Author:         Dr. Spiegel
Filename:       Treetest.cpp
Date:           November 19, 2022
Date retrieved: November 28, 2022
Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/Treetest.cpp
Purpose:        Driver for Binary Tree ADT
***************************************************************/
///////////////////////////////////////////////////////////////////////////////
/*
    Updated by:     Julia Moran
    Major:          Computer Science
    Retrieved Date: November 28, 2022
    Due Date:       December 4, 2022
    Course:         CSC237 010
    Professor Name: Dr. Speigel
    Assignment:     #4
    Filename:       Treetest.cpp
    Purpose:        This program will allow a user to insert and delete nodes
                    from a binary tree of Term objects. It will also allow for
                    the tree as a tree or as a polynomial, with the terms
                    printed in descending order with a plus sign in between
                    each term.
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
    https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/Treetest.cpp
    All content except for the usage of the TermTree class was authored by
    Dr. Spiegel */

// File: TreeTest.cpp
// Driver for Binary Tree ADT

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "TermTree.h"

using namespace std;

typedef TermTree BinTree;

char getChoice(string ok);

int main() {
    //Variables
    BinTree Tree;
    Term entry;
    int result;
    double coefficient;
    int exponent;
    char Choice;

    do {
        //Get the choice from the user
        cout << "\n\nSelect: A)dd    R)emove     P)rint     T)ree Print     Q)uit\n";
        Choice = getChoice("ARPTQ");

        //Perform the choice of action specified by the user
        switch (Choice) {

        //The case of inserting a term to the tree
        case 'A':
            //Get the term to enter to the tree
            cout << " Enter a Term >";
            cin >> coefficient >> exponent;
            entry.setCoefficient(coefficient);
            entry.setExponent(exponent);

            //Attempt to insert the new term into the tree
            result = Tree.insertToTree(entry);

            //Print whether adding to the tree was successful
            if (!result)
                cout << "\n" << entry << " Already In Tree\n";
            else
                cout << "\n" << entry << " Added to Tree\n";
            break;

        //The case of printing the contents of the tree as a polynomial
        case 'P':
            cout << "The Tree:" << endl;
            Tree.printRevOrder();
            break;

        //The case of removing a node from the tree
        case 'R':
            //Get the exponent of the value to delete
            cout << "Value to Delete? (Enter Exponent) >";
            cin >> exponent;
            entry.setExponent(exponent);

            //Check if there is a term in the tree with the entered exponent
            result=Tree.treeSearch(entry);

            //Print if a term with the entered exponent was found
            if (!result)
                cout << "\nTerm with Exponent " << exponent << " Not Found\n";
            else {
                cout << "\nTerm with Exponent " << exponent << " Will Be Removed\n";
                //Delete the term with the entered exponent
                Tree.deleteFromTree(entry);
            }//end else
            break;

        //The case of printing the tree
        case 'T':
            cout << "The tree, as it appears (sort of)..\n";
            Tree.treePrint();
        }//end switch

    } while (Choice!='Q'); //Continue performing specified actions until the user quits
}//end main

//Function Name: getChoice
/*!
    \brief Gets the user's choice of action
    \n This function will get the user's choice of action and convert it to an
       uppercase character so that the choice is case insensitive.
    \param ok The possible characters for the user to select (string).
    \return ch The character that determines which action to take (char).
*/
char getChoice(string ok)
{
    //Variable
    char ch=' ';

    do ch=toupper(cin.get()); while (ok.find(ch)==string::npos);
    cin.get(); // eat CR

    return(toupper(ch));
}//end function getChoice
