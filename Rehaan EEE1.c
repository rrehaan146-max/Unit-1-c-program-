/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>

int main()
{
    int choice;
    int roll, marks[5], total = 0;
    float average;
    char name[50];
    char grade;
    int entered = 0, calculated = 0;
    int i;

    do
    {
        printf("\nSTUDENT MARKS MANAGEMENT SYSTEM\n");
        printf("--------------------------------\n");
        printf("1. Enter Student Details\n");
        printf("2. Calculate Result\n");
        printf("3. Display Result\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll);

                printf("Enter Student Name: ");
                scanf(" %49[^\n]", name);

                for(i = 0; i < 5; i++)
                {
                    printf("Enter Subject %d Mark: ", i + 1);
                    scanf("%d", &marks[i]);
                }

                entered = 1;
                calculated = 0;
                break;

            case 2:
                if(entered == 0)
                {
                    printf("Please enter student details first!\n");
                    break;
                }

                total = 0;

                for(i = 0; i < 5; i++)
                {
                    total += marks[i];
                }

                average = total / 5.0;

                if(average >= 90)
                    grade = 'A';
                else if(average >= 80)
                    grade = 'B';
                else if(average >= 70)
                    grade = 'C';
                else if(average >= 60)
                    grade = 'D';
                else
                    grade = 'F';

                calculated = 1;
                printf("Result Calculated Successfully!\n");
                break;

            case 3:
                if(entered == 0 || calculated == 0)
                {
                    printf("Please enter details and calculate result first!\n");
                    break;
                }

                printf("\nSTUDENT RESULT\n");
                printf("------------------\n");
                printf("Roll Number : %d\n", roll);
                printf("Name        : %s\n", name);
                printf("Total       : %d\n", total);
                printf("Average     : %.2f\n", average);
                printf("Grade       : %c\n", grade);

                if(grade != 'F')
                    printf("Result      : PASS\n");
                else
                    printf("Result      : FAIL\n");

                break;

            case 4:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}
