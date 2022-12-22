/*
    Author:         Julia Moran
    Major:          Computer Science
    Retrieved Date: October 13, 2022
    Due Date:       October 25, 2022
    Course:         CSC237 010
    Professor Name: Dr. Spiegel
    Assignment:     #2
    Filename:       DblLink.h
    Purpose:        This file contains the Node, DblLink, and DblLinkItr
                    classes' prototypes, data members, and implementations
*/
// Sources Cited:
/*//////////////////////////////////////////////////////////////////////////////
    Author:         Dr. Spiegel
    Filename:       LinkedList.h
    Date:           November 29, 2018
    Date retrieved: October 13, 2022
    Purpose:        Linked List class with List Iterator class
    Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/SinglyLinkedList/LinkedList.h
*//////////////////////////////////////////////////////////////////////////////
/*
    Author:         Dr. Spiegel
    Filename:       Node.h
    Date:           October 11, 2016
    Date retrieved: October 13, 2022
    Purpose:        Doubly-linked list node definition/implementation
    Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/Node.h
*///////////////////////////////////////////////////////////////////////////////

/* Citation Source: This file was based on the files retrieved from
   Dr. Spiegel's website at
   https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/SinglyLinkedList/LinkedList.h
   and
   https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/Node.h */
#ifndef DBLLINK_H
#define DBLLINK_H

#include <iostream>

using namespace std;

//Prototypes of DblLink and DblLinkItr, needed since they are friends to class Node
template <typename eltType> class DblLink;
template <typename eltType> class DblLinkItr;

/* Citation Source: The Node class was retrieved from Dr. Spiegel's website at
   https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/Node.h
   All content was authored by Dr. Spiegel */
template <class eltType> class Node
{
    private:
        //Data members
        Node(eltType info, Node *pLink = 0, Node *rLink=0)
              : data(info), prev(pLink), next(rLink) {};
        eltType data; //Data in the node
        Node*   prev; //Points to the node before the node
        Node*   next; //Points to the node after the node

    //Allows DblLink and DblLinkItr access to Node's data members
    friend class DblLink<eltType>;
    friend class DblLinkItr<eltType>;
}; //end class Node

/* Citation Source: The DblLink class was based on the LinkedList class in the
   LinkedList.h file retrieved from Dr. Spiegel's website at
   https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/SinglyLinkedList/LinkedList.h
   All functions used the LinkedList.h file as an example */
template <typename eltType> class DblLink
{
    public:
        //Function Prototypes

        //Constructor
        DblLink();

        //Copy Constructor
        DblLink(DblLink<eltType>&);

        //Destructor
        ~DblLink();

        //Assignment Operator
        DblLink<eltType>& operator=(const DblLink<eltType>&);

        //Insert and Remove Functions
        void insert(eltType);
        bool remove(eltType);

    private:
        //Data members
        Node<eltType>* head; //Pointer to first node in the list

    friend class DblLinkItr<eltType>;
}; //end class DblLink

/* Citation Source: The DblLinkItr class was based on the ListIterator class in
   the LinkedList.h file retrieved from Dr. Spiegel's website at
   https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project2/SinglyLinkedList/LinkedList.h
   All the functions used LinkedList.h as an example
*/
template <typename eltType> class DblLinkItr
{
    public:
        //Function Prototypes

        //Constructor
        DblLinkItr(const DblLink<eltType> &listRef);

        //Other Function Prototypes
        void start();
        bool isEmpty();
        bool isLastNode();
        bool isFirstNode();
        eltType operator*();
        DblLinkItr<eltType> operator++();
        DblLinkItr<eltType> operator--();

    private:
        //Data Members
        const DblLink<eltType> &listRef; //reference to a DblLink list
        Node<eltType> *current; //pointer to the current node
};//end class DblLinkItr


////////////////////////DBLLINK FUNCTIONS/////////////////////////////

/*
    Function Name:  DblLink
    Description:    Serves as a contructor for the doubly linked list
    Parameters:     N/A
    Return Value:   N/A
*/
template <typename eltType> DblLink<eltType>::DblLink() : head(NULL)
{}//end constructor

/*
    Function Name:  DblLink
    Description:    Serves as the copy constructor for a DblLink object
    Parameters:     DblLink - DblLinkRef: a reference to the doubly linked list
    Return Value:   N/A
*/
template <typename eltType>
    DblLink<eltType>::DblLink(DblLink<eltType> &DblLinkRef)
{
    //Check if the source list is empty
    if(DblLinkRef.head != NULL)
    {
        //Pointer to the first item in the list
        Node<eltType>* first = NULL;

        //Pointer to the last item in the list
        Node<eltType>* last = NULL;

        //Begin the new list with the first node in the source list
        //and set the first and last pointers to the head of the new list
        first = last = new Node<eltType>(DblLinkRef.head->data, NULL, NULL);

        //Continue through the source list and new list until the end of the
        //source list has been reached
        for(Node<eltType>* source = DblLinkRef.head->next; source != NULL;
                                        source = source->next, last = last->next)
        {
            //Copy each element in the source list to the new list
            last->next = new Node<eltType>(source->data, last, NULL);
        }//end for loop

        //Set the head of the new list to the first node in the new list
        head = first;
    }//end if
    else
    {
        head = NULL;
    }//end else
}//end copy constructor

/*
    Function Name:  ~DblLink
    Description:    Serves as the destructor for the DblLink object
    Parameters:     N/A
    Return Value:   N/A
*/
template <typename eltType> DblLink<eltType>::~DblLink()
{
    while(head != NULL)
    {
        //Make a pointer to the current node, starting at head
        Node<eltType> *doomed = head;

        //Move to the next node
        head = head->next;

        //Delete the current node
        delete doomed;
    }//end while loop
}//end destructor

/*
    Function Name:  operator=
    Description:    Assignment operator for the DblLink object
    Parameters:     DblLink - DblLinkRef: reference to the DblLink object
    Return Value:   N/A
*/
template <typename eltType> DblLink<eltType>
        &DblLink<eltType>::operator =(const DblLink<eltType> &DblLinkRef)
{
    if(this != &DblLinkRef)
    {
        //Delete the data from the list being assigned
        while(head != NULL)
        {
            Node<eltType> *doomed = head;

            head = head->next;
            delete doomed;
        }//end while loop

        //Copy the data in the source list to the list being assigned
        if(DblLinkRef.head != NULL)
        {
            //Create pointers to the first and last nodes in the list being assigned
            Node<eltType>* first = NULL;
            Node<eltType>* last = NULL;

            //Set the first and last pointers to the first node in the list being
            //assigned, which will be the head node in the source list
            first = last = new Node<eltType>(DblLinkRef.head->data, NULL, NULL);

            //Continue through the list being assigned and the source list until
            //the end of the source list has been reached
            for(Node<eltType>* source = DblLinkRef.head->next; source != NULL;
                                            source = source->next, last = last->next)
            {
                //Copy each node in the source list to the list being assigned
                last->next = new Node<eltType>(source->data, last, NULL);
            }//end for

            head = first;
        }//end if
        else
        {
            head = NULL;
        }//end else
    }//end if

    //Allow cascading by returning the this pointer
    return *this;
}//end operator=

/*
    Function Name:  insert
    Description:    Insert the element into the doubly linked list in order
    Parameters:     eltType - element: the element to be inserted into the list
    Return Value:   N/A
*/
template <typename eltType>
                void DblLink<eltType>::insert(eltType elementToInsert)
{
    //Check if the new element is being inserted in an empty list
    if(head == NULL)
    {
        head = new Node<eltType>(elementToInsert, NULL, NULL);
    }//end if

    //Check if the new element is to be inserted at the head
    else if(elementToInsert < head->data)
    {
        //Insert the new node at the head
        head = new Node<eltType>(elementToInsert, NULL, head);
        head->next->prev = head;
    }//end else if

    //Consider all other cases
    else
    {
        //Set pointers to a current node and the node trailing after the current,
        //starting at the second node in the list since the first was already checked
        Node<eltType>* currentNode = head->next;
        Node<eltType>* trail = head;

        //Continue through the list until the end is reached or the position
        //to enter the new element has been found
        while(currentNode != NULL && currentNode->data < elementToInsert)
        {
            trail = currentNode;
            currentNode = currentNode->next;
        }//end while loop

        //Insert the new node before the first encountered node whose data is
        //greater than the data in the node being inserted
        trail->next = new Node<eltType>(elementToInsert, trail, currentNode);

        //Check if the node is being inserted before the last node
        if(currentNode != NULL)
        {
            //Set the current node's prev pointer to point at the node being
            //inserted if the current node is not the last node in the list
            currentNode->prev = trail->next;
        }//end if
    }//end else
}//end function insert

/*
    Function Name:  remove
    Description:    Searches for and removes an element from the doubly linked
                    list
    Parameters:     eltType - xToRemove: the element from the list to remove
    Return Value:   bool - true if the element was found in the list
                           false if the element was not found
*/
template <typename eltType> bool DblLink<eltType>::remove(eltType xToRemove)
{
    bool found = false; //set if the node in the list was found
    Node<eltType>* currentNode = head; //points to a current node
    Node<eltType>* trail = NULL; //points to the node following the current node

    //Continue through the list until the end is reached or the element to
    //remove is found
    while(currentNode != NULL && !(currentNode->data == xToRemove))
    {
        trail = currentNode;
        currentNode = currentNode->next;
    }//end while loop

    //The case of the node being removed from the head
    if(currentNode == head)
    {
        head = head->next;

        //If the list is not empty after removing from the head, set the prev
        //pointer to NULL
        if(head != NULL)
        {
            head->prev = NULL;
        }//end if

        found = true; //The element was found in the list
    }//end if
    //All other cases
    else if (currentNode != NULL)
    {
        //The case of the node to remove not being at the head or end of the list
        if(currentNode->next != NULL)
        {
            trail->next = currentNode->next;
            currentNode->next->prev = trail;
        }//end if
        //The case of the node to remove being at the end of the list
        else
        {
            trail->next = currentNode->next;
        }//end else

        found = true; //The element was found in the list
    }//end else if

    //Delete the node and return true if the element was found in the list
    if(found == true)
    {
        delete currentNode;
        return true;
    }//end if
    //Return false if the element was not found in the list
    else
    {
        return false;
    }//end else
}//end functio remove


/////////////////////ITERATOR FUNCTIONS///////////////////////////
/*
    Function Name:  DblLinkItr
    Description:    Serves as the constructor for the DblLinkItr
    Parameters:     DblLink - list: a doubly linked list
    Return Value:   N/A
*/
template<typename eltType>
DblLinkItr<eltType>::DblLinkItr(const DblLink<eltType> &list):
                                        listRef(list), current(NULL)
{}//end constructor

/*
    Function Name:  start
    Description:    Set the iterator's pointer to point at the first node of the
                    doubly linked list
    Parameters:     N/A
    Return Value:   N/A
*/
template <typename eltType> void DblLinkItr<eltType>::start()
{
    current = listRef.head;
}//end function start

/*
    Function Name:  isEmpty
    Description:    Returns whether or not the doubly linked list is empty
    Parameters:     N/A
    Return Value:   bool - true if the list is empty
                           false if the list is not empty
*/
template <typename eltType> bool DblLinkItr<eltType>::isEmpty()
{
    return listRef.head == NULL;
}//end function isEmpty

/*
    Function Name:  isLastNode
    Description:    Returns whether the current node is the last node in the list
    Parameters:     N/A
    Return Value:   bool - true if the current node is the last node in the list
                           false if the current node is not the last node in
                           the list
*/
template <typename eltType> bool DblLinkItr<eltType>::isLastNode()
{
    return current->next != NULL;
}//end function isLastNode

/*
    Function Name:  isFirstNode
    Description:    Returns whether or not the current node is the first node
                    in the doubly linked list
    Parameters:     N/A
    Return Value:   bool - true if the current node is the first node in the list
                           false if the current node is not the first node in
                           the list
*/
template <typename eltType> bool DblLinkItr<eltType>::isFirstNode()
{
      return current != listRef.head;
}//end function isFirstNode

/*
    Function Name:  operator*
    Description:    Returns the data of the node currently being pointed at
    Parameters:     N/A
    Return Value:   eltType -  the data of the node currently being pointed at
*/
template <typename eltType> eltType DblLinkItr<eltType>::operator*()
{
    return current->data;
}//end function operator

/*
    Function Name:  operator++
    Description:    Advances the pointer to the next node in the list
    Parameters:     N/A
    Return Value:   pointer to the current node
*/
template<typename eltType> DblLinkItr<eltType>
    DblLinkItr<eltType>::operator++()
{
    current = current->next;
    return *this;
}//end operator++

/*
    Function Name:  operator--
    Description:    Advances the pointer to the previous node in the list
    Parameters:     N/A
    Return Value:   pointer to the current node
*/
template<typename eltType> DblLinkItr<eltType>
     DblLinkItr<eltType>::operator--()
{
    current = current->prev;
    return *this;
}//end operator--
#endif
