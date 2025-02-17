#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const int WAGE_PER_HOUR = 20;
const int FULL_DAY_HOUR = 8;
const int PART_TIME_HOUR = 8;

// UC1: Check Employee Attendance for a single day
int checkAttendance() {
    return rand() % 2; // 0 for absent, 1 for present
}

// UC2: Calculate Daily Employee Wage
int calculateDailyWage(int empStatus) {
    if (empStatus == 0) {
        cout << "Employee is Absent. No wage calculated." << endl;
        return 0;
    }
    cout<<"Full-time Wages: "<<WAGE_PER_HOUR * FULL_DAY_HOUR<<endl;
    return WAGE_PER_HOUR * FULL_DAY_HOUR;
}

// UC3: Calculate Part-time Employee Wage
int calculatePartTimeWage(int empStatus) {
    if (empStatus == 0) {
        cout << "Employee is Absent. No wage calculated." << endl;
        return 0;
    }
    cout<<"Part-time Wages: "<<WAGE_PER_HOUR * PART_TIME_HOUR<<endl;
    return WAGE_PER_HOUR * PART_TIME_HOUR;
}

int main() {
    cout << "Welcome to Employee Wage Computation Program on Master Branch" << endl;
    srand(time(0));

    //UC1
    int empStatus = checkAttendance();
    cout << (empStatus == 1 ? "Employee is Present" : "Employee is Absent") << endl;

    //UC2
    int fullTimeWage=calculateDailyWage(empStatus);

    //UC3
    int partTimeWage=calculatePartTimeWage(empStatus);
    
    return 0;
}