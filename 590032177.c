/*
Name: Tushar Pahuja
SAP ID: 590032177
Batch No.: 20
*/#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    long long sap_id;
    int roll_no;
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int semester;
    float sgpa[8];
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

/* Calculate CGPA */
float calculateCGPA(struct Student s)
{
    float sum = 0;
    int i;

    if (s.semester <= 0)
        return 0;

    for (i = 0; i < s.semester; i++)
    {
        sum += s.sgpa[i];
    }

    return sum / s.semester;
}

/* Add Student */
void addStudent()
{
    int i;

    if (studentCount >= MAX_STUDENTS)
    {
        printf("\nStudent limit reached.\n");
        return;
    }

    printf("\n--- Add Student ---\n");

    printf("Enter SAP ID: ");
    scanf("%lld", &students[studentCount].sap_id);

    printf("Enter Roll No: ");
    scanf("%d", &students[studentCount].roll_no);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[studentCount].name);

    printf("Enter Phone No: ");
    scanf("%s", students[studentCount].phone);

    printf("Enter Email ID: ");
    scanf("%s", students[studentCount].email);

    printf("Enter Year (1-4): ");
    scanf("%d", &students[studentCount].year);

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &students[studentCount].semester);

    printf("Enter SGPA for %d semester(s):\n",
           students[studentCount].semester);

    for (i = 0; i < students[studentCount].semester; i++)
    {
        printf("Semester %d SGPA: ", i + 1);
        scanf("%f", &students[studentCount].sgpa[i]);
    }

    for (i = students[studentCount].semester; i < 8; i++)
    {
        students[studentCount].sgpa[i] = 0;
    }

    studentCount++;

    printf("\nStudent added successfully.\n");
}

/* Display One Student */
void displayStudent(struct Student s)
{
    int i;

    printf("\nSAP ID: %lld\n", s.sap_id);
    printf("Roll No: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Phone No: %s\n", s.phone);
    printf("Email ID: %s\n", s.email);
    printf("Year: %d\n", s.year);
    printf("Current Semester: %d\n", s.semester);

    printf("SGPA: ");

    for (i = 0; i < s.semester; i++)
    {
        printf("%.2f ", s.sgpa[i]);
    }

    printf("\nCGPA: %.2f\n", calculateCGPA(s));
}

/* Search Student */
void searchStudent()
{
    long long sap;
    int i, found = 0;

    printf("\nEnter SAP ID to search: ");
    scanf("%lld", &sap);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].sap_id == sap)
        {
            printf("\nStudent found:\n");
            displayStudent(students[i]);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found.\n");
    }
}

/* Display All Students */
void displayAllStudents()
{
    int i;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n===== ALL STUDENT RECORDS =====\n");

    for (i = 0; i < studentCount; i++)
    {
        printf("\nStudent %d\n", i + 1);
        displayStudent(students[i]);
    }
}

/* Display CGPA */
void displayCGPA()
{
    int i;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n===== STUDENT CGPA =====\n");

    for (i = 0; i < studentCount; i++)
    {
        printf("%s - CGPA: %.2f\n",
               students[i].name,
               calculateCGPA(students[i]));
    }
}

/* Average CGPA by Year */
void averageCGPAByYear()
{
    int year, i, count;
    float total;

    printf("\n===== AVERAGE CGPA BY YEAR =====\n");

    for (year = 1; year <= 4; year++)
    {
        total = 0;
        count = 0;

        for (i = 0; i < studentCount; i++)
        {
            if (students[i].year == year)
            {
                total += calculateCGPA(students[i]);
                count++;
            }
        }

        if (count > 0)
        {
            printf("Year %d Average CGPA: %.2f\n",
                   year, total / count);
        }
        else
        {
            printf("Year %d: No students\n", year);
        }
    }
}

/* Delete Student */
void deleteStudent()
{
    long long sap;
    int i, j, found = 0;

    if (studentCount == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\nEnter SAP ID of student to delete: ");
    scanf("%lld", &sap);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].sap_id == sap)
        {
            for (j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }

            studentCount--;
            found = 1;

            printf("\nStudent record deleted successfully.\n");
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found.\n");
    }
}

/* Sort by SAP ID */
void sortBySAP()
{
    int i, j;
    struct Student temp;

    for (i = 0; i < studentCount - 1; i++)
    {
        for (j = 0; j < studentCount - i - 1; j++)
        {
            if (students[j].sap_id > students[j + 1].sap_id)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by SAP ID.\n");
    displayAllStudents();
}

/* Sort by Name */
void sortByName()
{
    int i, j;
    struct Student temp;

    for (i = 0; i < studentCount - 1; i++)
    {
        for (j = 0; j < studentCount - i - 1; j++)
        {
            if (strcmp(students[j].name, students[j + 1].name) > 0)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by Name.\n");
    displayAllStudents();
}

/* AI-Assisted Academic Advisor */
void academicAdvisor()
{
    long long sap;
    int i, found = 0;
    float cgpa;

    printf("\n===== AI-ASSISTED ACADEMIC ADVISOR =====\n");

    printf("Enter SAP ID: ");
    scanf("%lld", &sap);

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].sap_id == sap)
        {
            found = 1;
            cgpa = calculateCGPA(students[i]);

            printf("\nStudent: %s\n", students[i].name);
            printf("CGPA: %.2f\n", cgpa);

            if (cgpa >= 9.0)
            {
                printf("Advice: Excellent Performance - Maintain your current study pattern.\n");
            }
            else if (cgpa >= 7.5)
            {
                printf("Advice: Good Performance - Keep working consistently and aim higher.\n");
            }
            else if (cgpa >= 6.0)
            {
                printf("Advice: Needs Improvement - Focus more on subjects with lower SGPA.\n");
            }
            else
            {
                printf("Advice: Requires Immediate Attention - Improve your study plan and seek academic support.\n");
            }

            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found.\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== STUDENT RECORD AND RESULT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Display CGPA\n");
        printf("5. Average CGPA by Year\n");
        printf("6. Delete Student\n");
        printf("7. Sort by SAP ID\n");
        printf("8. Sort by Name\n");
        printf("9. AI-Assisted Academic Advisor\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                displayAllStudents();
                break;

            case 4:
                displayCGPA();
                break;

            case 5:
                averageCGPAByYear();
                break;

            case 6:
                deleteStudent();
                break;

            case 7:
                sortBySAP();
                break;

            case 8:
                sortByName();
                break;

            case 9:
                academicAdvisor();
                break;

            case 10:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 10);

    return 0;
}
