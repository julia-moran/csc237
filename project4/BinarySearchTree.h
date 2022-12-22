/*!
\file BinarySearchTree.h
\brief BinaryTree ADT defined using Linked Structures

This file contains the definition and implementation of the templated class
TreeNode and the definition of the templated class BinaryTree. The BinaryTree
has public functions that include the constructor and functions that allow for
inserting a node to the tree, search the tree for a node, retrieve a node from
the tree, delete a node from the tree, and display the tree using InOrder
Traversal, PreOrder Traversal, PostOrder Traversal, and Breadth first print. It
also contains protected member functions printInorder, printPreorder,
printPostorder, and treePrintHelper as well as a protected pointer to the root
node.
*/
//Source Cited
/***************************************************************
Author:         Dr. Spiegel
Filename:       BinarySearchTree.h
Date:           November 15, 2019
Date retrieved: November 28, 2022
Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/BinarySearchTree.h
Purpose:        Binary Tree ADT defined using Linked Structures
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
    Filename:       BinarySearchTree.h
    Purpose:        This file contains the definition and implementation of
                    the templated class TreeNode and the definition of the
                    templated class BinaryTree. The BinaryTree class has
                    public functions that include the constructor and
                    functions that allow for inserting a node to the tree,
                    search the tree for a node, retrieve a node from the tree,
                    delete a node from the tree, and display the tree using
                    InOrder Traversal, PreOrder Traversal, PostOrder
                    Traversal, and Breadth first print. It also contains
                    protected member functions printInorder, printPreorder,
                    printPostorder, and treePrintHelper as well as a protected
                    pointer to the root node.
*///////////////////////////////////////////////////////////////////////////////

/* Citation source: This file was retrieved from Dr. Spiegel's website at
    https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project4/BinarySearchTree.h
    All content was authored by Dr. Spiegel */

// File: BinarySearchTree.h
// Binary Tree ADT defined using Linked Structures

#ifndef TREE_H
#define TREE_H

 template <typename eltType> class BinaryTree;

 template <typename eltType> class TreeNode {
 /*!
    \class TreeNode
    \brief Friend class to BinaryTree and TermTree that implements the TreeNode
           object

       This class is a friend to BinaryTree and TermTree and implements the
       construction of tree nodes, objects to hold data in the tree. It contains
       data in the node, a pointer to the node's left child, and a pointer to
       the node's right child as data members. All contents of the TreeNode
       class are private.
 */
 private:
  //Data Members
  eltType info; //Data in the tree node
  TreeNode<eltType> *left,*right; //Pointers to the left and right child
    /*!
        \fn TreeNode
        \brief Constructor
        \n Constructs a node object to store the data in a tree
        \param data The data to be stored in the node (eltType).
        \param lChild The pointer to the left child of the current node
                      (TreeNode<eltType>).
        \param rChild The pointer to the right child of the current node
                      (TreeNode<eltType>)
    */
  TreeNode(const eltType &data,
                        TreeNode<eltType> *lChild=NULL,TreeNode *rChild=NULL)
  {info=data;   left=lChild; right=rChild;  }

  //Allows BinaryTree and TermTree access to TreeNode's data members
  friend class BinaryTree<eltType>;
  friend class TermTree;
 };//end class TreeNode

template <typename eltType> class BinaryTree {
/*!
    \class BinaryTree
    \brief Stores the data in a binary search tree

        This class includes the constructor and functions that allow for
        inserting a node to the tree, search the tree for a node, retrieving
        a node from the tree, deleting a node from the tree, and displaying
        the tree using InOrder Traversal, PreOrder Traversal, PostOrder
        Traversal, and Breadth first print. It also contains protected member
        functions printInorder, printPreorder, printPostorder, and
        treePrintHelper as well as a protected pointer to the root node.
*/
public:
 /*!
    \fn BinaryTree
    \brief Constructor
    \n This function serves as the constructor for the BinaryTree class.
    \param N/A
    \return N/A
 */
 // Constructor
 BinaryTree();

 /*!
    \fn insertToTree
    \brief Inserts a node to the tree
    \n This function inserts a new node to the binary tree if it is not already
       not in the tree.
    \param data The data to add to the tree (eltType).
    \return 1 if the data was successfully inserted into the tree,
            0 if the data was already in the tree and thus not inserted (int).
 */
 // Place Element into Tree
 // Returns 1 if inserted, 0 if Data already in tree
 int insertToTree(const eltType &data);

 /*!
    \fn treeSearch
    \brief Search for Element in Tree
    \n This function searches for a specified element in the tree. It assumes
        == is defined for the element's type.
    \param data The data to search from the tree (eltType).
    \return t The boolean value to indicate if the element was found in the
              tree (bool).
 */
 // Search for Element in Tree
 // Assumes == is defined for eltType
 // Returns bool according to success
 bool treeSearch(const eltType &data);

 /*!
    \fn retrieveFromTree
    \brief Retrieve Element from Tree (leaving Tree Intact)
    \n This function retrieves the data from a specified node in the tree
       without editing the tree itself. It assumes that the element to retrieve
       is in the tree.
    \param data The element to retrieve from the tree (eltType).
    \return t->info The data from the specified node (eltType).
 */
 // Retrieve Element from Tree (leaving Tree Intact)
 // Precondition: Item is in Tree
 eltType &retrieveFromTree(const eltType &data);

 /*!
    \fn deleteFromTree
    \brief Remove an Element from the tree
    \n This function will delete a specified node from the tree. It will assume
       the node to delete is currently in the tree.
    \param data The element to delete from the tree (eltType).
    \return N/A
 */
 // Remove an Element from the tree
 // Pre: Element is in the Tree
 void deleteFromTree(const eltType &data);

 /*!
    \fn inorder
    \brief Display Tree using InOrder Traversal
    \n This function will recursively print the elements in the tree in order
       utilizing the printInorder helper function.
    \param N/A
    \return N/A
 */
 // Display Tree using InOrder Traversal
 void inorder() const;


 /*!
    \fn preorder
    \brief Display Tree using PreOrder Traversal
    \n This function will recursively print the elements in the tree through a
       preorder traversal utilizing the printPreorder helper function.
    \param N/A
    \return N/A
 */
 // Display Tree using PreOrder Traversal
 void preorder() const;

 /*!
    \fn postorder
    \brief Display Tree using PostOrder Traversal
    \n This function will recursively print the elements in the tree through a
       postorder traversal utilizing the printPostorder helper function.
    \param N/A
    \return N/A
 */
 // Display Tree using PostOrder Traversal
 void postorder() const;
 
 /*!
    \fn treePrint
    \brief Breadth first print
    \n This function will recursively print the elements in the tree by level
       utilizing the treePrintHelper helper function.
    \param N/A
    \return N/A
 */
 // Breadth first print
 void treePrint() const;
 
protected:

 //Data Member
 TreeNode<eltType> *root; //Pointer to the root of the tree

 /*!
    \fn printInorder
    \brief Helper to Recursively Print the Tree in Order
    \n This function will serve as a helper function and perform the recursion
       for the inorder function to print the contents of the tree in order.
    \param t Pointer to the current node (TreeNode<eltType>).
    \return N/A
 */
 // Display Tree using InOrder Traversal
 void printInorder(TreeNode<eltType> *) const;

 /*!
    \fn printPreorder
    \brief Helper to Recursively Print the Tree using PreOrder Traversal
    \n This function will serve as a helper function and perform the recursion
       for the preorder function to print the contents of the tree using
       preorder traversal.
    \param t Pointer to the current node (TreeNode<eltType>).
    \return N/A
 */
 // Display Tree using PreOrder Traversal
 void printPreorder(TreeNode<eltType> *) const;
 /*!
    \fn printPostorder
    \brief Helper to Recursively Print the Tree using PostOrder Traversal
    \n This function will serve as a helper function and perform the recursion
       for the postorder function to print the contents of the tree using
       postorder traversal.
    \param t Pointer to the current node (TreeNode<eltType>).
    \return N/A
 */
 // Display Tree using PostOrder Traversal
 void printPostorder(TreeNode<eltType> *) const;

 /*!
    \fn treePrintHelper
    \brief Helper to Recursively Print the Tree by Level
    \n This function will serve as a helper function and perform the recursion
       for the treePrint function to print the contents of the tree by level.
    \param root Pointer to the current root node (TreeNode<eltType>).
    \return N/A
 */
 void treePrintHelper(TreeNode<eltType> *) const;

};//end class BinarySearchTree

#endif
