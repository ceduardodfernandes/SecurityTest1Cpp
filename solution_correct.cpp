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
    char name[MAX_NAME + 1] = {0};
    char pass[MAX_PASSWORD + 1] = {0};

    if (argc > 1) {
        if (strlen(argv[1]) >= sizeof(name)) {
            cout << "The name field should be a maximum of " << MAX_NAME << " characters!" << endl;
            return 0;
        } else {
            strncpy(name, argv[1], strlen(argv[1]));
        }

        if (argc < 3) {
            cout << "Field password is required!" << endl;
            return 0;
        } else if (strlen(argv[2]) >= sizeof(pass)) {
            cout << "The password field should be a maximum of " << MAX_PASSWORD << " characters!" << endl;
            return 0;
        } else {
            strncpy(pass, argv[2], strlen(argv[2]));
        }

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
Right Solution!

In this case we are checking every boundries and buffer limits, avoiding stack overflows
and segmentation faults.
*/