//Include necessary libraries
//Include necessary header file(s)
//Namespace std

//function prototypes for various necessary parts of program
    //day running function (facilitates changes)
    //helper function for printing formatted data
    //function for tracking trade volume
    //function for tracking stock price
    //function for tracking sector-wide effects

    //function parameters will depend on whether they reference or change fields
        //reference vs value

//define main()
    //initalize a map named something like "notRobinhood" to store data about various sector(s) arrays
        //each sector array associated a list of three companies
    
    //open an external file to read in data about the companies and populate their associated list entries
        //include error handling/messaging
        //close once all data has been sucessfully read in
    
    //begin the time-based for loop simulating a month's market fluctuations
        // 30ish calls to the day running function 
            //for each array (sector)
                //facilitates any sector-wide changes
                //for each list (stock)
                    //facilitates data changes (stock price increase/decreate), (trading volume increase/decrease)
                    //data printing, ex: [Day X: APPL: 231.23, VOLUME: +232,323]
                    //similar printing that announces sector-wide events
                        //could even get crazy and do whole-market effects (in spirit of the recent election)
                
    // pause briefly/add space between messages to maintain readable breakdown

//end main()
    
//function implementation:
    //day running function (facilitates changes)
    //helper function for printing formatted data
    //function for tracking trade volume
    //function for tracking stock price
    //function for tracking sector-wide effects


// COMSC-210 | labs 29-31 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list> // for std::list
#include <array> //for std::array
#include <map>
#include <time.h>
#include <random>
using namespace std;

//function prototypes
void readInData(map<string,array<list<int>,3>>&, string); 
void readIntoList(map<string,array<list<int>,3>>&, string, ifstream &); //helper
void runMonth(map<string,array<list<int>,3>>&app);
void stockPrice(map<string,array<list<int>,3>>&app);
void calcTradeVolume(map<string,array<list<int>,3>>&app);
void marketWide(map<string,array<list<int>,3>>&app);
void printInfo(map<string,array<list<int>,3>>app, int);


const int NUM_STOCKS = 3, DAYS = 30;

int main()
{
    srand(time(0)); 

    map<string,array<list<int>,3>>notRobinhood; 
    //need a way to differentiate lists because each represent a different stock but are currently represented as ints.

    //initialize the key/value pair of two arrays 
    notRobinhood["CommServ"]; 
    notRobinhood["InfoTech"]; 

    //read in data to each of the array nested loops
    readInData(notRobinhood, "Comm.txt"); //string passed to differentiate sectors
    readInData(notRobinhood, "IT.txt"); 

    //program loop
    for(int i = 0; i < DAYS; i++)
    {
        runMonth(notRobinhood);
        printInfo(notRobinhood, i+1); //so days start at one
    }

    return(0);
}

//implementation functions

void readInData(map<string,array<list<int>,3>>&app, string sector) //different sectors each have different text files
{
    ifstream in(sector); //open sector-specific file
    if(!in.good())
    {
        cout << "ERROR OPENING FILE\n"; //no file exists at the moment
    }
    else if(sector == "Comm.txt")
    {
        readIntoList(app, "CommServ", in); //populates each of three lists (lists currently have no way of being differentiated)
    }
    else if(sector == "IT.txt")
    {
        readIntoList(app, "InfoTech", in);
    }
    else
    {
        cout << "Invalid Sector passed.\n";
    }
    in.close(); 
}

void readIntoList(map<string,array<list<int>,3>>&app, string sector, ifstream &in) //helper function
{
    int buf; //stores values to populate map
    for(int i = 0; i < NUM_STOCKS; i++)
    {
        for(int j = 0; j < DAYS; j++) //assumes each company has exactly 30 days in the text file
        {
            in >> buf; 
            app[sector][i].push_back(buf); //push back to list
        }

        cout << "List has been populated by: " << sector << "!\n"; //FOR TESTING PURPOSES
    }
}

void runMonth(map<string,array<list<int>,3>>&app)
{
    //stockPrice(app); //legacy function, arrays are now populated
    calcTradeVolume(app);
    marketWide(app); 
}

void stockPrice(map<string,array<list<int>,3>>&app)
{
}

void calcTradeVolume(map<string,array<list<int>,3>>&app, string sector, int company)
{
    //to be implemented
    cout << "Trading volume for "; 
}

string matchCompany(map<string,array<list<int>,3>>&app, string sector, int company) //used to match numbers to specific companies
{
    //utilize maps in this function to list ints to stock names
    //itc = "int to company"
    map<int,string>itcCommServ = 
    {
        {0, ""},
        {1, ""},
        {2, ""},
    };
    map<int,string>itcInfoTech = 
    {
        {0, ""},
        {1, ""},
        {2, ""},
    };


    if(sector == "CommServ")
    {

    }
    else if (sector == "InfoTech")
    {

    }
}

void marketWide(map<string,array<list<int>,3>>&app)
{
}

void printInfo(map<string,array<list<int>,3>>app, int i) 
{
    //logic to print data for each day
}

// TODO: Make proper struct for each list? Or just have main handle specific stocks?
    //going to be hard to have a seperate tracker for trade volume unless I start using something like a struct.