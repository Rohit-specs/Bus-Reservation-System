#include <stdio.h>
#include <string.h>

int choice;
char name[25];
char password[25];
char nname[25];
char npassword[25];
int is_regestration = 0;

int log_in();
int regestration();
int usermenu();

int main()
{

    while (1)
    {
        printf("\n\n\t\t**********BUS RESERVATION SYSTEM**********\n");
        printf("\t1. Registration");
        printf("\n\t2. Login\n");
        printf("\t3. Exit\n");
        printf("\tPlease Enter Your Choice : ");
        if (scanf("%d", &choice) == 1)
        {

            switch (choice)
            {
            case 1:
                regestration();
                break;
            case 2:
                log_in();
                //  usermenu();
                break;
            case 3:
                printf("\n\t**THANK YOU**");
                return 0;
            default:
                printf("\tPlease Enter A Valid Option!\n");
                break;
            }
        }

        else
        {
            printf("\tPlease Enter A Digit!\n\n");
        }
    }
}

int regestration()
{
    printf("\n\tPlease Enter Username For Registration: ");
    scanf(" %s", name);

    printf("\tPlease Set A Password: ");
    scanf(" %s", password);

    is_regestration = 1;

    printf("\n\tREGISTRATION COMPLETE!\n");
    return 0;
}

int log_in()
{
    if (is_regestration == 0)
    {
        printf("\n\tRegestration Is Not Completed!");
        return regestration();
    }

    printf("\n\n\tPlease Enter Registered Username: ");
    scanf(" %s", nname);

    if (strcmp(nname, name) == 0)
    {
        printf("\tPlease Enter Registered Password: ");
        scanf(" %s", npassword);
        if (strcmp(npassword, password) == 0)
        {
            printf("\n\tLogin Successful\n");
            printf("\tWelcome, %s", name);
            // return usermenu();
        }
        else
        {
            printf("\tPassword Not matched");
        }
    }
    else
    {
        printf("\tPlease enter correct username:");
    }
}
