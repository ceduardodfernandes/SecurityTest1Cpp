#include <iostream>
#include "memory.h"

#define MAX_NAME 100
#define MAX_PASSWORD 50

using namespace std;

bool Login(char name[], char pass[]) {
    //Some DB validation

    return true;
}

int main(int argc, char* argv[]) {
    char name[MAX_NAME] = {0};
    char pass[MAX_PASSWORD] = {0};

    if (argc > 1) {
        strncpy(name, argv[1], sizeof(name) - 1);
        strncpy(pass, argv[2], sizeof(pass) - 1);

        if (Login(name, pass)) {
            cout << "Logged In!" << endl;
        } else {
            cout << "Invalid credentials!" << endl;
        }
    } else {
        cout << "Credentials required!" << endl;
    }

    return 0;
}

/*
Wrong Solution

Checking the buffer size we are going to copy is safer than 
not checking, but we have not yet validated the sizes to know 
if they will fit in our array, and we are not validating all the fields.
*/