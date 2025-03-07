#pragma once

using namespace std;
#include <iostream>
#include <string>

class User{
    private:
        string username;
        string phoneNum;
        double serviceRating;
        bool isServiceProvider;

    public:
        User();
        User(bool isProvider, string name, string contactNum, double rating);

        void setUsername(string name);
        void setContactInfo(string contactNum);
        void setProviderRole(bool isProvider);
        void setRating(double inRating);

        string getUsername();
        string getContactInfo();
        double getRating();
        bool getProviderRole();
        
        void displayInfo();
};
