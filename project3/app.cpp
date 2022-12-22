/*!
\file app.cpp
\brief Driver program for the Term classes

   This program will read in a file with numbers respresenting the coefficients
   and exponents of polynomial. It will then store the data in an array
   of objects, a doubly linked list, or a vector depending on the user's
   input and print the information in the method the user chooses. It will
   finally accept a number as x from the user to compute P(x).
*/
/*
    Author:         Julia Moran
    Major:          Computer Science
    Creation Date:  October 16, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 010
    Professor Name: Dr. Speigel
    Assignment:     #3
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
#include <chrono>
#include <vector>
#include "TermSTLObjList.h"
#include "TermDblLinkList.h"
#include "TermArrayList.h"
#include "Term.h"
#include "TermList.h"

using namespace std;
using namespace std::chrono;

//Function Prototypes
void batchMode(ifstream&, int, char**, TermList*);
void printBatchMode(string, double, TermList*, bool);
void openFile(ifstream&, string&);
int menu();
int secondMenu(int);
void choiceSwitch(ifstream&, int, int, string&);
double getXValue();
void printAnswer(double, double);
void printOption(int, string&, TermList*, bool);

int main(int argc, char **argv)
{
    //Variables
    ifstream ifs; //input file stream
    string filename; //name of the file
    int choice = 0; //first choice from the user
    int secondChoice = 0; //second choice from the user
    TermList* ThePoly; //pointer to the polynomial, a TermList object

    //Enter batch mode if the user enters three arguments
    if(argc == 3)
    {
        batchMode(ifs, argc, argv, ThePoly);
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

//Function Name: batchMode
/*!
    \brief Runs the program in batch mode
    \n The function batchMode calls the function to print all the possible
       options for the array, vector, and doubly linked list at once if batch
       mode is entered.
    \param ifs Input file stream (ifstream).
    \param argc The number of commend line arguments the user inputs (int).
    \param argv The array of arguments the user inputs (char**).
    \param ThePoly A pointer to a TermList object that allows for
                   polymorphism (*TermList).
    \return N/A
*/
void batchMode(ifstream& ifs, int argc, char **argv, TermList *ThePoly)
{
    //Initialize the filename and x value variables to the user's inputs
    string filename = argv[1];
    double xVal = atof(argv[2]);

    //Open the file
    ifs.open(filename);

    //Array List Options
    ThePoly = new TermArrayList();
    printBatchMode(filename, xVal, ThePoly, true);

    //Vector Options
    ThePoly = new TermSTLObjList();
    printBatchMode(filename, xVal, ThePoly, false);

    //Doubly Linked List Options
    ThePoly = new TermDblLinkList();
    printBatchMode(filename, xVal, ThePoly, false);

    //Close the file
    ifs.close();
}//end function batchMode

//Function Name: printBatchMode
/*!
    \brief Prints all options in batch mode
    \n The function printbatchMode prints all the possible options for the
       array, vector, and doubly linked list at once if batch mode is entered.
    \param filename The name of the file to read from (string).
    \param xVal The value of x to plug in the polynomial (double).
    \param ThePoly Pointer to a TermList object, used to utilize polymorphism (TermList*).
    \param isArray A boolean value that indicates if the data structure to
                   operate on is an array.
    \return N/A
*/
void printBatchMode(string filename, double xVal, TermList* ThePoly, bool isArray)
{
    //Variables
    double answer = 0.0;
    auto begin = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);

    //Read the data from the file to the data container
    ThePoly->readIntoList(filename);

    //Print the data iteratively
    begin = high_resolution_clock::now();
//    ThePoly->printRecursively();
    ThePoly->printIteratively();
    end = high_resolution_clock::now();

    ticks = duration_cast<microseconds>(end-begin); //Time the print iteratively
    cout << "Time to perform this action: " << ticks.count() << " microseconds.\n";

    //Print the data recursively
    begin = high_resolution_clock::now();
//    ThePoly->printIteratively();
    ThePoly->printRecursively();
    end = high_resolution_clock::now();

    ticks = duration_cast<microseconds>(end-begin); //Time the print recursively
    cout << "Time to perform this action: " << ticks.count() << " microseconds.\n";

    //Prints the pointer option if the data container is an array
    if(isArray == true)
    {
        begin = high_resolution_clock::now();
        ThePoly->printPtr();
        end = high_resolution_clock::now();

        ticks = duration_cast<microseconds>(end-begin); //Time the print with a pointer
        cout << "Time to perform this action: " << ticks.count() << " microseconds.\n";
    }//end if

    //Print the evaluated polynomial
    answer = (*ThePoly)(xVal);
    printAnswer(xVal, answer);
}//end function printBatchMode

//Function Name: openFile
/*!
    \brief Opens the file
    \n The function openFile attempts to open the file with the name supplied
       by the user and exits if the file fails to open.
    \param file The input file stream (ifstream).
    \param filename The name of the file the user supplies (string).
    \return N/A
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

/*!
    \fn menu
    \brief Gets first action
    \n The function main prints the possible containers to store the data in
       and gets user's choice out of those options.
    \param N/A
    \return choice The number the user inputs to decide the data
                   structure to use for printing or evaluating or
                   to exit the program (int).
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

//Function Name: secondMenu
/*!
    \brief Gets the second choice
    \n The function secondMenu prints the possible options for the chosen data
       structure and gets the user's choice of action on the data structure.
    \param choice The first choice from the first menu that
                  indicates the data structure to use or to exit (int).
    \return secondChoice The second choice that indicates whether to
                         print, evaluate the polynomial, or exit (int).
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
        cout << "2. Object Array Recursive Print" << endl;
        cout << "3. Object Array Pointer Print" << endl;
        cout << "4. Evaluate the Polynomial" << endl;
        cout << "5: Exit Object Array" << endl;
    }//end if
    //If STL Object is chosen, show STL Object options
    else if(choice == 2)
    {
        cout << "------------------------------------------------" << endl;
        cout << "STL Object" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "1. STL Object Iterative Print" << endl;
        cout << "2. STL Object Recursive Print" << endl;
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
        cout << "2. Doubly Linked List Recursive Print" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4. Exit Doubly Linked List" << endl;
    }//end else if

    //Get the second choice from the user
    cout << "> ";
    cin >> secondChoice;

    return secondChoice;
}//end function secondMenu

//Function Name: choiceSwitch
/*!
    \brief Switches on chosen data structure
    \n The function choiceSwitch points the TermList object to the chosen data
       structure and calls the function to perform the chosen action on that
       data structure.
    \param ifs The input file stream (ifstream).
    \param choice The first choice from the user to indicate the
                      data structure to use (int).
    \param secondChoice The second choice from the user to
                        indicate whether to print, evaluate,
                        or exit from the data structure (int).
    \param filename The name of the file the user supplies (string).
    \return N/A
*/
void choiceSwitch(ifstream& ifs, int choice, int secondChoice, string& filename)
{
    TermList* ThePoly; //Pointer to TermList object, allows for polymorphism

    while(choice != 4)
    {
        switch(choice)
        {
            //Object Array Option
            case 1:
                //Get the user's second choice for the array
                secondChoice = secondMenu(choice);

                while(secondChoice != 5)
                {
                    //Point the polynomial at the array container
                    ThePoly = new TermArrayList();

                    //Run the chosen action on the array
                    printOption(secondChoice, filename, ThePoly, true);

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
                    //Point the polynomial at the vector container
                    ThePoly = new TermSTLObjList();

                    //Run the chosen action on the vector
                    printOption(secondChoice, filename, ThePoly, false);

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
                    //Point the polynomial at the doubly linked list container
                    ThePoly = new TermDblLinkList();

                    //Run the chosen action on the doubly linked list
                    printOption(secondChoice, filename, ThePoly, false);

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

/*!
    \fn getXValue
    \brief Gets the x value
    \n The function getXValue prompts for and gets the value for x to evaluate
       the polynomial with from the user.
    \param N/A
    \return xToEvaluate The x value to evaluate the polynomial with (double).
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

//Function Name: printAnswer
/*!
    \brief Prints answer after evaluation
    \n The function printAnswer prints the answer after the polynomial is
       evaluated using the x value inputted by the user.
    \param xToEvaluate The x value from the user (double).
    \param answer The result when the x value is plugged into P(x) (double).
    \return N/A
*/
void printAnswer(double xToEvaluate, double answer)
{
    cout << "Evaluated: P(" << xToEvaluate << ") = " << answer << endl << endl;
}//end function printAnswer

//Function Name: printOption
/*!
    \brief Performs the chosen action on the chosen data structure
    \n The function printOption performs the action chosen by the user out of
       the avaliable options for each data structure, which is to either print
       iteratively, print recursively, evaluate the polynomial, exit or print
       using a pointer for the array option.
    \param secondChoice The second choice from the user, indicates whether to
                        print the contents of the vector iteratively or
                        recursively or with a pointer for the array option,
                        evaluate the polynomial, or exit (int).
    \param filename The name of the file to read from (string).
    \param ThePoly Pointer to a TermList object, allows for polymorphism (TermList*).
    \param isArray Boolean value to indicate if the chosen data structure is an array
                   (bool).
    \return N/A
*/
void printOption(int secondChoice, string& filename, TermList* ThePoly, bool isArray)
{
    //Variables
    double answer = 0.0;
    double xToEvaluate = 0.0;
    auto begin = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto ticks = duration_cast<microseconds>(end-begin);

    //Read the contents of the file
    ThePoly->readIntoList(filename);

    //Print the data iteratively
    if(secondChoice == 1)
    {
        begin = high_resolution_clock::now();
        ThePoly->printIteratively();
        end = high_resolution_clock::now();

        ticks = duration_cast<microseconds>(end-begin); //Time the action
        //Print the time to perform the printIteratively
        cout << "Time to perform this action: " << ticks.count() << " microseconds.\n";
    }//end if

    //Print the data recursively
    else if(secondChoice == 2)
    {
        begin = high_resolution_clock::now();
        ThePoly->printRecursively();
        end = high_resolution_clock::now();

        ticks = duration_cast<microseconds>(end-begin); //Time the action
        //Print the time to perform the printRecursively
        cout << "Time to perform this action: " << ticks.count() << " microseconds.\n";
    }//end else if

    //Print the data with a pointer if it is an array
    else if((secondChoice == 3) && (isArray == true))
    {
        begin = high_resolution_clock::now();
        ThePoly->printPtr();
        end = high_resolution_clock::now();

        ticks = duration_cast<microseconds>(end-begin); //Time the action
        //Print the time to perform the printPtr
        cout << "Time to perform this action: " << ticks.count() << " microseconds.\n";
    }//end else if

    //Evaulate the polynomial
    else if(((secondChoice == 3) && (isArray != true)) || ((secondChoice == 4) && (isArray == true)))
    {
        xToEvaluate = getXValue(); //Get the value of x from the user
        answer = (*ThePoly)(xToEvaluate); //Plug in the x value to the polynomial

        //Print the result after plugging in the value of x to the polynomial
        printAnswer(xToEvaluate, answer);
    }//end else if

    //Exit
    else if(((secondChoice == 4) && (isArray != true)) || ((secondChoice == 5) && (isArray == true)))
    {
    }//end else if

    //Invalid input
    else
    {
        cout << "I cannot understand " << secondChoice << ".  Try again" << endl;
    }//end else
}//end function printOption
