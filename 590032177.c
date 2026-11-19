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

/* Function to add a student */
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

/* Function to display one student */
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

    printf("\n");
}

/* Function to search student using SAP ID */
void searchStudent()
{
    long long sap;
    int i;
    int found = 0;

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

/* Function to display all students */
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

int main()
{
    int choice;

    do
    {
        printf("\n===== STUDENT RECORD AND RESULT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Calculate CGPA\n");
        printf("5. Delete Student\n");
        printf("6. Sort by SAP ID\n");
        printf("7. Sort by Name\n");
        printf("8. Academic Advisor\n");
        printf("9. Exit\n");

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
                printf("\nCGPA function will be added next.\n");
                break;

            case 5:
                printf("\nDelete function will be added next.\n");
                break;

            case 6:
                printf("\nSAP ID sorting will be added next.\n");
                break;

            case 7:
                printf("\nName sorting will be added next.\n");
                break;

            case 8:
                printf("\nAcademic Advisor will be added next.\n");
                break;

            case 9:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}
