#pragma once

#include <iostream>  // Input/output operations (e.g., cout, cin)
#include <string>    // String manipulation
#include <vector>    // Dynamic arrays
#include <fstream>   // File handling
#include <sstream>   // String streams 
#include <iomanip> 
#include "Job.h"

using namespace std;

#pragma region userFunctions
// take data in from .txt and make users from it

void ingestData(vector<User>& companyData , bool write = true) {
    fstream fileIn("companies.txt");
    string currUser;
    
    while(getline(fileIn, currUser)) {

        bool userNum;  
        string userName;
        string userContact;
        double rating;

        stringstream s(currUser);
        s >> userNum;
        s >> userName;
        s >> userContact;
        s >> rating;
        
        User u(userNum, userName, userContact, rating);
        companyData.push_back(u);
    }    

    if(write)
    {
        cout <<setfill('-') << setw(73) << "";
    }

    for (int i = 0; i < companyData.size(); i++) {

        if(write)
        {
            cout << "\n| Company: " << left << setfill(' ') << setw(21) << companyData.at(i).getUsername() 
            << "| Contact #: " << companyData.at(i).getContactInfo() << " | Rating: " << setfill(' ') << 
            fixed << setprecision(1) << companyData.at(i).getRating() << " |";
        }
    }

    if(write)
    {
        cout << endl << setfill('-') << setw(73) << "";
    }
}



#pragma endregion userFunctions


#pragma region companyFunctions

vector<Job> jobListings(bool write) { 
    fstream fileIn("job listings.txt");

    string jobName;  
    string jobDesc;
    string jobDeadline;
    string jobPrice;
    vector<Job> jobBoard;
    int jobID = 1;
    
    if(write)
    {
        cout <<setfill('-') << setw(181) << "";
        cout << endl;
    }

    while(getline(fileIn, jobName,'%') && getline(fileIn, jobDesc,'%') && 
    getline(fileIn, jobDeadline,'%') && getline(fileIn, jobPrice)) {
       
        jobBoard.push_back(Job(jobName, jobDesc, jobDeadline, stoi(jobPrice)));

        if(write)
        {
            cout << left << setfill(' ') << setw(2) << jobID << "| Job name: " << left << setfill(' ') << setw(23) << jobName 
            << setw(20) << " | Job description: " <<  setw(75) << jobDesc  << "  | Deadline: " << setfill(' ') 
            << jobDeadline << "  | Job price: "  << setfill(' ') << setw(9) << jobPrice << "|\n";
        }

        jobID++;
        
    }
    
    if(write)
    {
        cout << endl << setfill('-') << setw(181) << "";
        cout << endl;
    }

    return jobBoard;              
}

#pragma endregion companyFunctions