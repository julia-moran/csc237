/*!
\file TermTree.cpp
\brief TermTree implementation for storing terms in a tree

This file serves as the implementation for the functions for TermTree. It
implements the constructor to construct a TermTree using a BinarySearchTree. It
also implements the functions printRevOrder and printReverseinOrder, which
allows for the TermTree to be printed as a polynomial recursively.
*/
// Source Cited:
/*
/////////////////////////////////////////////////////////////////////////////////
    Author:         Dr. Spiegel
    Filename:       TermTree.cpp
    Date:           November 20, 2022
    Date retrieved: November 28, 2022
    Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/TermTree.cpp
*///////////////////////////////////////////////////////////////////////////////
/*
    Updated by:     Julia Moran
    Major:          Computer Science
    Retrieved Date: November 28, 2022
    Due Date:       December 4, 2022
    Course:         CSC237 010
    Professor Name: Dr. Speigel
    Assignment:     #4
    Filename:       TermTree.cpp
    Purpose:        This file will construct a tree made of Terms using the
                    BinaryTree class. It also implements functions that allow
                    for the entire polynomial of terms to be printed recursively.
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
    https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/TermTree.cpp
    All content except for the body of the printReverseinOrder function was
    authored by Dr. Spiegel */

// File: TermTree.cpp
// Update with your documentation, including a *good* description.
// And give proper attribution.

#include <iostream>
#include "TermTree.h"

// This is Complete
/*
    Function Name:  TermTree
    Description:    Serves as the constructor for TermTree
    Parameters:     N/A
    Return Value:   N/A
*/
TermTree::TermTree() : BinaryTree()
{}//end constructor

// Need Helper to Recursively Print the Polynomial
//The boolean is a reference so once the first node is printed, the rest have their flag changed
/*
    Function Name:  printReverseInorder
    Description:    Prints the terms in the tree in descending order as a
                    polynomial with a plus sign in between each term
    Parameters:     TreeNode<Term> - t: pointer to the current node to print
                    bool - first: indicates if the term is the first one to be
                                  printed
                                  if true: print the term without a plus sign
                                           after it
                                  if false: print the term with a plus sign
                                            after it
    Return Value:   N/A
*/
void TermTree::printReverseInorder(TreeNode<Term> *t, bool &first) const
{
    //Check if the pointer is pointing to a node in the tree
    //It will be NULL otherwise
    if (t) {
// Complete the function body

        printReverseInorder(t->right, first);
        //Print a plus sign if the current term is the first term to print
        if (first == false) {
            cout << " ";
            cout << symbol;
            cout << " ";
        }//end if

        //Print the data in the current Term
        cout << t->info;
        first = false;
        printReverseInorder(t->left, first);
    }//end if
}//end function printReverseInorder

/*
    Function Name:  printRevOrder
    Description:    Helper function to print the terms in the tree in
                    descending order as a polynomial with a plus sign in
                    between each term
    Parameters:     N/A
    Return Value:   N/A
*/
// Display Polynomial using Reverse InOrder Traversal
void TermTree::printRevOrder() const
{
    bool firstNode = true;

    //Call the recursive function to print the polynomial, starting at the root
    printReverseInorder(root, firstNode);
    cout << endl;
}//end function printRevOrder
