#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    int employeeID;
    float salary;
    char jobTitle[50];
};

struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

void addEmployee() {
    if (numEmployees == MAX_EMPLOYEES) {
        printf("Maximum number of employees reached.\n");
        return;
    }

    struct Employee newEmployee;

    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);

    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.employeeID);

    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);

    printf("Enter employee job title: ");
    scanf("%s", newEmployee.jobTitle);

    employees[numEmployees] = newEmployee;
    numEmployees++;

    printf("Employee added successfully.\n");
}

int findEmployeeIndex(int employeeID) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].employeeID == employeeID) {
            return i;
        }
    }
    return -1;
}

void updateEmployee() {
    int employeeID;
    printf("Enter the employee ID to update: ");
    scanf("%d", &employeeID);

    int employeeIndex = findEmployeeIndex(employeeID);

    if (employeeIndex == -1) {
        printf("Employee with ID %d not found.\n", employeeID);
        return;
    }

    struct Employee updatedEmployee;

    printf("Enter updated employee name: ");
    scanf("%s", updatedEmployee.name);

    printf("Enter updated employee salary: ");
    scanf("%f", &updatedEmployee.salary);

    printf("Enter updated employee job title: ");
    scanf("%s", updatedEmployee.jobTitle);

    employees[employeeIndex] = updatedEmployee;

    printf("Employee with ID %d updated successfully.\n", employeeID);
}

void deleteEmployee() {
    int employeeID;
    printf("Enter the employee ID to delete: ");
    scanf("%d", &employeeID);

    int employeeIndex = findEmployeeIndex(employeeID);

    if (employeeIndex == -1) {
        printf("Employee with ID %d not found.\n", employeeID);
        return;
    }

    for (int i = employeeIndex; i < numEmployees - 1; i++) {
        employees[i] = employees[i + 1];
    }

    numEmployees--;

    printf("Employee with ID %d deleted successfully.\n", employeeID);
}

void displayEmployees() {
    if (numEmployees == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("Employee Details:\n");
    printf("---------------------------------\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Employee ID: %d\n", employees[i].employeeID);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("Job Title: %s\n", employees[i].jobTitle);
        printf("---------------------------------\n");
    }
}

int main() {
    int choice;

    do {
        printf("Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Update Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Display Employees\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                updateEmployee();
                break;
            case 3:
                deleteEmployee();
            case 4:
                displayEmployees();
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }while (choice != 5);
  
return 0;
  
}
