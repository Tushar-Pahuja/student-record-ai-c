#include <stdio.h>
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

/* Calculate CGPA of a student */
float calculateCGPA(struct Student s)
{
    float sum = 0;
    int i;

    if (s.semester <= 0)
        return 0;

    for (i = 0; i < s.semester; i++)
    {
        sum = sum + s.sgpa[i];
    }

    return sum / s.semester;
}

/* Add a student */
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

/* Display one student */
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

/* Search student using SAP ID */
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

/* Display all students */
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

/* Display CGPA of all students */
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

/* Calculate average CGPA for each year */
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

/* Sort students by SAP ID */
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

/* Sort students by name */
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
        printf("6. Sort by SAP ID\n");
        printf("7. Sort by Name\n");
        printf("8. Delete Student\n");
        printf("9. Academic Advisor\n");
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
                sortBySAP();
                break;

            case 7:
                sortByName();
                break;

            case 8:
                printf("\nDelete function will be added next.\n");
                break;

            case 9:
                printf("\nAcademic Advisor will be added next.\n");
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
