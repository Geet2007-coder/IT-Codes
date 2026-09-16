#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks[5];
    float percentage;
    char grade;
};

int main()
{
    int n, i, j;
    struct Student s[100], temp;
    float total;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        total = 0;

        printf("Enter marks of 5 subjects:\n");
        for (j = 0; j < 5; j++)
        {
            scanf("%f", &s[i].marks[j]);
            total = total + s[i].marks[j];
        }

        // Calculate percentage
        s[i].percentage = total / 5;

        // Calculate grade
        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 80)
            s[i].grade = 'B';
        else if (s[i].percentage >= 70)
            s[i].grade = 'C';
        else if (s[i].percentage >= 60)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';
    }

    // Sort students based on percentage
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].percentage < s[j].percentage)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // Display all students
    printf("\n========== STUDENT REPORT ==========\n");

    printf("Roll\tName\tPercentage\tGrade\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%.2f%%\t\t%c\n",
               s[i].roll,
               s[i].name,
               s[i].percentage,
               s[i].grade);
    }

    // Display top three performers
    printf("\n========== TOP THREE PERFORMERS ==========\n");

    int limit;

    if (n < 3)
        limit = n;
    else
        limit = 3;

    for (i = 0; i < limit; i++)
    {
        printf("%d. %s (Roll No: %d) - %.2f%% - Grade %c\n",
               i + 1,
               s[i].name,
               s[i].roll,
               s[i].percentage,
               s[i].grade);
    }

    return 0;
}