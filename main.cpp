/* --------------------------------------------------------
 * Class: Program #2 for CS 141, Fall 2019
 * Lab: Mon 5am,
 * TA Alan Turing
 * System: Mac OS X
 * Author: Sanket Patel
 */


#include <iostream>
#include <cctype>       // For the letter checking functions
#include <fstream>      // For file input
#include <iomanip>      // For setw
#include <cstdlib>      // For exit and abs
#include <cmath>        // mathematical rounding purpose
using namespace std;


//***Aditi: at the function have comments explaining the parameters of the function along with it's utility
//Stage 1: Random Lines from Trump.txt or Warren.txt (COMMON FUNCTION)
void randomLinesFrom(string candidateName,int linesToDisplay)
{
    // Here is some sample code to open a file, read the number on the first line, and print it.
        ifstream inputFileStream;  // Declare the input file stream
   
    // Open input file and verify that file was found
    inputFileStream.open( candidateName.c_str() );
    if( !inputFileStream.is_open()) {
        cout << "Could not find input file " << candidateName << "  Exiting..." << endl;
        exit( -1);
    }
    // Read the number on the first line of the input file, which indicates how many subsequent
    // lines there are in the file.
    int numberOfLinesInFile = 0;
    inputFileStream >> numberOfLinesInFile; 
    
    // Read one line at a time, repeating until we get to the designated line.  If the designated
    // line is blank or is a comment line starting with '#', then skip it and go on to the next.
    string line;
    char A = '#';   //***Aditi: Use meanigful varaible namespace
    char B = ' ';
    
    for (int x = 0; x < linesToDisplay; x++)//for loop for number of lines to be displayed.
    {
        ifstream inputFileStream;
        inputFileStream.open( candidateName.c_str() ); //Open file again after displaying 1 line.
         
        int rn=rand()%numberOfLinesInFile; // store random number in rn.
        for(int y = 0; y < rn; y++) // To reach at the random number generated.
        {
          getline( inputFileStream, line);
        }//Now we are at required line.
        
        if (line.size() == 0) {
            getline( inputFileStream, line);
            getline( inputFileStream, line);
        }
        else if (line.at(0) == '#') {
            getline( inputFileStream, line);
        }
        cout<<line<<endl;
     
        inputFileStream.close(); //Close file to make the loop runs from beginning.
    }
    cout<<endl;
    
        inputFileStream.close();
}
//***Aditi: Funtion names should be camel case
//-------------------------------------------------------------------------------------------------
void RallyQuiz(int userInput,double &X,double &Total,double &Percent,int linesToDisplay)
{
    int rn = rand()%2; // random valuges either 1 or 0
    
    if(rn==0) // If random number generated is 0 get lines from Trump.txt.
    {
      randomLinesFrom("Trump.txt",linesToDisplay);  
    }
    else  // If random number generated is 1 get lines from Warren.txt.
    {
      randomLinesFrom("Warren.txt",linesToDisplay);  
    }
    
    cout<<"Enter 1 for Trump, 2 for Warren:";
    cin>>userInput;
    cout<<endl;
    
      
     if(userInput==(rn+1)) // rn is going to be 0 or 1 AND userinput is going to be either 1 or 2.
    {                      //So, establishing relation between userInput and rn to check correctness.
        X+=1; // X is number of correct answers.
        Total+=1;
        Percent=(X/Total)*100;
       cout<<"Correct! You got "<<X<<" out of "<<Total<<", which is "<<fixed<<setprecision(0)<<Percent<<"%"<<endl;
    }
    else
    {
        Total+=1;
        Percent=(X/Total)*100;
        cout<<"Wrong! You got "<<X<<" out of "<<Total<<", which is "<<Percent<<"%"<<endl;
    }
    cout<<endl;
    cout<<endl;
}
//-------------------------------------------------------------------------------------------------
int main() {
    
    int menuOption = -1;// User input of menu option
        double userInput,X=0.0,Total=0.0; //X is variable for counting Percent. Total is number of attempts.
    double Percent=0.0;
    int linesToDisplay=3; //By default without any input if menu option 2 or 3 is selected, 3 lines will be displayed.
     
    // Initialize the random number generator
    srand( 1);    // You must leave it as srand( 1) for the version you turn in.
                      // Change this to srand( time(0))  if you want it to be different every time.
                      //cout << "A random value is: " << rand() << endl;


        while (menuOption != 5)
    {
    // Display which program this is and display menu options to select program output to be displayed
        cout << "----  Program 2: Rally Songs  ----\n"
                 << "Select from the following:\n"
                 << "   1. Set number of lines to display\n"
                 << "   2. Get random lines from Trump.txt\n"
                 << "   3. Get random lines from Warren.txt\n"
                 << "   4. Rally song quiz\n"
                 << "   5. Exit the program\n"
                 << "Your choice --> ";
         
           cin >> menuOption;
        cout << endl;
        // Handle menu options
        if( menuOption == 5) {
           
            cout<<"You got "<<X<<" out of "<<Total<<", which is "<<fixed<<setprecision( 0)<<round(Percent)<<"%"<<endl;
            cout<<endl;
            exit(0);      // Break enclosing loop.
        }
        else if(menuOption == 1) {
            cout<<"Enter the number of lines you want to display -> ";
            cin>>linesToDisplay;
            cout<<endl;
                //cout<<"Invalid menu response.  Please retry."<<endl;
        }
        else if(menuOption == 2){
           randomLinesFrom("Trump.txt",linesToDisplay);
        }
        else if(menuOption == 3){
            randomLinesFrom("Warren.txt",linesToDisplay);
        }
        else if (menuOption == 4){
            RallyQuiz(userInput, X,Total,Percent,linesToDisplay);
        }
        else
        {
            cout<<"Invalid menu response.  Please retry."<<endl;
            cout<<endl;
        }
    }
    return 0;
}//end main()
