/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  October 16, 2022
    Due Date:       October 25, 2022
    Course:         CSC237 010
    Professor Name: Dr. Speigel
    Assignment:     #2
    Filename:       app.cpp
    Purpose:        This program will read in a file with numbers respresenting
                    the coefficients and exponents of polynomial. It will then
                    store the data in an array of objects, a doubly linked list,
                    or a vector depending on the user's input and print the
                    information in the method the user chooses. It will finally
                    accept a number as x from the user to compute P(x).
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "TermSTLObjList.h"
#include "TermDblLinkList.h"
#include "TermArrayList.h"
#include "Term.h"
#include "TermList.h"

//Function Prototypes
void batchMode(ifstream&, int, char**);
void openFile(ifstream&, string&);
int menu();
int secondMenu(int);
void choiceSwitch(ifstream&, int, int, string&);
double getXValue();
void printAnswer(double, double);
void arrayListOption(int, string&);
void vectorOption(int, string&);
void doublyLinkedListOption(int, string&);

int main(int argc, char **argv)
{
    //Variables
    ifstream ifs; //input file stream
    string filename;
    int choice = 0; //first choice from the user
    int secondChoice = 0; //second choice from the user

    //Enter batch mode if the user enters three arguments
    if(argc == 3)
    {
        batchMode(ifs, argc, argv);
    }//end if
    //Otherwise, run the program without batch mode
    else
    {
        openFile(ifs, filename);
        choice = menu();
        choiceSwitch(ifs, choice, secondChoice, filename);
    }//end else

    return 0;
}//end main

/*
    Function Name:  batchMode
    Description:    Prints all the possible options at once if batch mode is
                    entered
    Parameters:     ifstream - ifs: input file stream
                    int - argc: number of commend line arguments the user inputs
                    char** - argv: array of arguments the user inputs
    Return Value:   N/A
*/
void batchMode(ifstream& ifs, int argc, char **argv)
{
    //Initialize the filename and x value variables to the user's inputs
    string filename = argv[1];
    double xVal = atof(argv[2]);

    //Declare remaining variables
    TermArrayList arrayList; //array of objects
    TermSTLObjList vectorTerms; //vector
    TermDblLinkList doublyLinkedList; //doubly linked list
    double answer = 0.0;

    //Open the file
    ifs.open(filename);

    //Array List Options
    arrayList.readIntoList(filename);
    arrayList.printIteratively();
    answer = arrayList(xVal);
    printAnswer(xVal, answer);
    arrayList.printPtr();
    answer = arrayList(xVal);
    printAnswer(xVal, answer);

    //Vector Options
    vectorTerms.readIntoList(filename);
    vectorTerms.printIteratively();
    answer = vectorTerms(xVal);
    printAnswer(xVal, answer);

    //Doubly Linked List Options
    doublyLinkedList.readIntoList(filename);
    doublyLinkedList.printIteratively();
    answer = doublyLinkedList(xVal);
    printAnswer(xVal, answer);

    //Close the file
    ifs.close();
}//end function batchMode

/*
    Function Name:  openFile
    Description:    Attempts to open the file with the name supplied by the user
    Parameters:     ifstream - file: input file stream
                    string - filename: name of the file the user supplies
    Return Value:   N/A
*/
void openFile(ifstream& file, string& filename)
{
    //Get the filename from the user
    cout << "Please enter a file name: ";
    cin >> filename;

    file.open(filename);

    //Display error message and exit if the file fails to open
    if(file.fail())
    {
        cout << "Sorry, the file failed to open.\n" << endl;
        exit(0);
    }//end if
}//end function openFIle

/*
    Function Name:  menu
    Decription:     Gets the first action from the user
    Parameters:     N/A
    Return Value:   int - choice: the number the user inputs to decide the data
                                  structure to use for printing or evaluating or
                                  to exit the program
*/
int menu()
{
    int choice = 0;

    //Print out options
    cout << "\nSelect Term List Type ?" << endl;
    cout << "1. Object Array" << endl;
    cout << "2. STL Object" << endl;
    cout << "3. Doubly Linked List" << endl;
    cout << "4. Exit" << endl;
    cout << "> ";

    //Get the user's choice
    cin >> choice;

    return choice;
}//end function menu

/*
    Function Name:  secondMenu
    Description:    Gets the second choice from the user based on the first
                    choice of data structure
    Parameters:     int - choice: first choice from the first menu that
                                  indicates the data structure to use or to exit
    Return Value:   int - secondChoice: second choice that indicates whether to
                                        print, evaluate the polynomial, or exit
*/
int secondMenu(int choice)
{
    int secondChoice;

    cout << "\nSelect Action ?" << endl;

    //If Object Array is chosen, show Object Array options
    if(choice == 1)
    {
        cout << "------------------------------------------------" << endl;
        cout << "Object C++ Array" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. Object Array Iterative Print" << endl;
        cout << "2. Object Array Pointer Print" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4: Exit Object Array" << endl;
    }//end if
    //If STL Object is chosen, show STL Object options
    else if(choice == 2)
    {
        cout << "------------------------------------------------" << endl;
        cout << "STL Object" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. STL Object Iterative Print" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4. Exit STL Object" << endl;
    }//end else if
    //If Doubly Linked List is chosen, show Doubly Linked List options
    else if(choice == 3)
    {
        cout << "------------------------------------------------" << endl;
        cout << "Doubly Linked List" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. Doubly Linked List Iterative Print" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4. Exit Doubly Linked List" << endl;
    }//end else if

    //Get the second choice from the user
    cout << "> ";
    cin >> secondChoice;

    return secondChoice;
}//end function secondMenu

/*
    Function Name:  choiceSwitch
    Description:    Calls the appropriate function to the options for each data
                    structure
    Parameters:     ifstream - ifs: input file stream
                    int - choice: first choice from the user to indicate the
                                  data structure to use
                    int - secondChoice - second choice from the user to
                                         indicate whether to print, evaluate,
                                         or exit from the data structure
    Return Value:   N/A
*/
void choiceSwitch(ifstream& ifs, int choice, int secondChoice, string& filename)
{
    while(choice != 4)
    {
        switch(choice)
        {
            //Object Array Option
            case 1:
                //Get the user's second choice for the array
                secondChoice = secondMenu(choice);

                while(secondChoice != 4)
                {
                    //Run the chosen action on the array
                    arrayListOption(secondChoice, filename);

                    //Return to the menu for array options
                    secondChoice = secondMenu(choice);
                }//end while
            break;

            //STL Object Option
            case 2:
                //Get the user's second choice for the vector
                secondChoice = secondMenu(choice);

                while(secondChoice != 4)
                {
                    //Run the chosen action on the vector
                    vectorOption(secondChoice, filename);

                    //Return to the menu for STL object options
                    secondChoice = secondMenu(choice);
                }//end while
            break;

            //Doubly Linked List Option
            case 3:
                //Get the user's second choice for the doubly linked list
                secondChoice = secondMenu(choice);

                while(secondChoice != 4)
                {
                    //Run the chosen action on the doubly linked list
                    doublyLinkedListOption(secondChoice, filename);

                    //Return to the menu for doubly linked list options
                    secondChoice = secondMenu(choice);
                }//end while
            break;

            //Case if the input is invalid
            default:
                cout << "I cannot understand " << choice << ".  Try again" << endl;
            break;
        }//end switch
        choice = menu();
    }//end while

    //Print exit message
    cout << "Goodbye" << endl;

    //Close the file
    ifs.close();
}//end function choiceSwitch

/*
    Function Name:  getXValue
    Description:    Gets the value for x to evaluate the polynomial with from
                    the user
    Parameters:     N/A
    Return Value:   double - xToEvaluate: x value to evaluate the polynomial
                                          with
*/
double getXValue()
{
    double xToEvaluate;

    //Get the x value from the user
    cout << "Enter a value x for P(x) > ";
    cin >> xToEvaluate;
    cout << endl;

    return xToEvaluate;
}//end function getXValue

/*
    Function Name:  printAnswer
    Description:    Prints the answer after the polynomial is evaluated using
                    the x value inputted by the user
    Parameters:     double - xToEvaluate: x value from the user
                    double - answer: result when the x value is plugged into
                                     P(x)
    Return Value:   N/A
*/
void printAnswer(double xToEvaluate, double answer)
{
    cout << "Evaluated: P(" << xToEvaluate << ") = " << answer << endl << endl;
}//end function printAnswer

/*
    Function Name:  arrayListOption
    Description:    Calls the appropriate function out of the avaliable options
                    for the array of objects
    Parameters:     int - secondChoice: second choice from the user, indicates
                                        whether to print iteratively, print
                                        with a pointer, evaluate the polynomial,
                                        or exit
                    string - filename: name of the file to read the data from
    Return Value:   N/A
*/
void arrayListOption(int secondChoice, string& filename)
{
    //Variables
    TermArrayList arrayList; //array of Term objects
    double xToEvaluate = 0.0;
    double answer = 0.0;

    //Read the data into an array of objects
    arrayList.readIntoList(filename);

    switch(secondChoice)
    {
        //Case of printing iteratively
        case 1:
            arrayList.printIteratively();
        break;

        //Case of printing using a pointer
        case 2:
            arrayList.printPtr();
        break;

        //Case of evaluating the polynomial
        case 3:
            xToEvaluate = getXValue();
            answer = arrayList(xToEvaluate);
            printAnswer(xToEvaluate, answer);
        break;

        //Case of exiting
        case 4:
        break;

        //Case when the user's input is invalid
        default:
            cout << "I cannot understand " << secondChoice << ".  Try again" << endl;
        break;
    }//end switch
}//end function arrayListOption

/*
    Function Name:  vectorOption
    Description:    Calls the appropriate function out of the avaliable options
                    for the STL container option, which is a vector
    Parameters:     int - secondChoice: second choice from the user, indicates
                                        whether to print the contents of the
                                        vector iteratively, evaluate the
                                        polynomial, or exit
    Return Value:   N/A
*/
void vectorOption(int secondChoice, string& filename)
{
    //Variables
    TermSTLObjList vectorTerms; //vector
    double answer = 0.0;
    double xToEvaluate = 0.0;

    //Read the contents of the file to a vector
    vectorTerms.readIntoList(filename);

    switch(secondChoice)
    {
        //Case of printing the vector's contents iteratively
        case 1:
            vectorTerms.printIteratively();
        break;

        //Case of evaluating the polynomial
        case 3:
            xToEvaluate = getXValue();
            answer = vectorTerms(xToEvaluate);
            printAnswer(xToEvaluate, answer);
        break;

        //Case of exiting
        case 4:
        break;

        //Case when the user's input is invalid
        default:
            cout << "I cannot understand " << secondChoice << ".  Try again" << endl;
        break;
    }//end switch
}//end function vectorOption

/*
    Function Name:  doublyLinkedListOption
    Description:    Calls the appropriate funtion out of the avaliable options
                    for the doubly linked list option
    Parameters:     int - secondChoice: second choice from the user, indicates
                                        whether to print the contents of the
                                        doubly linked list iteratively, evaluate
                                        the polynomial, or exit
                    string - filename: name of the file to read in the data from
    Return Value:   N/A
*/
void doublyLinkedListOption(int secondChoice, string& filename)
{
    //Variables
    TermDblLinkList doublyLinkedList; //dounly linked list
    double xToEvaluate = 0.0;
    double answer = 0.0;

    //Read the data from the file into a doubly linked list
    doublyLinkedList.readIntoList(filename);

    switch(secondChoice)
    {
        //Case of printing the contents iteratively
        case 1:
            doublyLinkedList.printIteratively();
        break;

        //Case of evaluating the polynomial
        case 3:
            xToEvaluate = getXValue();
            answer = doublyLinkedList(xToEvaluate);
            printAnswer(xToEvaluate, answer);
        break;

        //Case of exiting
        case 4:
        break;

        //Case when the user's input is invalid
        default:
            cout << "I cannot understand " << secondChoice << ".  Try again" << endl;
        break;
    }//end switch
}//end function doublyLinkedListOption

