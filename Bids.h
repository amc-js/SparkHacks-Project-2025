#pragma once

using namespace std;
#include <iostream>
#include <string>
#include "User.h"

class Bids{
    private:
        User bidder;   
        double bidAmount;

    public:
        Bids();
        Bids(User currBid, double amount);

        void setBid(double bid);
        void setBidder(User bidUser);
        double getBid();
        User getBidder();
};
