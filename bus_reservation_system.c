#include <stdio.h>
#include <string.h>

int choice;
char name[25];
char password[25];
char nname[25];
char npassword[25];
int is_regestration = 0;
int seat, Tseats = 40;
int busnum;
int bookedBus[10];   
int bookedSeats[10];  
int cancelseatsarr[10]; 
int bookingCount = 0;

int log_in();
int regestration();
int usermenu();
int ticketbooking();
void busstatus();
int cancelseats();

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
            while (getchar() != '\n');
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
            return usermenu();
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

int usermenu()
{
    printf("\n\n\t=======User Menu=======\n");
    printf("\t1. Book A Ticket\n");
    printf("\t2. Cancel A Ticket\n");
    printf("\t3. Check Bus Status\n");
    printf("\t4. Logout\n");
    printf("\tEnter Your Choice: ");
    if (scanf("%d", &choice) == 1)
    {
        switch (choice)
        {
        case 1:
            ticketbooking();
            break;
        case 2:
            //cancelseats();
            break;
        case 3:
            //busstatus();
            break;
        case 4:
            printf("\n\t**THANKS FOR COMING**\n");
            return 0;
        default:
            printf("\t Please Enter A Valid Option!\n");
            break;
        }
    }
    else
    {
        printf("\tPlease Enter A Digit!\n");
        while (getchar() != '\n');
    }
    return usermenu();
}

int ticketbooking() 
{
    printf("\n\t---------TICKET_BOOKING---------\n");
    printf("\tBus No.105\tDelhi  to  UP\n");
    printf("\tBus No.101\tDelhi  to  Uttrakhand\n");
    printf("\tBus No.124\tDelhi  to  MP\n");
    printf("\tBus No.119\tDelhi  to  Rajasthan\n");
    printf("\n\tEnter Bus Number To Continue: ");
    if (scanf("%d", &busnum)) 
    {
        if (!(busnum == 105 || busnum == 101 || busnum == 124 || busnum == 119)) {
            printf("\tInvalid Bus Number!");
            return 0;
        }
        printf("\tEnter No. Of Seat: ");
        scanf("%d", &seat);
        if (Tseats >= seat) 
        {
            bookedBus[bookingCount] = busnum;
            bookedSeats[bookingCount] = seat;
            cancelseatsarr[bookingCount] = 0;
            bookingCount++;
            printf("\n\tBOOKING SUCCESSFUL!\n");
            printf("\t%d Seats Booked On Bus Number %d.\n", seat, busnum);
        } 
        else 
        {
            printf("\tThat Many Seats Are Not Available!\n");
        }
    }
     else 
    {
        printf("\n\tBus Number Should Be A Digit!");
        while (getchar() != '\n');
    }
    return 0;
}



