#include <iostream>  // Input/output operations (cout, cin, ge)line
#include <string>    // String handling
#include <vector>    // Dynamic arrays
#include <fstream>   // File handling
#include <sstream>   // String streams 
#include <iomanip>   // setw & setfill

using namespace std;

#include "User.cpp"
#include "Bids.cpp"
#include "GUI.cpp"
#include "Job.h"
#include "dataProcess.cpp"

// prompts users for name, phone number, and whether they're a company or not
int main() {
    
    User u = login(); 
    displayMenu(u); 
        
    return 0;
}
