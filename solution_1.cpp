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
        strcpy(name, argv[1]);

        if (strlen(argv[2]) < 1) {
            cout << "Password needed!" << endl;
            return;
        }

        strcpy(pass, argv[2]);

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
Incomplete solution 1

Since we were not checking if the password field was being sent, 
strcpy () that did not have security handling was generating a Segmentation Fault.
*/