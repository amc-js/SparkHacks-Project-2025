using namespace std;

#include <iostream>
#include <string>
#include "User.h"


// constructors
#pragma region constructor
User::User(){
    username = "N/A";
    phoneNum = "N/A";
    isServiceProvider = false;
    serviceRating = -1.0;
};

User::User(bool isProvider, string name, string contactNum, double rating){
    username = name;
    phoneNum = contactNum;      
    isServiceProvider = isProvider;
    serviceRating = rating;
};

#pragma endregion constructor

// setters n getters
#pragma region settersNgetters
void User::setUsername(string name){
    username = name;
};

void User::setContactInfo(string contactNum){
    phoneNum = contactNum;
};

void User::setProviderRole(bool isProvider){
    isServiceProvider = isProvider;
};

void User::setRating(double rating){
    serviceRating = rating;
};

string User::getUsername(){
    return username;
}

string User::getContactInfo(){
    return phoneNum;
}

bool User::getProviderRole(){
    return isServiceProvider;
}

double User::getRating() {
    return serviceRating;
}

#pragma endregion settersNgetters

// print functions
#pragma region display
void User::displayInfo(){
    string provider;
    if(isServiceProvider){
        provider = "Is a service provider";
    }else provider = "Is not a service provider";
    
    cout << username << " Contact: " << phoneNum << " " << provider << endl;
};

#pragma endregion display