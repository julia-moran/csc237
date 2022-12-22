/*!
\file TermTree.h
\brief Tree made of Term objects created using a BinarySearchTree

This file will construct a tree made of Terms using the BinaryTree class. It also
contains functions that allow for the entire polynomial of terms to be printed
recursively.
*/
// Source Cited:
/*
/////////////////////////////////////////////////////////////////////////////////
    Author:         Dr. Spiegel
    Filename:       TermTree.h
    Date:           November 20, 2022
    Date retrieved: November 28, 2022
    Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/TermTree.h
*///////////////////////////////////////////////////////////////////////////////
/*
    Updated by:     Julia Moran
    Major:          Computer Science
    Retrieved Date: November 28, 2022
    Due Date:       December 4, 2022
    Course:         CSC237 010
    Professor Name: Dr. Speigel
    Assignment:     #4
    Filename:       Term.cpp
    Purpose:        This file will construct a tree made of Terms using the
                    BinaryTree class. It also contains functions that allow for
                    the entire polynomial of terms to be printed recursively.
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
    https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/TermTree.h
    All content was authored by Dr. Spiegel */


// File: TermTree.h
// Update with your documentation, including a *good* description.
// And give proper attribution.



#ifndef TERMTREE_H
#define TERMTREE_H

#include <iostream>
#include "BinarySearchTree.h"
#include "Term.h"

using namespace std;

const char symbol='+';

class TermTree : public BinaryTree<Term> {
//               ^^^^^^
/*!
    \class TermTree
    \brief TermTree subclass that implements a tree of terms

    \n This subclass inherits from BinaryTree<Term> to create a tree of Term
       objects. It contains the constructor, a public recursive function that
       prints the polynomial as a sum of the terms in descending order, and a
       private function that serves as the recursive helper for the public
       printRevOrder function.
*/
public:
 /*!
    \fn TermTree
    \brief Constructor
    \n This function serves as the constructor for TermTree
    \param N/A
    \return N/A
 */
 TermTree(); 

/*!
    \fn printRevOrder
    \brief Helper function to print preorder with only symbol parameter
    \n Display Polynomial using Reverse InOrder Traversal
    \param N/A
    \return N/A
*/
 void printRevOrder() const;

private:
/*!
    \fn printReverseInorder
    \brief Prints the polynomial inorder reversed using recursion 
    \n Display Polynomial using Reverse InOrder Traversal, inserting + signs between terms.
    \param TreeNode<Term> *t (import) - a pointer to the tree to be printed.
    \param bool& first (import/export) - if the current node is the first one to be printed, it's true --> no + sign. Otherwise, false --> + sign first.
    \return N/A
*/
  void printReverseInorder(TreeNode<Term> *t, bool &first) const;

};//end class

#endif
