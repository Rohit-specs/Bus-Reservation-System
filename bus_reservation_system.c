#include <stdio.h>
#include <string.h>

int choice;
char name[25];
char password[25];
char nname[25];
char npassword[25];
int is_regestration = 0;
int seat, Tseats = 40;
int busnum, busnum1;
int cancelseat, currentseat;
int Fare = 120;
int bookedBus[10];   
int bookedSeats[10];  
int cancelseatsarr[10]; 
int bookingCount = 0;
int attempts = 3;
char confirmPassword[25];
int hasLetter, hasDigit;

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
    do 
    {  
        printf("\n\tPlease Enter Username For Registration: ");  
        scanf(" %s", name);  
        
        if (name[0] == '0') 
        {  
            printf("\tUsername cannot start with 0!\n");  
            continue;  
        }  
        
        hasLetter = hasDigit = 0;
        for (int i = 0; name[i] != '\0'; i++) 
        {  
            if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))  
                hasLetter = 1;  
            if (name[i] >= '0' && name[i] <= '9')  
                hasDigit = 1;  
        }  
        if (!(hasLetter && hasDigit))  
            printf("\tUsername must contain at least 1 letter and 1 digit!\n");  
    }
    while (name[0] == '0' || !(hasLetter && hasDigit));  
    do 
    {  
        printf("\tPlease Set A Password: ");  
        scanf(" %s", password);  

        if (password[0] == '0') {  
            printf("\tPassword cannot start with 0!\n");  
            continue;  
        }  

        hasLetter = hasDigit = 0;  
        for (int i = 0; password[i] != '\0'; i++) {  
            if ((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z'))  
                hasLetter = 1;  
            if (password[i] >= '0' && password[i] <= '9')  
                hasDigit = 1;  
        }  
        if (!(hasLetter && hasDigit)) {  
            printf("\tPassword must contain at least 1 letter and 1 digit!\n");  
            continue;  
        }  
        printf("\tConfirm Password: ");  
        scanf(" %s", confirmPassword);  

        if (strcmp(password, confirmPassword) != 0) {  
            printf("\tPasswords Do Not Match! Please Try Again.\n\n");  
            continue;  
        }  
        is_regestration = 1;  
        printf("\n\tREGISTRATION COMPLETE!\n");  
        break;  

    } while (1);  

    return 0;  
}

int log_in()
{
    if (is_regestration == 0)
    {
        printf("\n\tRegistration Is Not Completed!");
        return regestration();
    }
    while (attempts > 0)
    {
        printf("\n\n\tPlease Enter Registered Username: ");
        scanf(" %s", nname);

        if (strcmp(nname, name)== 0)
        {
            printf("\tPlease Enter Registered Password: ");
            scanf(" %s", npassword);

            if (strcmp(npassword, password)== 0)
            {
                printf("\n\tLogin Successful\n");
                printf("\tWelcome, %s\n", name);
                return usermenu();
            }
            else
            {
                attempts--;
                printf("\tIncorrect Password Attempts left: %d\n", attempts);
            }
        }
        else
        {
            attempts--;
            printf("\tIncorrect Username Attempts left: %d\n", attempts);
        }
    }
    printf("\n\tToo many failed attempts Access denied\n");
    printf("\n\t\tRegister Again Further!\n");
    return 0;
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
            cancelseats();
            break;
        case 3:
            busstatus();
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
    printf("\tBus No.105\tDelhi  -->  UP\n");
    printf("\tBus No.101\tDelhi  -->  Uttrakhand\n");
    printf("\tBus No.124\tDelhi  -->  MP\n");
    printf("\tBus No.119\tDelhi  -->  Rajasthan\n");
    printf("\n\tEnter Bus Number To Continue: ");
    if (scanf("%d", &busnum)) 
    {
        if 
        (!(busnum == 105 || busnum == 101 || busnum == 124 || busnum == 119)) 
        {
            printf("\tInvalid Bus Number!\n");
            printf("\tYou can try values like 105 and 101");
            return 0;
        }
        printf("\tEnter No. Of Seat: ");
        if (scanf("%d", &seat))
        {
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
            while(getchar() != '\n');
            printf("\tSeats Should Be In Digits!");
            return ticketbooking();
        }
    }
    else 
    {
        printf("\n\tBus Number Should Be A Digit!");
        while (getchar() != '\n');
        return ticketbooking();
    }
    return 0;
}

int cancelseats()
{
    int index;
    if (bookingCount == 0) 
    {
        printf("\tPlease Book Some Ticket First!\n");
        return 0;
    }
        printf("\n\t---------CANCEL_BOOKED_SEATS---------\n");
        printf("\tYour Bookings:\n");
    for (int i = 0; i < bookingCount; i++) 
    {
        printf("\t%d. Bus %d - %d seats booked\n", i + 1, bookedBus[i], bookedSeats[i] - cancelseatsarr[i]);
    }
    printf("\n\tEnter Booking Number To Cancel From: ");
    scanf("%d", &index);
    index--;
    if (index >= 0 && index < bookingCount) 
    {
        printf("\tEnter Number Of Seats to Cancel: ");
        scanf("%d", &cancelseat);
        if (cancelseat > (bookedSeats[index] - cancelseatsarr[index])) 
        {
            printf("\tInvalid! You are cancelling more seats than available.\n");
        } else 
        {
            cancelseatsarr[index] += cancelseat;
            printf("\n\tSeat Cancellation Successful!\n");
        }
    } 
    else 
    {
        printf("\tInvalid Booking Number!\n");
    }
    return 0;
}

void busstatus() 
{
    printf("\n\t---------BUS_STATUS---------\n");
    if (bookingCount == 0) 
    {
        printf("\tNo bookings yet!\n");
        return;
    }
    for (int i = 0; i < bookingCount; i++) 
    {
        currentseat = bookedSeats[i] - cancelseatsarr[i];
        printf("\n\tBus Number:             %d", bookedBus[i]);
        printf("\n\tSource City:            Delhi");
        switch (bookedBus[i]) 
        {
        case 105:
            printf("\n\tDestination City:       Uttar Pradesh");
            break;
        case 101:
            printf("\n\tDestination City:       Uttrakhand");
            break;
        case 124:
            printf("\n\tDestination City:       Madhya Pradesh");
            break;
        case 119:
            printf("\n\tDestination City:       Rajasthan");
            break;
        }
        printf("\n\tTotal Seats:            %d", Tseats);
        printf("\n\tAvailable Seats:        %d", Tseats - currentseat);
        printf("\n\tFare:                   %d*%d = %d\n", Fare, currentseat, Fare * currentseat);
    }
}