#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

//CREATING  DATATYPE PASSENGER FOR STORING ALL DATA RELATED TO PASSENGERS USING STRUCT
struct passenger
{
	char passport[6];
	char name[15];
	int seat_num;
	char contact_num[15];
	char aadhar_num[15];                 //temp=dummy end=stream
	struct passenger *following;
}
*begin, *end;
struct passenger *temp;

//STARTING OF MAIN FUNCTION
void main()
{
	void book_ticket(int x), cancel_ticket(), update_details(), print_details(), check_seat_status(), savefile();  //function prototypes reserve=book_tickets cancel=cancel_tickets display=printdetails
	int choice;
	begin = end = NULL;  //initialize the struct pointers to NULL
	int num=152;

	do
	{
printf("\n\n\t**********************************************");
printf("\n\n\t\t WELCOME TO RAJPUTANA AIRWAYS \n");
printf("\n\t**********************************************");
printf("\n\t WISHING YOU HAPPY JOURNEY");
printf("\n\n\t Please enter your choices for help!! ");
printf("\n\n\t ENTER 1 FOR RESEVATION OF TICKET ");
printf("\n\t ENTER 2 FOR PRINTING YOUR TICKET ");
printf("\n\t ENTER 3 FOR CANCELLING OF TICKET ");
printf("\n\t ENTER 4 FOR UPDATING OF YOUR TICKET DETAILS ");
printf("\n\t ENTER 5 FOR CHECKING SEAT STATUS ");
printf("\n\t ENTER 6 FOR EXITING THE SERVICE ");
printf("\n\t\t");
		//USE OF SWITCH CASE
		scanf("%d", &choice);
		 fflush(stdin);
		system("cls"); //to clear the screen
switch(choice)
		{
		case 1:
		    {
			book_ticket(num);
			num++;
			break;
		    }
		case 2:
		    {
			print_details();
			break;
		    }
		case 3:
			{
            cancel_ticket();
			break;
			}
		case 4:
		{
			update_details();
            break;
		}
			case 5:
		{
			check_seat_status();
			break;
		}
			case 6:
		{
            savefile();
			break;
		}
		default:
			printf("\n\n\t YOU HAVE ENTERED WRONG CHOICES");
			printf("\n\n\t PLEASE ENTER VALID CHOICES");
			printf("\n\n\t PLEASE ENTER OPTIONS BETWEEN 1 TO 6");
		} //END OF SWITCH CASE
	getch();
	}
	while (choice != 6);
		}
//************************ENTERING THE DETAILS*****************************//
void details()
{
    printf("\n\t Enter your  name:");
	gets(end->name);
	fflush(stdin);
	printf("\n\t Enter your  aadhar number:");
	gets(end->aadhar_num);
	fflush(stdin);
	printf("\n\t Enter your passport number:");
	gets(end->passport);
	 fflush(stdin);   //reads a line from stdin and stores it into the string pointed
	printf("\n\t Enter your contact number:");
	gets(end->contact_num);
	fflush(stdin);
}
void details();
//****************************************************book_ticket******************************//
void book_ticket(int x)
{
	end = begin;
	if (begin == NULL)
	{
		begin = end = (struct passenger*)malloc(sizeof(struct passenger));
		details();
		end->following = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t your seat number is: Seat A-%d", x);
		end->seat_num = x;
		return;
	}
	else if (x > 160) // WHEN SEAT IS FULL FOR THE FLIGHT
	{
		printf("\n\t\t Seat is full for this flight.");
		printf("\n\t\t Kindly check for other flight.");
		return;
	}
	else
	{
		while (end->following)
			end = end->following;
		end->following = (struct passenger *)malloc(sizeof(struct passenger));
		end = end->following;
		details();
		end->following = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t Your ticket is confirmed.");
		printf("\n\t Your seat number is: Seat F- %d", x);
		end->seat_num = x;
		return;
	}
}
//*******************************************************print_details**********************************//
void print_details()
{
    end = begin;
	while (end)
	{
	    printf("\n\n\t ************************************************************");
		printf("\n      PASSPORT NUMBER : %-6s", end->passport);
		printf("\n      NAME : %-15s", end->name);
		printf("\n      CONTACT NUMBER: %-15s", end->contact_num);
		printf("\n      AADHAR NUMBER: %-15s", end->aadhar_num);
		printf("\n      SEAT NUMBER: A-%d", end->seat_num);
		printf("\n\n\t ************************************************************");
		end = end->following;
	}
}
//*******************************************************cancel_ticket**********************************//
void cancel_ticket()
{
	end = begin;
	system("cls");
	char passport[6];
	printf("\n\tYou are about to cancel your ticket");
	printf("\n\n\t Enter your passport number to cancel the ticket:");
	gets(passport);
	fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		temp = begin;
		begin = begin->following;
		free(temp);
		printf(" \n\n\t Your ticket has been cancelled ");
		Sleep(800);
		return;
	}

	while (end->following)
	{
		if (strcmp(end->following->passport, passport) == 0)
		{
			temp = end->following;
			end->following = end->following->following;
			free(temp);
			printf("\n\t Your ticket is cancelled successfully");
			getch();
			Sleep(800);
			return;
		}
		end = end->following;
	}
	printf("\n\t passport number is wrong please check your passport");

}
//*******************************************************update_details**************************************//
void update_details()
{
    printf("\n\n\t Enter your details again");
    details();
}
//*******************************************************check_seat_status***********************************//
void check_seat_status()
{
book_ticket(56);
}
//******************************************************savefile**********************************************//
void savefile()
{
    FILE *fpointer = fopen("rajput files", "w");
	if (!fpointer)
	{
		printf("\n Error in opening file!");
		return;
		Sleep(800);
	}
	end = begin;
	while (end)
	{
		fprintf(fpointer, "%-6s", end->passport);
		fprintf(fpointer, "%-15s", end->name);
		fprintf(fpointer, "%-15s", end->contact_num);
		end = end->following;
	}
	printf("\n\n\t Details have been saved to a file (rajput files)");
	fclose(fpointer);
}
