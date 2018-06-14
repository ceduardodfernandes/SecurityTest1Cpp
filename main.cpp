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
        strcpy(name, argv[1]); /*risk*/
        strcpy(pass, argv[2]); /*risk*/

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