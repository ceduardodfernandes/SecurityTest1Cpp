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
    char* name;
    char* pass;

    if (argc > 1) {
        name = (char*)malloc(strlen(argv[1]) * sizeof(char));
        pass = (char*)malloc(strlen(argv[2]) * sizeof(char));
        
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
not checking, but we are not validating all the fields. In this case,
password could be empty.
In addition, malloc () should reserve one more position so that our 
buffer could have the null finalizer. And we are never releasing the
allocated memory.
*/