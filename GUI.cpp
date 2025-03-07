#pragma once

using namespace std;

#include <string>
#include <iostream>
#include <stdlib.h> 
#include <cstdlib>
#include "User.h"
#include "Job.cpp"
#include "dataProcess.cpp"
#include "Bids.h"
#include <unistd.h>
#include <fstream>

Job createJobPosting(User sessionUser);

User login(){
    User sessionUser;

    bool isProvider;
    string name, contactNum, isCompany;
    double rating;

    cout << "Please enter your name: ";
    getline(cin, name);
    
    cout << "Please enter your phone number: ";
    getline(cin, contactNum);
    
    cout << "Are you a company (Yes or No): ";
    getline(cin, isCompany);

    if(isCompany == "Yes" || isCompany == "yes" || isCompany == "y"){isProvider = true;}
    else if(isCompany == "No" || isCompany == "no" || isCompany == "n"){isProvider = false;}
    
    if(isProvider){
        sessionUser.setUsername(name);
        sessionUser.setContactInfo(contactNum);
        sessionUser.setProviderRole(isProvider);
        double ranRating = static_cast<double>((rand() % 3) + 2) + (((rand() % 8) + 1) / 10.0);
        sessionUser.setRating(ranRating);
    }
    else{
        sessionUser.setUsername(name);
        sessionUser.setContactInfo(contactNum);
        sessionUser.setProviderRole(isProvider);
        sessionUser.setRating(-1.0);
    }
    return sessionUser;
}



void displayMenu(User userInfo){
    string choice = "0";

    cout << endl;
    cout << left <<setfill('-') << setw(25) << "" << endl;
    cout << left <<setw(25) << "| Welcome to SeaJobs++  |" << endl;
    cout << left << setfill(' ') << setw(24) << "|" << "|" << endl;
    cout << left << setw(24) << "| Select an option" << setw(24) <<'|' << endl;
    //For the company 
    if(userInfo.getProviderRole())
    {
        while(stoi(choice) != 3)
        {
            cout << left <<setfill('-') << setw(25) << "" << endl;
            cout << left << setfill(' ') << setw(24) << "| 1) View Available Jobs" << setw(24)<<'|'<< endl;
            cout << left << setfill(' ') << setw(24) << "|" << "|";
            cout << left << setfill(' ') << setw(25) << "\n| 2) Place a Bid" << setfill(' ') << setw(25)<<'|'<< endl;
            cout << left << setfill(' ') << setw(24) << "|" << "|";
            cout << left << setfill(' ') << setw(25) << "\n| 3) Exit" << setfill(' ') <<setw(25)<<'|'<< endl;

            cout << setfill('-') << setw(25) << "" << endl;

            getline(cin, choice);

            if(stoi(choice) == 1)
            {
                jobListings(true);
                cout << endl;
            }
            else if (stoi(choice) == 2)
            {
                string jobPick = "";
                cout << "\nPick a Job ID to bid for " << endl;
                getline(cin, jobPick);

                vector<Job> jobList = jobListings(false);

                vector<User> companyData;
                ingestData(companyData, false);

                cout << "You are now bidding for: $" << jobList.at(stoi(jobPick) - 1).getTitle() << endl;
                cout << "The current bid is: $" << jobList.at(stoi(jobPick) - 1).getCurrentPrice() << endl << "(To bid, type in a number)" << endl;
                string holdCheck;
                string bestCompany = "";
                double original = jobList.at(stoi(jobPick) - 1).getCurrentPrice();

                while(original*0.30 < jobList.at(stoi(jobPick) - 1).getCurrentPrice())
                {
                    sleep(2);
                    if(getline(cin, holdCheck))
                    {
                        if(stod(holdCheck) < jobList.at(stoi(jobPick) - 1).getCurrentPrice())
                        {

                            jobList.at(stoi(jobPick) - 1).setCurrentBid(stod(holdCheck)); 
                            bestCompany = jobList.at(stoi(jobPick) - 1).getUser().getUsername();
                            cout << userInfo.getUsername() << ": " << (int)stod(holdCheck) << endl;
                        }
                    }
                    
                    sleep(2);
                    int randomID = (rand() % 19) + 1;
                    string company = companyData.at(randomID).getUsername();
                    int maxValue = jobList.at(stoi(jobPick) - 1).getCurrentPrice() * 0.65;
                    double minValue = jobList.at(stoi(jobPick) - 1).getCurrentPrice()  * 0.35;
                    bestCompany = company;

                    cout << company << ": " << (rand() % maxValue) + minValue << endl;

                    holdCheck = "";
                }

                cout << "The bid winner is " << bestCompany << "." << endl << endl;;
        
            }
            else if(stoi(choice) == 3)
            {
                exit(0);
            }
        }
    } 
    // else branch for a Homeowner
    else
    {
        while(stoi(choice) != 3)
        {
            cout << left <<setfill('-') << setw(25) << "" << endl;
            cout << left << setfill(' ') << setw(24) << "| 1) View Companies" << setw(24)<<'|'<< endl;
            cout << left << setfill(' ') << setw(24) << "|" << "|";
            cout << left << setfill(' ') << setw(25) << "\n| 2) Create Job Listing" << setfill(' ') << setw(25)<<'|'<< endl;
            cout << left << setfill(' ') << setw(24) << "|" << "|";
            cout << left << setfill(' ') << setw(25) << "\n| 3) Exit" << setfill(' ') <<setw(25)<<'|'<< endl;
            cout << setfill('-') << setw(25) << "" << endl;
            
            getline(cin, choice);
            if(stoi(choice) == 1)
            {
                vector<User> companyData;
                ingestData(companyData);
                cout << endl;          
            }
            else if(stoi(choice) == 2)
            {
                Job f = createJobPosting(userInfo);
                vector<User> companyData;
                ingestData(companyData, false);
                
                cout << "\nYou started a bid for $" << (int)f.getCurrentPrice() << " dollars." << endl;
                double lowestBid = 999999;
                string bestCompany = "";
                string phoneNumber = "";
                double original = f.getCurrentPrice();

                while(original*0.20 < lowestBid)
                {
                    int randomID = (rand() % 19) + 1;
                    string checkCompany = companyData.at(randomID).getUsername();
                    int maxValue = f.getCurrentPrice() * 0.65;
                    double minValue = f.getCurrentPrice() * 0.35;

                    int checkLow = (rand() % maxValue) + minValue;
                    
                    if(checkLow < lowestBid && checkCompany != bestCompany)
                    {
                        lowestBid = checkLow;
                        bestCompany = checkCompany;
                        phoneNumber = companyData.at(randomID).getContactInfo();
                        f.setCurrentBid(lowestBid);

                        cout << bestCompany << " bids: $" << (int)lowestBid << endl;
                        sleep((rand() % 2) + 1);

                    }
                }
                cout << "The bid winner is " << bestCompany << " (" << phoneNumber << ")"<< " with $" << lowestBid << endl << endl;
            }
            else if(stoi(choice) == 3)
            { 
                exit(0);
            }    
        }
    }
}

Job createJobPosting(User sessionUser){
    string jobTitle, description, deadline, initialPrice;
    
    cout << "Please enter title for job: "; 
    getline(cin, jobTitle);
    cout << endl;

    cout << "Please enter description for job: "; 
    getline(cin, description);
    cout << endl;

    cout << "Please enter deadline for job: "; 
    getline(cin, deadline);
    cout << endl;

    cout << "Please enter the initial price: ";
    getline(cin, initialPrice);
    cout << endl;

    Bids newBid = Bids(sessionUser, stod(initialPrice));
    

    Job newJob = Job(sessionUser, jobTitle, description, deadline, stod(initialPrice), newBid);
    cout << "Job created successfully" << endl;

    return newJob;
}


