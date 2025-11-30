#include <stdio.h>


struct Salary {
    float basic;
    float bonus;
    float deduction;
};

struct Employee {
    int id;
    char name[50];
    struct Salary sal;
};

void addEmployee(struct Employee emp[], int *count) {
    if (*count >= 50) {
        printf("Cannot add more employees.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp[*count].id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp[*count].name);

    printf("Enter Basic Pay: ");
    scanf("%f", &emp[*count].sal.basic);

    printf("Enter Bonus: ");
    scanf("%f", &emp[*count].sal.bonus);

    printf("Enter Deduction: ");
    scanf("%f", &emp[*count].sal.deduction);

    (*count)++;

    printf("\nEmployee Added Successfully!\n");
}

float netSalary(struct Salary s) {
    return s.basic + s.bonus - s.deduction;
}

void display(struct Employee emp[], int count) {
    if (count == 0) {
        printf("\nNo employees to display.\n");
        return;
    }
	int i;
    printf("\n=== EMPLOYEE DETAILS ===\n");

    for (i = 0;i< count; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Basic Pay: %.2f\n", emp[i].sal.basic);
        printf("Bonus: %.2f\n", emp[i].sal.bonus);
        printf("Deduction: %.2f\n", emp[i].sal.deduction);
        printf("Net Salary: %.2f\n", netSalary(emp[i].sal));
    }
}

int main() {
    struct Employee emp[50];
    int count = 0;
    int choice;

    do {
        printf("\n==== MENU ====\n");
        printf("1. Add Employee\n");
        printf("2. Display Salary Details\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(emp, &count);
                break;

            case 2:
                display(emp, count);
                break;

            case 3:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 3);

    return 0;
}

