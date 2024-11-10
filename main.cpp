// Include necessary libraries
// Include necessary header file(s)
// Namespace std

// function prototypes for various necessary parts of program
// day running function (facilitates changes)
// helper function for printing formatted data
// function for tracking trade volume
// function for tracking stock price
// function for tracking sector-wide effects

// function parameters will depend on whether they reference or change fields
// reference vs value

// define main()
// initalize a map named something like "notRobinhood" to store data about various sector(s) arrays
// each sector array associated a list of three companies

// open an external file to read in data about the companies and populate their associated list entries
// include error handling/messaging
// close once all data has been sucessfully read in

// begin the time-based for loop simulating a month's market fluctuations
//  30ish calls to the day running function
// for each array (sector)
// facilitates any sector-wide changes
// for each list (stock)
// facilitates data changes (stock price increase/decreate), (trading volume increase/decrease)
// data printing, ex: [Day X: APPL: 231.23, VOLUME: +232,323]
// similar printing that announces sector-wide events
// could even get crazy and do whole-market effects (in spirit of the recent election)

// pause briefly/add space between messages to maintain readable breakdown

// end main()

// function implementation:
// day running function (facilitates changes)
// helper function for printing formatted data
// function for tracking trade volume
// function for tracking stock price
// function for tracking sector-wide effects

// COMSC-210 | labs 29-31 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>  // for std::list
#include <array> //for std::array
#include <map>
#include <time.h>
#include <random>
#include <string>
using namespace std;

// function prototypes
void readInData(map<string, array<list<double>, 3>> &, string);
void readIntoList(map<string, array<list<double>, 3>> &, string, ifstream &); // helper
void runDay(map<string,array<list<double>,3>>&app);
void calcTradeVolume(map<string, array<list<double>, 3>> &app, string, int);
string matchCompany(string sector, int company);
void marketOrSectorWide(map<string, array<list<double>, 3>> &app);
void printInfo(map<string, array<list<double>, 3>> app, int);

// driver tests for the program
void testLists(map<string, array<list<double>, 3>> app);
void testVolume(map<string, array<list<double>, 3>> app);

const int NUM_STOCKS = 3, DAYS = 30;

int main()
{
    srand(time(0));

    map<string, array<list<double>, 3>> notRobinhood;

    // initialize the key/value pair of two arrays
    notRobinhood["CommServ"];
    notRobinhood["InfoTech"];

    // read in data to each of the array nested loops
    readInData(notRobinhood, "Comm.txt"); // string passed to differentiate sectors
    readInData(notRobinhood, "IT.txt");

    // program loop
    for (int i = 0; i < 3; i++) //testing with days at 3 to not flood terminal
    {
        runDay(notRobinhood);
        printInfo(notRobinhood, i+1); //so days start at one
    }

    // testing purpose functions
    // testLists(notRobinhood);
    // testVolume(notRobinhood);

    return (0);
}

// implementation functions

void readInData(map<string, array<list<double>, 3>> &app, string sector) // different sectors each have different text files
{
    ifstream in(sector); // open sector-specific file
    if (!in.good())
    {
        cout << "ERROR OPENING FILE\n"; // no file exists at the moment
    }
    else if (sector == "Comm.txt")
    {
        readIntoList(app, "CommServ", in); // populates each of three lists (lists currently have no way of being differentiated)
    }
    else if (sector == "IT.txt")
    {
        readIntoList(app, "InfoTech", in);
    }
    else
    {
        cout << "Invalid Sector passed.\n";
    }
    in.close();
}

void readIntoList(map<string, array<list<double>, 3>> &app, string sector, ifstream &in) // helper function
{
    double buf; // stores values to populate map
    for (int i = 0; i < NUM_STOCKS; i++)
    {
        for (int j = 0; j < DAYS; j++) // assumes each company has exactly 30 days in the text file
        {
            in >> buf;
            app[sector][i].push_back(buf); // push back to list
        }
    }
}

void runDay(map<string, array<list<double>, 3>> &app)
{
    marketOrSectorWide(app);  // sim marketwide change

    // for each stock:
    for(int i = 0; i < 3; i++)
        calcTradeVolume(app, "CommServ", i); 
    for(int i = 0; i < 3; i++)
        calcTradeVolume(app, "InfoTech", i); 
}

void calcTradeVolume(map<string, array<list<double>, 3>> &app, string sector, int company)
{
    int volume = 0, i = 0; // variable to do calculations upon

    volume = rand() % 2938; // test function

    // to be implemented
    // probably calculates based on current stock price,
    // if went up, volume up (people buying high)
    // if went down, volume WAY up (people selling out of fear)

    cout << "vol: " << volume << " ";
    i++;
    if (i % 10 == 0 && i != 0)
        cout << '\n';
}

string matchCompany(string sector, int company) // used to match numbers to specific companies
{
    // utilize maps in this function to list ints to stock names
    // itc = "int to company"
    map<int, string> itcCommServ =
        {
            {0, "GOOGL"},
            {1, "META"},
            {2, "NFLX"},
        };

    map<int, string> itcInfoTech =
        {
            {0, "AAPL"},
            {1, "NVDA"},
            {2, "CTLP"}, // cantaloupe inc, a smaller company
        };

    if (sector == "CommServ")
        return (itcCommServ[company]);

    else if (sector == "InfoTech")
        return (itcInfoTech[company]);

    else
        return ("INVALID COMPANY REFERENCED"); // error message as precaution
}

void marketOrSectorWide(map<string, array<list<double>, 3>> &app)
{
    // logic for Sectorwide/Marketwide crash or boom, will probably
    // work based on a random value generation, with a chance each
    // time in the monthloop.
}

void printInfo(map<string, array<list<double>, 3>> app, int i)
{
    // logic to print data for each day, will be similar to
    // the tester function for the list output, interestingly
    // enough
}

// testing functions

void testLists(map<string, array<list<double>, 3>> app)
{
    // for commserv sector
    cout << "TESTING COMMSERV SECTOR: \n";
    for (int i = 0; i < NUM_STOCKS; i++)
    {
        cout << matchCompany("CommServ", i) << '\n'; // test the ability of matchCompany for the "Commserv" array

        auto &companyList = app["CommServ"][i]; // address
        int j = 0;
        for (double val : companyList)
        {
            cout << val << " ";
            if (j % 10 == 0 && j != 0)
                cout << '\n'; // formatting
            j++;
        }
        cout << '\n';
    }
    cout << "\n"; // format

    cout << "TESTING INFOTECH SECTOR: \n";
    for (int i = 0; i < NUM_STOCKS; i++)
    {
        cout << matchCompany("InfoTech", i) << '\n'; // test the ability of matchCompany for the "Commserv" array

        auto &companyList = app["InfoTech"][i]; // address
        int j = 0;
        for (double val : companyList)
        {
            cout << val << " ";
            if (j % 10 == 0 && j != 0)
                cout << '\n'; // formatting
            j++;
        }
        cout << '\n';
    }
}

void testVolume(map<string, array<list<double>, 3>> app)
{
    cout << "\nNOW CALCULATING TRADE VOLUMES: \n\n";
    cout << "FOR NVDA: \n";
    auto &companyList = app["InfoTech"][1]; // address
    for (double val : companyList)
    {
        calcTradeVolume(app, "InfoTech", 1);
    }

    cout << "\n\n";

    cout << "FOR CTLP: \n";
    auto &companyList2 = app["InfoTech"][2]; // address
    for (double val : companyList)
    {
        calcTradeVolume(app, "InfoTech", 2);
    }
}