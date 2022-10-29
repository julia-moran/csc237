/*
    Author:         Julia Moran
    Creation Date:  September 15, 2022
    Due Date:       September 22, 2022
    Course:         CSC 237
    Professor Name: Dr. Spiegel
    Assignment:     #1
    Filename:       p1.cpp
    Purpose:        This program will open a file with numbers representing the
                    coefficients and exponents of a polynomial. It will then store
                    the data in parallel arrays, an array of objects, or a vector
                    depending on the user's input and print the information in the
                    method the user chooses. It will finally accept a number as x
                    from the user to compute P(x).
*/

//Sources Cited:
/*
    Author:         Dr. Spiegel
    Filename:       Term.cpp
    Retrieved Date: September 15, 2022
    Retrieved from: https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project1/term.cpp
    Note:           The code to print out the parallel arrays' terms was based
                    off of the operator << defined in Dr. Spiegel's Term.cpp
                    file.

    Author:         Dr. Spiegel
    Filename:       showArgs.cpp
    Retrieved Date: September 21, 2022
    Retrieved from: Dr. Spiegel's acad public directory at spiegel/public/cis237/Projects/Project1/showArgs.cpp
    Note:           The code to allow for batch mode was based off of Dr. Spiegel's
                    showArgs.cpp file in the public directory for cis237
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include "term.h"
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

//Function prototypes for all data structures
void openFile(ifstream&, string&);
int menu();
void choiceSwitch(int, ifstream&);
double getXValue();
void printAnswer(int, double, ifstream&, vector<Term>&);

//Prototypes for Parallel Array Functions
void readParallelArrays(ifstream&, double[10], int[10]);
void printParallelIterative(double coefficientArray[10], int exponentArray[10]);
void printParallelRecursive(double coefficientArray[10], int exponentArray[10], int);
double xToParallelArrays(double, double coefficientArray[], int exponentArray[]);

//Prototypes for Object Array Functions
void readToObject(ifstream&, const Term& objectTerm, Term arrayObjects[]);
void printArrayIteration(Term arrayObjects[]);
void printArrayPointers(Term arrayObjects[]);
void printArrayRecursive(Term arrayObjects[], int);
double xToArrayObjects(double, Term arrayObjects[]);

//Prototypes for Vector Functions
void readToVector(ifstream&, const Term& objectTerm, vector<Term>&);
void printVectorForLoop(vector<Term>&);
void printVectorIterator(vector<Term>&);
double xToVector(double, vector<Term>&);

int main(int argc, char **argv)
{
    //Variables
    ifstream ifs;
    string filename;
    int choice;
    double answer;
    Term objectTerm;
    Term arrayObjects[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    double coefficientArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int exponentArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<Term> vectorTerms;
    double xVal;

    /*Citation Source: This code was based off of Dr. Spiegel's code
    in the showArgs.cpp file, retrieved September 21 from
    spiegel/public/cis237/Projects/Project1/showArgs.cpp */
//    printf("There are %d command-line arguments:\n", argc);
    for (int idx = 0; idx < argc; idx++);
//        printf("%d: %s\n", idx, argv[idx]);

    //Allows to run the program in batch mode
    if(argc == 3)
    {
        //Set the arguments to the filename and x value
        filename = argv[1];
        xVal = atof(argv[2]);

        //Open the file
        ifs.open(filename);

        //Read to parallel arrays
        readParallelArrays(ifs, coefficientArray, exponentArray);

        //Parallel Arrays Iterative Option
        printParallelIterative(coefficientArray, exponentArray);
        answer = xToParallelArrays(xVal, coefficientArray, exponentArray);
        printAnswer(xVal, answer, ifs, vectorTerms);

        //Parallel Arrays Recursive Option
        printParallelRecursive(coefficientArray, exponentArray, i);
        answer = xToParallelArrays(xVal, coefficientArray, exponentArray);
        printAnswer(xVal, answer, ifs, vectorTerms);

        //Read to object array
        readToObject(ifs, objectTerm, arrayObjects);

        //Object Array Iteration Option
        printArrayIteration(arrayObjects);
        answer = xToArrayObjects(xVal, arrayObjects);
        printAnswer(xVal, answer, ifs, vectorTerms);

        //Object Array Pointer Option
        printArrayPointers(arrayObjects);
        answer = xToArrayObjects(xVal, arrayObjects);
        printAnswer(xVal, answer, ifs, vectorTerms);

        //Object Array Recursive Option
        printArrayRecursive(arrayObjects, i);
        answer = xToArrayObjects(xVal, arrayObjects);
        printAnswer(xVal, answer, ifs, vectorTerms);

        //Vector For Loop Option
        readToVector(ifs, objectTerm, vectorTerms);
        printVectorForLoop(vectorTerms);
        answer = xToVector(xVal, vectorTerms);
        printAnswer(xVal, answer, ifs, vectorTerms);

        vectorTerms.clear();
        vector<Term> vectorTermsIterator;

        //Vector Iterator Option
        readToVector(ifs, objectTerm, vectorTermsIterator);
        printVectorIterator(vectorTermsIterator);
        answer = xToVector(xVal, vectorTermsIterator);
        printAnswer(xVal, answer, ifs, vectorTermsIterator);
    }//end if
    //Run the program without batch mode
    else
    {
        //Open the file
        openFile(ifs, filename);

        //Have the user choose the print method
        choice = menu();
        choiceSwitch(choice, ifs);
    }//end else

    //Close the file
    ifs.close();
    return 0;
}//end main

/*
    Function Name:  openFile
    Description:    Attempts to open the file with the name supplied by the user
    Parameters:     ifstream - file: input file stream
                    string - filename: name of the file the user supplies
    Return Value:   N/A
*/
void openFile(ifstream& file, string& filename)
{
    bool fileOpen = false;

    //Get the filename from the user
    cout << "Enter the name of the input file: ";
    cin >> filename;

    file.open(filename);

     //Display error message and exit if the file fails to open
    if(file.fail())
    {
        cout << "Error: Can't open file.\n" << endl;
        exit(0);
    }//end if
}//end function openFIle

/*
    Function Name:  menu
    Description:    Prints the menu options and gets the user's choice
    Parameters:     N/A
    Return Value:   int - choice: the user's choice from the menu options
*/
int menu()
{
    int choice = 0;

    while(choice > 8 || choice < 1)
    {
        //Display the menu options
        cout << "\nPlease select one of the following options:" << endl;
        cout << "1: Parallel Iterative" << endl;
        cout << "2: Parallel Recursize" << endl;
        cout << "3: Object Array Iterative" << endl;
        cout << "4: Object Array Pointer" << endl;
        cout << "5: Object Array Recursive" << endl;
        cout << "6: STL SEQ Object For Loop" << endl;
        cout << "7: STL SEQ Object Iterator" << endl;
        cout << "8: Quit" << endl;

        //Get the user's choice
        cin >> choice;

        if(choice > 8 || choice < 1)
        {
            cout << "Invalid input. Please select a valid number." << endl;
        }//end if
    }//end while

    return choice;
}//end function menu

/*
    Function Name:  choiceSwitch
    Description:    Switches on the user's choice to call appropriate functions
    Parameters:     int - choice: the user's choice
                    ifstream - ifs: input file stream
    Return Value:   N/A
*/
void choiceSwitch(int choice, ifstream& ifs)
{
    //Variables
    double xVal;
    double answer;
    Term objectTerm;
    Term arrayObjects[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    double coefficientArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int exponentArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<Term> vectorTerms;

    while(choice != 8)
    {
        //Reset the arrays and vector each time a choice is selected
        Term arrayObjects[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        double coefficientArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int exponentArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vectorTerms.clear();

        switch(choice)
        {
            //Case of parallel arrays printed with iteration
            case 1:
                readParallelArrays(ifs, coefficientArray, exponentArray);
                printParallelIterative(coefficientArray, exponentArray);
                xVal = getXValue();
                answer = xToParallelArrays(xVal, coefficientArray, exponentArray);
                printAnswer(xVal, answer, ifs, vectorTerms);
            break;

            //Case of parallel arrays printed with recursion
            case 2:
                readParallelArrays(ifs, coefficientArray, exponentArray);
                printParallelRecursive(coefficientArray, exponentArray, i);
                xVal = getXValue();
                answer = xToParallelArrays(xVal, coefficientArray, exponentArray);
                printAnswer(xVal, answer, ifs, vectorTerms);
           break;

            //Case of object array printed with iteration
            case 3:
                readToObject(ifs, objectTerm, arrayObjects);
                printArrayIteration(arrayObjects);
                xVal = getXValue();
                answer = xToArrayObjects(xVal, arrayObjects);
                printAnswer(xVal, answer, ifs, vectorTerms);
            break;

            //Case of object array printed with pointers
            case 4:
                readToObject(ifs, objectTerm, arrayObjects);
                printArrayPointers(arrayObjects);
                xVal = getXValue();
                answer = xToArrayObjects(xVal, arrayObjects);
                printAnswer(xVal, answer, ifs, vectorTerms);
            break;

            //Case of object array printed with recursion
            case 5:
                readToObject(ifs, objectTerm, arrayObjects);
                printArrayRecursive(arrayObjects, i);
                xVal = getXValue();
                answer = xToArrayObjects(xVal, arrayObjects);
                printAnswer(xVal, answer, ifs, vectorTerms);
            break;

            //Case of vector printed with a for loop
            case 6:
                readToVector(ifs, objectTerm, vectorTerms);
                printVectorForLoop(vectorTerms);
                xVal = getXValue();
                answer = xToVector(xVal, vectorTerms);
                printAnswer(xVal, answer, ifs, vectorTerms);
            break;

            //Case of vector printed with a iterator
            case 7:
                readToVector(ifs, objectTerm, vectorTerms);
                printVectorIterator(vectorTerms);
                xVal = getXValue();
                answer = xToVector(xVal, vectorTerms);
                printAnswer(xVal, answer, ifs, vectorTerms);
            break;
        }//end switch

        choice = menu();
    }//end while
}//end function choiceSwitch

/*
    Function Name:  getXValue
    Description:    Gets the value of x from the user
    Parameters:     N/A
    Return Value:   double - xVal: the value of x the user inputs
*/
double getXValue()
{
    double xVal;

    //Get the value of x
    cout << "\nEnter the value of x: ";
    cin >> xVal;

    cout << "\nValue of x: " << xVal << endl;

    return xVal;
}//end function getXValue

/*
    Function Name:  printAnswer
    Description:    Prints the final answer for P(x)
    Parameters:     int - xVal: the user inputed x value
                    double - answer: the answer for P(x)
                    ifstream - ifs: input file stream
                    vector<Term> - vectorTerms: vector of object terms
    Return Value:   N/A
*/
void printAnswer(int xVal, double answer, ifstream& ifs, vector<Term>& vectorTerms)
{
    //Print the answer
    cout << "\nP(" << xVal << ") = " << answer << endl;

    //Clear and rewind the file to allow to read from it again
    ifs.clear();
    ifs.seekg(0, ios::beg);

    //Clear the vector
    vectorTerms.clear();

}//end function printAnswer


/////////////////////PARALLEL ARRAYS FUNCTIONS///////////////////////////////////
/*
    Function Name:  readParallelArrays
    Description:    Reads the file into two parallel arrays
    Parameters:     ifstream - ifs: input file stream
                    double - coefficientArray[]: array of coefficients
                    int - exponentArray[]: array of exponents
    Return Value:   N/A
*/
void readParallelArrays(ifstream& ifs, double coefficientArray[10], int exponentArray[10])
{
    //Variables
    double coefficient;
    int exponent;
    double tempCoefficient;
    int tempExponent;
    int currentSize = 0;
    bool spotFound = false;
    bool equivalent = false;
    int spotToInsert;

    //Read the first term to the arrays
    ifs >> coefficient >> exponent;
    coefficientArray[0] = coefficient;
    exponentArray[0] = exponent;
    currentSize++;

    //Read the rest of the terms to the arrays
    while(ifs >> coefficient >> exponent)
    {
        for(int i = 0; i < currentSize; i++)
        {
            //Check if there is a duplicate in the arrays for the term coming in
            if(currentSize < 10 && exponent == exponentArray[i] && spotFound == false)
            {
                //Create temp value to overwrite the current term
                tempExponent = exponent;
                tempCoefficient = coefficientArray[i] + coefficient;

                //Override the current term with a combined value of the term coming in and the current term
                exponentArray[i] = tempExponent;
                coefficientArray[i] = tempCoefficient;

                equivalent = true;
                break;
            }//end if

            //Check if the current exponent is less than the exponent coming in
            if(currentSize < 10 && exponent > exponentArray[i] && spotFound == false)
            {
                spotToInsert = i;

                //Push all the current terms in the arrays up one index
                for(int idx = currentSize; idx > spotToInsert; idx--)
                {
                    exponentArray[idx] = exponentArray[idx-1];
                    coefficientArray[idx] = coefficientArray[idx-1];
                }//end for

                //Insert the term coming in after the other terms are pushed
                exponentArray[spotToInsert] = exponent;
                coefficientArray[spotToInsert] = coefficient;

                currentSize++;
                spotFound = true;
            }//end if
        }//end for

        //Insert the term coming in at the end of the array if no match or spot was found
        if(spotFound == false && equivalent == false)
        {
            exponentArray[currentSize] = exponent;
            coefficientArray[currentSize] = coefficient;
            currentSize++;
        }//end if

        spotFound = false;
        equivalent = false;
    }//end while
}//end function readParallelArrays

/*
    Function Name:  printParallelIterative
    Desscription:   Prints the parallel arrays with iteration
    Parameters:     double - coefficientArray[]: array of coefficients
                    int - exponentArray[]: array of exponents
    Return Value:   N/A
*/
void printParallelIterative(double coefficientArray[], int exponentArray[])
{
    bool firstPrinted = false;

    for(int i = 0; i < 10; i++)
    {
        //Print the print option and first term
        if((coefficientArray[i] != 0) && (firstPrinted == false))
        {
            cout << "\nParallel Iterative" << endl;
            cout << "Equation: ";

            /*Citation Source: This code was based off of Dr. Spiegel's code
            in the term.cpp file, retrieved September 15 from
            https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project1/term.cpp*/

            //Prints coefficients not equal to 1
            if(coefficientArray[i] != 1)
                cout << coefficientArray[i];
            //Prints terms with an exponent of 0 as 1
            else if(exponentArray[i] == 0)
                cout << 1;

            //Prints terms with an exponent of 1 without the exponent
            if(exponentArray[i] == 1)
                cout << "x";
            //Prints the exponent if it is greater than 1
            else if(exponentArray[i] > 1)
                cout << "x^" << exponentArray[i];

            firstPrinted = true;
        }//end if

        //Print the remaining terms with a plus sign in front
        else if((coefficientArray[i] != 0) && (firstPrinted == true))
        {
            cout << " + ";

            /*Citation Source: This code was based off of Dr. Spiegel's code
            in the term.cpp file, retrieved September 15 from
            https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project1/term.cpp*/

            //Prints coefficients not equal to 1
            if(coefficientArray[i] != 1)
                cout << coefficientArray[i];
            //Prints terms with an exponent of 0 as 1
            else if(exponentArray[i] == 0)
                cout << 1;

            //Prints terms with an exponent of 1 without the exponent
            if(exponentArray[i] == 1)
                cout << "x";
            //Prints the exponent if it is greater than 1
            else if(exponentArray[i] > 1)
                cout << "x^" << exponentArray[i];
        }//end else if
   }//end for loop
}//end function printParallelIterative

/*
    Function Name:  printParallelRecursive
    Description:    Prints the parallel arrays recursively
    Parameters:     double - coefficientArray[]: array of coefficients
                    int - exponentArray[]: array of exponents
                    int - i: current index the function is at
    Return Value:   N/A
*/
void printParallelRecursive(double coefficientArray[], int exponentArray[], int i)
{
    //Prints the option type before the first term
    if(i == 0)
    {
        cout << "\nParallel Recursive" << endl;
        cout << "Equation: ";
    }//end if

    //Base Case - return when at the end of the arrays, prints last term in arrays
    if(coefficientArray[i + 1] == 0 || i == 9)
    {
        /*Citation Source: This code was based off of Dr. Spiegel's code
        in the term.cpp file, retrieved September 15 from
        https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project1/term.cpp*/

        //Prints coefficients not equal to 1
        if(coefficientArray[i] != 1)
            cout << coefficientArray[i];
        //Prints terms with an exponent of 0 as 1
        else if(exponentArray[i] == 0)
            cout << 1;

        //Prints terms with an exponent of 1 without the exponent
        if(exponentArray[i] == 1)
            cout << "x";
        //Prints the exponent if it is greater than 1
        else if(exponentArray[i] > 1)
            cout << "x^" << exponentArray[i];

        return;
    }//end if

    //Recursive Step - prints all but the last term in the arrays with a plus sign in front
    else
    {
        /*Citation Source: This code was based off of Dr. Spiegel's code
        in the term.cpp file, retrieved September 15 from
        https://faculty.kutztown.edu/spiegel/CSc237/Projects/Project1/term.cpp*/

        //Prints coefficients not equal to 1
        if(coefficientArray[i] != 1)
            cout << coefficientArray[i];
        //Prints terms with an exponent of 0 as 1
        else if(exponentArray[i] == 0)
            cout << 1;

        //Prints terms with an exponent of 1 without the exponent
        if(exponentArray[i] == 1)
            cout << "x";
        //Prints the exponent if it is greater than 1
        else if(exponentArray[i] > 1)
            cout << "x^" << exponentArray[i];

        cout << " + ";

        i++;
        printParallelRecursive(coefficientArray, exponentArray, i);
    }//end else
}//end function printParallelRecursive

/*
    Function Name:  xToParallelArrays
    Description:    Plugs in the x value supplied by the user into the equation and
                    computes the output for the parallel arrays
    Parameters:     double - xVal: x value supplied by user
                    double - coefficientArray[]: array of coefficients
                    int - exponentArray[]: array of exponents
    Return Value:   double - sum: The value of P(x) after x is plugged in
*/
double xToParallelArrays(double xVal, double coefficientArray[], int exponentArray[])
{
    //Variables
    double sum = 0;
    double tempValue;

    for(int i = 0; i < 10; i++)
    {
        //Compute the value of each term when x is plugged in
        tempValue = coefficientArray[i] * (pow(xVal, exponentArray[i]));

        //Add up the terms
        sum = sum + tempValue;
    }//end for loop

    return sum;
}//end function xToParallelArrays


////////////////////////OBJECT ARRAYS FUNCTIONS////////////////////////////////////
/*
    Function Name:  readToObject
    Description:    Read the file into an array of objects of type Term
    Parameters:     ifstream - ifs: input file stream
                    Term - objectTerm: terms read from the file before they
                                       are placed in the array
                    Term - arrayObjects[]: array of objects storing the terms
    Return Value:   N/A
*/
void readToObject(ifstream& ifs, const Term& objectTerm, Term arrayObjects[])
{
    //Variables
    double coefficient;
    int exponent;
    Term valueToPush;
    Term pushedTerm;
    int currentSize = 0;
    bool equivalent = false;
    bool spotFound = false;

    //Read the first term
    ifs >> coefficient >> exponent;
    Term firstTerm(coefficient, exponent);
    arrayObjects[0] = firstTerm;
    currentSize++;

    //Read the remaining terms
    while(ifs >> coefficient >> exponent)
    {
        for(int i = 0; i < currentSize + 1; i++)
        {
            //Find the first term less than the current term and push the current term
            if(arrayObjects[i].getExponent() < exponent || (arrayObjects[i].getCoefficient() == 0 && exponent == 0))
            {
                valueToPush = arrayObjects[i];
                Term objectTerm(coefficient, exponent);

                //Place the term with the greater exponent at the spot of the current term
                arrayObjects[i] = objectTerm;

                //Prepare to push the current term by making it the next term to compare
                exponent = valueToPush.getExponent();
                coefficient = valueToPush.getCoefficient();

                spotFound = true;
                equivalent = false;
            }//end if

            //Combine coefficients if there exists terms with the same exponent
            if((spotFound == false) && (arrayObjects[i].getExponent() == exponent))
            {
                //Overwrite the current object with the combined term
                Term tempValue(arrayObjects[i].getCoefficient() + coefficient, exponent);
                arrayObjects[i] = tempValue;

                equivalent = true;
                break;
            }//end if
         }//end for loop

         //Push the remaining terms if the spot was found
         if(spotFound == true && coefficient != 0)
         {
            Term pushedTerm(exponent, coefficient);
            arrayObjects[currentSize] = pushedTerm;

            currentSize++;
            spotFound = false;
         }//end if
         //Increment the current size once all values are pushed properly after inserting the new term
         else if(spotFound == true && coefficient == 0)
         {
             currentSize++;
             spotFound = false;
        }//end else if
    }//end while
}//end function readToObject

/*
    Function Name:  printArrayIteration
    Description:    Prints the contents of the object array using iteration
    Parameters:     Term - arrayObjects[]: array of objects storing the terms
    Return Value:   N/A
*/
void printArrayIteration(Term arrayObjects[])
{
    bool firstPrinted = false;

    for(int i = 0; i < 10; i++)
    {
        //Print out the first object
        if((arrayObjects[i].getCoefficient() != 0) && (firstPrinted == false))
        {
            cout << "\nObject Array Iterative" << endl;
            cout << "Equation: " << arrayObjects[i];
            firstPrinted = true;
        }//end if

        //Print the remaining objects with a plus sign in front
        else if((arrayObjects[i].getCoefficient() != 0) && (firstPrinted == true))
        {
            cout << " + " << arrayObjects[i];
        }//end else if

    }//end for loop
}//end function printArrayIteration

/*
    Function Name:  printArrayRecursive
    Description:    Prints the contents of the object array recursively
    Parameters:     Term - arrayObjects[]: array of objects storing the terms
                    int - i: current index of function
    Return Value:   N/A
*/
void printArrayRecursive(Term arrayObjects[], int i)
{
    //Print the print option before the first term
    if(i == 0)
    {
        cout << "\nObject Array Recursive" << endl;
        cout << "Equation: ";
    }//end if

    //Base Case - if at the last object in the array, print the object without a plus sign
    if(arrayObjects[i + 1].getCoefficient() == 0 || i == 9)
    {
        cout << arrayObjects[i];
        return;
    }//end if

    //Recursive Step - print out all but the last term with a plus sign in front
    else
    {
        cout << arrayObjects[i] << " + ";
        i++;
        printArrayRecursive(arrayObjects, i);
    }//end else
}//end function printArrayRecursive

/*
    Function Name:  printArrayPointers
    Description:    Prints the array using pointers
    Parameters:     Term - arrayObjects[]: array of objects storing the terms
    Return Value:   N/A
*/
void printArrayPointers(Term arrayObjects[])
{
    Term *pointer = &arrayObjects[0];

    //Print the print option and first object
    cout << "\nObject Array Pointer" << endl;
    cout << "Equation: " << *pointer;
    pointer++;

    //Print the remaining objects with a plus sign in front
    for(int i = 0; (*pointer).getCoefficient() != 0 && i < 10; i++)
    {
        cout << " + " << *pointer;
        pointer++;
    }//end for loop
}//end function printArrayPointers

/*
    Function Name:  xToArrayObjects
    Description:    Plugs the x value supplied by the user into the polynomial and
                    computes the answer
    Parameters:     double - xVal: value of x supplied by the user
                    Term - arrayObjects[]: array of objects storing the terms
    Return Value:   double - sum: the answer P(x) when x is plugged in
*/
double xToArrayObjects(double xVal, Term arrayObjects[])
{
    double sum = 0;

    //Add up the sum of the terms after x is plugged in for each term
    for(int i = 0; i < 10; i++)
    {
        sum = arrayObjects[i](xVal) + sum;
    }//end for loop

    return sum;
}//end function xToArrayObjects


//////////////VECTOR FUNCTIONS/////////////////////////
/*
    Function Name:  readToVector
    Description:    Read the data from the file into a vector
    Parameters:     ifstream - ifs: input file stream
                    Term - objectTerm: object the data is read into before it is
                                       placed in the vector
                    vector<Term> - vectorTerms: vector storing the terms
    Return Value:   N/A
*/
void readToVector(ifstream& ifs, const Term& objectTerm, vector<Term>& vectorTerms)
{
    //Variables
    vector<Term>::iterator it = vectorTerms.begin();
    double coefficient;
    int exponent;
    bool equivalent = false;

    //Read the first term into the vector
    ifs >> coefficient >> exponent;
    Term firstTerm(coefficient, exponent);
    vectorTerms.insert(vectorTerms.begin(), firstTerm);

    //Read in the remaining terms
    while(ifs >> coefficient >> exponent)
    {
        Term objectTerm(coefficient, exponent);
        equivalent = false;

        for (it = vectorTerms.begin(); it != vectorTerms.end() && *it < objectTerm; it++);
            //Check if there exists another term in the vector with the same exponent as the current object
            if(objectTerm == *it)
            {
                //Override the object at the iterator with a term that combines the coefficients of terms with the same exponent
                Term tempTerm(((*it).getCoefficient() + objectTerm.getCoefficient()), objectTerm.getExponent());
                 *it = tempTerm;
                equivalent = true;
            }//end if

            //Insert the next object at the right position if no other terms have the same exponent
            if(equivalent == false)
            {
                vectorTerms.insert(it, objectTerm);
            }//end if
    }//end while loop
}//end function readToVector

/*
    Function Name:  printVectorForLoop
    Description:    Print the contents of the vector using a for loop
    Parameters:     vector<Term> - vectorTerms: vector storing the terms
    Return Value:   N/A
*/
void printVectorForLoop(vector<Term>& vectorTerms)
{
    //Print the print option and the first term
    cout << "\nSTL SEQ Object For Loop (Vector)" << endl;
    cout << "Equation: " << vectorTerms[vectorTerms.size() - 1];

    //Print out the remaining terms with a plus sign in front
    for(int i = vectorTerms.size() - 2; i >= 0; i--)
    {
        cout << " + " << vectorTerms[i];
    }//end for loop

}//end function printVectorForLoop

/*
    Function Name:  printVectorIterator
    Description:    prints the contents of the vector using an iterator
    Parameters:     vector<Term> - vectorTerms: vector storing the terms
    Return Value:   N/A
*/
void printVectorIterator(vector<Term>& vectorTerms)
{
    vector<Term>::iterator it = vectorTerms.end() - 1;

    //Print the print option and the first term
    cout << "\nSTL SEQ Object Iterator (Vector)" << endl;
    cout << "Equation: " << *it;

    //Print out the remaining terms
    for(it = vectorTerms.end() - 2; it >= vectorTerms.begin(); it--)
    {
        cout << " + " << *it;
    }//end for loop

}//end function printVectorIterator

/*
    Function Name:  xToVector
    Description:    Plugs the value supplied by the user and computes the output of
                    the equation for the vector
    Parameters:     double - xVal: value inputted by user
                    vector<Term> - vectorTerms: vector storing the terms
    Return Value:   double - sum: the answer for P(x) when x is plugged in
*/
double xToVector(double xVal, vector<Term>& vectorTerms)
{
    double sum = 0;

    //Add up the terms after the inputted value is plugged in for x
    for(int i = 0; i < vectorTerms.size(); i++)
    {
        sum = vectorTerms[i](xVal) + sum;
    }//end for loop

    return sum;
}//end function xToVector
