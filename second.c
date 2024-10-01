#include <stdio.h>

struct Employee
{
    int Employee_id;
    char Name[100];
    char Designation[100];
    float Salary;
    float hra;
    float da;
    float gross_salary;
};

float gross_salary(int basic_salary, float hra, float da)
{
    return (basic_salary * (1 + hra / 100.0 + da / 100.0));
}

int main()
{

    int n;
    printf("Enter number of Employees: ");
    scanf("%d", &n);

    struct Employee employee[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Details for employee %d: \n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employee[i].Employee_id);
        printf("Name: ");
        scanf("%s", &employee[i].Name);
        printf("Designation: ");
        scanf("%s", &employee[i].Designation);
        printf("Salary: ");
        scanf("%f", &employee[i].Salary);
        printf("HRA: ");
        scanf("%f", &employee[i].hra);
        printf("DA: ");
        scanf("%f", &employee[i].da);
    }

    printf("Employee Information: \n");

    for (int i = 0; i < n; i++)
    {
        printf("Employee ID: %d\n", employee[i].Employee_id);
        printf("Name: %s\n", employee[i].Name);
        printf("Designation: %s\n", employee[i].Designation);
        printf("Salary: %.2f\n", employee[i].Salary);
        printf("HRA: %.2f\n", employee[i].hra);
        printf("DA: %.2f\n", employee[i].da);
        printf("Gross Salary: %.2f\n", gross_salary(employee[i].Salary, employee[i].hra, employee[i].da));
    }

    return 0;
}