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
void readInData(map<string,array<list<int>,3>>&); 
void runMonth(map<string,array<list<int>,3>>&app);
void stockPrice(map<string,array<list<int>,3>>&app);
void tradeVolume(map<string,array<list<int>,3>>&app);
void marketWide(map<string,array<list<int>,3>>&app);
void printInfo(map<string,array<list<int>,3>>app, int);

int main()
{
    const int DAYS = 30;
    srand(time(0)); 

    map<string,array<list<int>,3>>notRobinhood; 
    readInData(notRobinhood); 

    //program loop
    for(int i = 0; i < DAYS; i++)
    {
        runMonth(notRobinhood);
        printInfo(notRobinhood, i+1); //so days start at one
    }

    return(0);
}

//implementation

//thinking about it maybe the list elements should be structs for me 
//if they each have details such as prices/volumes of trade, they can't be so one-dimensional

void readInData(map<string,array<list<int>,3>>&app)
{
    //at the moment stocks are represented not by names but as list integers 0,1,2
    ifstream in("stockInfo.txt");
    if(!in.good())
    {
        cout << "ERROR OPENING FILE\n"; //no file exists at the moment
    }
    app["Communications Sector"][0].push_back(150); 
    in.close(); 
}

void runMonth(map<string,array<list<int>,3>>&app)
{
    stockPrice(app);
    tradeVolume(app);
    marketWide(app); 
}

void stockPrice(map<string,array<list<int>,3>>&app)
{
    cout << "Stock prices went places.\n";
    app["Communications Sector"][0].push_back(rand()%20+150); //assign a random value for testing 
}

void tradeVolume(map<string,array<list<int>,3>>&app)
{
    cout << "Trade volumes changed\n"; 
}

void marketWide(map<string,array<list<int>,3>>&app)
{
    cout << "Market did things.\n";
}

void printInfo(map<string,array<list<int>,3>>app, int i) 
{
    cout << "[DAY " << i << "]: AAPL now at " << app["Communications Sector"][0].back() << "$ \n\n";
}

// TODO: Make proper struct for each list? Or just have main handle specific stocks?
    //going to be hard to have a seperate tracker for trade volume unless I start using something like a struct.