using namespace std;

#include <iostream>
#include <string>
#include "Job.h"

Job::Job()
{
    User personRequesting = User();
    string title = "N/A";
    string description = "N/A";
    string deadLine = "N/A";       // date MM/DD/YYYY
    double currentPrice = -1.0;     //decided by user with 'long term plan' to implelement auto suggesting
    
    vector<Bids> bids = {Bids()};
};


Job::Job(string setTitle,string setDescription, string setDeadline, double SetStartPrice)
{
    title = setTitle;
    description = setDescription;
    deadLine = setDeadline;
    currentPrice = SetStartPrice;
};

Job::Job(User person, string setTitle,string setDescription, string setDeadline, double SetStartPrice, Bids addBid)
{
    personRequesting = person;
    title = setTitle;
    description = setDescription;
    deadLine = setDeadline;
    currentPrice = SetStartPrice;
    bids.push_back(addBid);
};

void Job::setTitle(string getTitle)
{
    title = getTitle;
}

void Job::setDescription(string getDescription)
{
    description = getDescription;
}

void Job::setDeadline(string getDeadline)
{
    deadLine = getDeadline;
}

void Job::setCurrentBid(double price)
{
    currentPrice = price;
}

void Job::addBids(Bids addBit)
{
    bids.push_back(addBit);
}

User Job::getUser()
{
    return personRequesting;
}

string Job::getTitle()
{
    return title;
}

string Job::getDescription()
{
    return description;
}

string Job::getDeadline()
{
    return deadLine;
}

double Job::getCurrentPrice()
{
    return currentPrice;
}

vector<Bids> Job::getBids()
{
    return bids;
}

int Job::bidsAmount()
{
    return bids.size();
}


