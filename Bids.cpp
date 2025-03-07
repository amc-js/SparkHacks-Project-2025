#pragma once

using namespace std;
#include <iostream>
#include <string>
#include "User.h"
#include "Bids.h"


Bids::Bids(){
    User personRequesting = User();
    bidAmount = 0.00;
};

Bids::Bids(User currBid, double amount){
    bidder = currBid;
    bidAmount = amount;
};


// Getters and Setters
void Bids::setBid(double bid) {
    bidAmount = bid;
}

void Bids::setBidder(User bidUser) {
    bidder = bidUser;
}

double Bids::getBid() {
    return bidAmount;
}

User Bids::getBidder() {
    return bidder;
}
