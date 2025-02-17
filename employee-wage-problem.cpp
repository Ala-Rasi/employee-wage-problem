#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// UC1: Check Employee Attendance for a single day
int checkAttendance() {
    return rand() % 2; // 0 for absent, 1 for present
}

int main() {
    cout << "Welcome to Employee Wage Computation Program on Master Branch" << endl;
    srand(time(0));
    //UC1
    int empStatus = checkAttendance();
    cout << (empStatus == 1 ? "Employee is Present" : "Employee is Absent") << endl;
    return 0;
}