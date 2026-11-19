#include <stdio.h>

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

int main()
{
    int choice;

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

    return 0;
}
