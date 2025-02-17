#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const int WAGE_PER_HOUR = 20;
const int FULL_DAY_HOUR = 8;
const int PART_TIME_HOUR = 8;
const int WORKING_DAYS_PER_MONTH = 20;
const int MAX_HOURS = 100;

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

// UC4: Display results using Switch Case
void displayWage(int empStatus, int fullTimeWage, int partTimeWage) {
    int choice;
    cout << "Select option to display: \n1. Employee Attendance \n2. Full-time Wage \n3. Part-time Wage \n";
    cout<<"Your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << (empStatus == 1 ? "Employee is Present" : "Employee is Absent") <<
            endl;
            break;
        case 2:
            cout << "Daily Full-time Wage: " << fullTimeWage << endl;
            break;
        case 3:
            cout << "Daily Part-time Wage: " << partTimeWage << endl;
            break;
        
        default:
            cout << "Invalid choice!" << endl;
    }
}

// Shared Monthly Attendance Array
int attendance[WORKING_DAYS_PER_MONTH];

// UC5: Generate Monthly Attendance and Calculate Wages
void calculateMonthlyWage() {
    int monthlyWage = 0;
    for (int i = 0; i< WORKING_DAYS_PER_MONTH; i++) {
        attendance[i] = checkAttendance();
    }
    for (int i = 0; i < WORKING_DAYS_PER_MONTH; i++) {
        if (attendance[i] == 1) {
            monthlyWage += WAGE_PER_HOUR * FULL_DAY_HOUR;
        }
    }
    cout << "Total Monthly Employee Wage: " << monthlyWage << endl;
}

// UC6: Calculate Wages till total working hours or days condition is met
void calculateConditionalWage() {
    int totalHours = 0, totalDays = 0, totalWage = 0;
    for (int i = 0; i < WORKING_DAYS_PER_MONTH && totalHours < MAX_HOURS; i++) {
        if (attendance[i] == 1) {
            totalHours += FULL_DAY_HOUR;
            totalWage += WAGE_PER_HOUR * FULL_DAY_HOUR;
            totalDays++;
        }
    }
    cout<<"Total Hours Accumulated: "<<totalHours<<endl;
    if (totalHours >= MAX_HOURS)
        cout << "Maximum working hours reached. Total Employee Wage: " << totalWage << endl;
    else
        cout << "Working hours not yet reached. Total Wage so far: " << totalWage << endl;
}

// UC7: Refactor using Class
class EmployeeWageCalculator {
public:
    void computeWages() {
        int empStatus = checkAttendance();
        cout << (empStatus == 1 ? "Employee is Present" : "Employee is Absent") << endl;
        
        int fullTimeWage = calculateDailyWage(empStatus);
        int partTimeWage = calculatePartTimeWage(empStatus);
        displayWage(empStatus, fullTimeWage, partTimeWage);
        calculateMonthlyWage();
        calculateConditionalWage();
    }
};

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

    //UC4
    displayWage(empStatus, fullTimeWage, partTimeWage);

    //UC5
    calculateMonthlyWage();

    //UC6
    calculateConditionalWage();

    //UC7
    cout<<"UC7 (using classes): "<<endl;
    EmployeeWageCalculator empWage;
    empWage.computeWages();
    
    return 0;
}