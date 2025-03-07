#pragma once

using namespace std;
#include <iostream>
#include <string>
#include <vector>

#include "User.h"
#include "Bids.cpp"

class Job{
    private:
        User personRequesting;
        string title;
        string description;
        string deadLine;        // date MM/DD/YYYY
        double startPrice;      //decided by user with 'long term plan' to implelement auto suggesting
        double currentPrice;
        
        vector<Bids> bids;

    public:
        Job();
        Job(string setTitle,string setDescription, string setDeadline, double SetStartPrice);
        Job(User person, string setTitle,string setDescription, string setDeadline, double SetStartPrice, Bids addBid);

        // void setUser(User getUser);
        void setTitle(string getTitle);
        void setDescription(string getDescription);
        void setDeadline(string getDeadline);
        void setCurrentBid(double price);
        void addBids(Bids addBit);
    
        User getUser();
        string getTitle();
        string getDescription();
        string getDeadline();
        double getCurrentPrice();
        vector<Bids> getBids();

        int bidsAmount();
        
};

