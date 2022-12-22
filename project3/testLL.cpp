/*!
\file testLL.cpp
\brief Test driver program for DblLink.h

   This program will test the DblLink.h file by allowing the
   user to insert and remove nodes from a doubly linked list
   and print the contents forwards and backwards.
*/
/*
    Author:          Julia Moran
    Major:           Computer Science
    Creation Date:   October 13th, 2022
    Due Date:        October 25th, 2022
    Course:          CSC237 010
    Professor Name:  Dr. Spiegel
    Assignment:      #2
    Filename:        testLL.cpp
    Purpose:         This program will test the DblLink.h file by allowing the
                     user to insert and remove nodes from a doubly linked list
                     and print the contents forwards and backwards.
*/

#include <iostream>
#include <stdlib.h>
#include "DblLink.h"

//Function Prototypes
int testMenu();
void choiceSwitch(int, DblLink<int>&);
void addToList(DblLink<int>&);
void removeFromList(DblLink<int>&);
void printForward(const DblLink<int>&);
void printBackward(const DblLink<int>&);

int main()
{
    //Variables
    DblLink<int> list; //doubly linked list
    int choice = 0; //choice from the user

    //Print the avaliable options to the user
    choice = testMenu();

    //Switch on the user's choice to perform the correct action
    choiceSwitch(choice, list);

    return 0;
}//end main

//Function Name: testMenu
/*!
    \brief Prints options on list
    \n The function menu gets the user's choice, which is either to insert a
       node, remove one, print the contents forwards, print the contents
       backwards, or exit.
    \param N/A
    \return choice The user's choice out of the menu options (int).
*/
int testMenu()
{
    int choice = 0;

    //Print the avaliable options
    cout << "1: Insert" << endl;
    cout << "2: Remove" << endl;
    cout << "3: Print Forward" << endl;
    cout << "4: Print Backward" << endl;
    cout << "5: Exit" << endl;
    cout << "> ";

    //Get the user's choice
    cin >> choice;

    return choice;
}//end function menu

//Function Name: choiceSwitch
/*!
    \brief Switches on choice of action
    \n The choiceSwitch function calls the appropriate function based on the 
       user's choice of action
    \param choice The user's choice out of the menu options (int).
    \param list A doubly linked list of integers (DblLink<int>).
    \return N/A
*/
void choiceSwitch(int choice, DblLink<int>&list)
{
    while(choice != 5)
    {
        switch(choice)
        {
            //Insert a new integer to the list
            case 1:
                addToList(list);
            break;
            //Remove an integer from the list
            case 2:
                removeFromList(list);
            break;
            //Print the list's contents forwards
            case 3:
                printForward(list);
            break;
            //Print the list's contents backwards
            case 4:
                printBackward(list);
            break;
            //Case of invalid input
            default:
                cout << "\nI cannot understand " << choice <<
                    ". Please try again." << endl << endl;
            break;
        }//end switch

        //Get the next user's choice
        choice = testMenu();
    }//end while

    //Print out exit message
    cout << "Goodbye" << endl;
    exit(0);
}//end function choiceSwitch

//Function Name: addToList
/*!
    \brief Insert a number to the list
    \n The function addToList adds a user-inputted integer to the list in
       ascending order.
    \param list A doubly linked list of integers (DblLink<int>).
    \return N/A
*/
void addToList(DblLink<int>& list)
{
    int numToAdd; //number that will be added to the list

    //Get the number to add to the list
    cout << "\nEnter a number to add to the list: ";
    cin >> numToAdd;

    //Insert the inputted number
    list.insert(numToAdd);

    //Output the added number
    cout << numToAdd << " added\n" << endl;
}//end addToList

//Function Name: removeFromList
/*!
    \brief Removes a number from the list
    \n The function removeFromList removes an inputted number from the list if
       it is part of the list.
    \param list A doubly linked list of integers (DblLink<int>).
    \return N/A
*/
void removeFromList(DblLink<int>&list)
{
    //Variables
    DblLinkItr<int> itr(list); //iterator to traverse the doubly linked list
    int numToRemove; //number to remove from the list
    bool found; //set if the number the user wants to remove was found in the list

    //Check if the list is empty
    if(itr.isEmpty() == false)
    {
        //Get the number to remove
        cout << "\nEnter a number to remove from the list: ";
        cin >> numToRemove;

        //Remove the number if it is part of the list
        if(list.remove(numToRemove) == true)
        {
            cout << numToRemove << " removed\n" << endl;
        }//end if
        //Print a message to the user if the number is not part of the list
        else
        {
            cout << numToRemove << " not found\n" << endl;
        }//end else
    }//end if
    //Print a message if the user attempts to remove from an empty list
    else
    {
        cout << "\nCan't remove from an empty list.\n" << endl;
    }//end else
}//end function removeFromList

//Function Name: printForward
/*!
    \brief Print in ascending order
    \n The function printForward prints the contents of the list from lowest
       number to the highest.
    \param list A doubly linked list of integers (DblLink<int>);
    \return N/A
*/
void printForward(const DblLink<int>&list)
{
    DblLinkItr<int> itr(list); //iterator to traverse the doubly linked list

    //Check if the list is empty
    if(itr.isEmpty() == false)
    {
        cout << "\n";

        //Traverse the list to print each number in the list
        for(itr.start(); itr.isLastNode() == false; ++itr)
        {
            cout << *itr << " ";
        }//end for loop

        //Print the last number in the list
        cout << *itr << endl << endl;
    }//end if
}//end function printForward

//Function Name: printBackward
/*!
    \brief Print the numbers in descending order
    \n The function printBackward. The contents of the list from the highest
       number to the smallest.
    \param list A doubly linked list of integers (DblLink<int>).
    \return N/A
*/
void printBackward(const DblLink<int>&list)
{
    DblLinkItr<int> itr(list); //iterator to traverse the doubly linked list

    //Check if the list is empty
    if(itr.isEmpty() == false)
    {
        cout << "\n";

        //Traverse the list to get to the last node
        for(itr.start(); itr.isLastNode() == false; ++itr);

        //Traverse the list backwards to print each number
        for(; itr.isFirstNode() == false; --itr)
        {
            cout << *itr << " ";
        }//end for loop

        //Print the first number in the list
        cout << *itr << endl << endl;
    }//end if
}//end printBackward
