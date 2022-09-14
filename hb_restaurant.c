/*	Programmed by: AGULTO, JULIANA MARIE B.
	Description: The purpose of this project aims to simulate the restaurant's activity. It should have a main menu that shows the characters: 
customer, waiter, and chef. Each character has their task or designated roles to play.
	Last modified: <December 7, 2019>   */

#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>

//Preprocessor directives

//character selection
void MainMenu(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five);//character selection

//customer
void CustomerNO(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five);// new or old customer
void CustomerAction(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); //customer actions
void CustomerOrder(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five);// customer order menu
int CustomerPay(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five);// customer payment
void CustomerStatus(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); // customer status

//waiter
void Waiter(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); //waiter actions
void SendOrder(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); //sent order to chef
void PendingOrder(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); // orders to be sent by chef
void ServeDish(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); //dish to be served
void WaiterList(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); //list of current customers and orders

//chef
void Chef(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); //chef action
void CookedNDish(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); // order to be cooked
void DeliverOrder(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five); //order to be delivered by chef 


/* This function is for character selection
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (<void>) no return value]
*/
void MainMenu(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	char cChar;
	int isDigit = 0; // just a variable
	int nConvert; // converting the user input
	int getValue1 = 0; // getting the value of arrCustomerStatus
	int getValue2 = 0; // getting the value of the status
	int totalCustomerStatus = 0; 
	int totalCustomer = 0;

	// this status is for checking whether the restaurant is close or not and if the customer has already paid
	for (i = 0; i < 21; i++)
	{
		getValue1 = arrCustomerStatus[i];
		if(getValue1 == 3)
		 {	
		 	totalCustomerStatus = totalCustomerStatus + 1;
		 }
	}   
	for (i = 0;  i < 20; i++)
	{
		getValue2 = arrCustomer[i];
		if(getValue2 > 0)
		{	
			totalCustomer = totalCustomer + 1;
		}
	}  
	if(totalCustomer == totalCustomerStatus && Status == 1)
	{
		for(i = 1; i <= 25; i++)
		printf(" ~");
		
		printf("\n\tTHE RESTAURANT IS NOW CLOSED\n");
		printf("\nTotal income :: P %.2f\n", TotalIncome);

		for(i = 1; i <= 25; i++)
			printf(" ~");		
		
		exit(0);
	}
	
	printf("\n");
	
	for(i = 1; i <= 49; i++)
		printf("-");
		
	printf("\n - - - - - - - - M A I N  M E N U - - - - - - - - \n");
		
	for(i = 1; i <= 49; i++)
		printf("-");
	
	printf("\n");
	printf("[1]	Customer\n");
	printf("[2]	Waiter\n");
	printf("[3]	Chef\n");
	printf("[4]	Exit\n");
	
	printf("Enter character choice :: ");
	while((cChar = getchar()) !='\n' && cChar != EOF) // to check if user input is integer only
    {
    	if(cChar < 0)
    		MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
		
		nConvert = (int)cChar - (int)48 ; //converting the ascii and the inputted integer
		if(isdigit(cChar))
		{
			printf("\n");
		}
		else
			isDigit = 1;   	
	}
  	
	if(isDigit == 1) // if user input has a character involved	
		MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);

	switch(nConvert)
	{
		case 1: 
				CustomerNO(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 2: 
				Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 3: 
				Chef(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 4: 
				main();
				break;
		default:
				printf("\n\t\tINVALID INPUT!!\n");
				MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
	}
	MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);			
}

/* This function is to check for new or old customer
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (<void>) no return value]
*/
void CustomerNO(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCustomerChoice;
	int found = 0;
	int nCountCustomer = 0;
	
	printf("\nAre you a new or old customer?? ");
	printf("\n[1]	New");
	printf("\n[2]	Old");
	printf("\n[3]	Exit");
	
	printf("\nEnter choice :: ");
	scanf("%d", &nCustomerChoice); // makes sure that user input is integer only
	
	switch(nCustomerChoice)
	{
		case 1:
				if(Status == 1) // to check if the restuarant is close
				{
					printf("\n\tSORRY, THE RESTAURANT IS CLOSED.\n");
					MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				}
				if(Status == 3) // to check if restaurant is full - 5 at a time
				{
					printf("\n\tSORRY, THE RESTAURANT IS FULL.");
					printf("\n\tPLEASE COME BACK LATER.\n");
					MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				}
				else
				{
					for(i = 0; i <= 20 && found == 0; i++) // to check if customer is new
					{
						if (arrCustomer[i] == 0)
						{	
							Five += 1; // counter for 5 at a time
							arrCustomer[i] = i + 1;
							found != 0;
							printf("\n     Kindly take note of your customer number.\n");	
							printf("\t   < < Customer #%02d > >\n", arrCustomer[i]);
							CustomerId = arrCustomer[i];
							
							if(CustomerId == 20) // if reached a total of 20 customers, restaurant will close
								Status = 1;
								
							if(Five == 5) // if reached a number of 5 customers, restaurant will wait until some leaves
								Status = 3;

							CustomerOrder(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
						}
					} 
				}
				break;
		case 2: 
				fflush(stdin);
				printf("\nWhat is your customer number?? :: ");
				scanf("%d", &CustomerId);		
				if(arrCustomer[CustomerId - 1] == CustomerId && arrCustomerStatus[CustomerId] != 3)
					CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				else
				{
					printf("\n\tSORRY, CUSTOMER NUMBER NOT FOUND!\n");
					CustomerNO(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				}
				break;
		case 3: 
				MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;	
		default:
				printf("\n\tINVALID INPUT!!\n");	
				CustomerNO(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
	}
	MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is for the customer actions
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (<void>) no return value]
*/
void CustomerAction(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCustomer_Counter = 1;
	char cChar;
	int isDigit = 0; 
	int nConvert; // converting the user input
	
	printf("\n");
	
	for(i = 1; i <= 49; i++)
		printf("-");
	
	printf("\n - - - - - - - - C U S T O M E R - - - - - - - -\n");
	
	for(i = 1; i <= 49; i++)
		printf("-");
		
	printf("\n");
	printf("[1]	Order\n");
	printf("[2]	Pay \n");
	printf("[3]	Display Customer Number \n");
	printf("[4]	Display Status \n");
	printf("[5]	Exit\n");
	
	printf("Enter choice :: ");
	while((cChar = getchar()) !='\n' && cChar != EOF) // to check if user input is integer only
    {
    	if(cChar < 0)
    		CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
		nConvert = (int)cChar - (int)48 ; //converting the lowercase of the alphabet and the inputted integer
		if(isdigit(cChar)) // is digit is a function
		{
			printf("\n");
		}
		else
			isDigit = 1;   	
	}
	if(isDigit == 1) // if user input has a character involved	
		CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
	
	switch(nConvert)
	{
		case 1: 
				if(arrCustomerStatus[CustomerId] == 0)
				{					
					printf("\n\tYou have already ordered!!\n");	
				}
				else if(arrCustomerStatus[CustomerId] == 1)
				{
					printf("\n\tWaiting for food to be served.\n");
				}
				else if(arrCustomerStatus[CustomerId] == 2)
				{
					printf("\n\tYou\'re currently eating.\n");
				}
				CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);		
				break;
		case 2: 
				CustomerPay(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 3: 
				printf("\t< < Customer #%02d > >\n", CustomerId);
				CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 4:	
				CustomerStatus(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking , Status, Five);
				break;	
		case 5: 
				MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		default:
				printf("\n\tINVALID INPUT!!\n");
				CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
	}
	CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is for the customer menu - to order dish
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (<void>) no return value]
*/
void CustomerOrder(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCountOrder; 
	char sChar;
	int nCounter = 2;
	int nFoodCount; 
	float fTotalFood; // total amount of food ordered
	int x; // passing the value of arrCustomerOrder

		
	printf("\n");
		
	for(i = 1; i <= 49; i++)
		printf("+");
		
	printf("\n\t\t M E N U \n");
		
	for(i = 1; i <= 49; i++)
		printf("+");
	
	printf("\nCODE   \t\t\t\t\t   PRICE");
	printf("\n[1]   Creamy Courgette Lasagne------------P400.00");
	printf("\n[2]   Walnut & Red Pepper Pesto Pasta-----P320.00");
	printf("\n[3]   Special Seafood & Saffron Pasta-----P430.00");
	printf("\n[4]   Springtime Pasta--------------------P300.00");
	
	printf("\n\n[MAX 3 ORDERS ONLY]\n");
	printf("How many order(s) do you want? :: ");
	scanf("%d", &nCountOrder); // makes sure that user input is integer only
		
	if(nCountOrder > 3 || nCountOrder < 0)
	{
		printf("\nYou can only order a maximum of 3 dishes only\n");
		CustomerOrder(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
	}
	
	nCounter = 2;

	for(nFoodCount = 1; nFoodCount <= nCountOrder; nFoodCount++)
	{
		fflush(stdin);
		do{
			printf("What is your order (%d) :: ", nFoodCount);
			scanf("%d", &arrCustomerOrder[CustomerId * 3 - nCounter]);
			x = arrCustomerOrder[CustomerId * 3 - nCounter];
		}while(x < 0 || x > 4);
		nCounter--;
							
		//food price
		if(x == 1)
			fTotalFood += 400.0;

		else if(x == 2)		
			fTotalFood += 320.0;
			
		else if(x == 3)
			fTotalFood += 430.0;
			
		else if(x == 4)
			fTotalFood += 300.0;
		else 
			fTotalFood = fTotalFood;		
	}
		arrCustomerPrice[CustomerId] = fTotalFood;
		printf("\n     Your order will be ready in a few minutes.\n ");
		printf("\t\t   Thank you ~\n");
		arrCustomerStatus[CustomerId] = 1; // the status of the customer will change to waiting
		
		if(arrCustomerOrder[20] > 0) // if reached a total of 20 dishes, restaurant will close
			Status = 1;
		
	CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is for the customer to pay their bills after eating
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (<int>) return nChange]
*/
int CustomerPay(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	float nPay;
	float nChange;
	float x; // passing the value of arrCustomerPrice[CustomerId]
	int nCounter = 2;
	
	if(arrCustomerStatus[CustomerId] == 2)
	{
		if(arrCustomerOrder!= 0)
		{
			x = arrCustomerPrice[CustomerId];
			TotalIncome += x;
			
			printf("\nThe total bill is P%.2f", x);
			printf("\nChange for P");
			scanf("%f", &nPay);

			if(nPay >= x)
			{
				printf("\n");
						
				for(i = 1; i <= 49; i++)
					printf("+");
						
				printf("\n\t\t R E C E I P T \n");
						
				for(i = 1; i <= 49; i++)
					printf("+");	
					
				printf("\nTOTAL BILL :: P%.2f", x);					
				nChange = nPay - x;
				printf("\n    CHANGE :: P%.2f\n", nChange);
				printf("\n\tTHANK YOU!! PLEASE COME AGAIN!!\n\n");
				arrCustomerStatus[CustomerId] = 3;
				Five -= 1;
				if(Status == 3)	// if the status is full
					Status = 0; // it will turn back to open
				MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
			}
			else
			{
				printf("\n\tPAYMENT TOO SMALL\n");
				CustomerPay(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
			}
		}
	}	
	else
	{
		printf("\t.FOOD NOT YET SERVED.\n");
		CustomerAction( CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five); //customer actions	
	}
	return nChange;
}

/* This function is to check the status of the customer either waiting or eating
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (<int>) return nChange]
*/
void CustomerStatus(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{	
	if(arrCustomerStatus[CustomerId] == 1)
	{
		printf("\nStatus :: . . WAITING FOR FOOD TO BE SERVED . . \n");
	}
	
	else if(arrCustomerStatus[CustomerId] == 2)
	{
		printf("\nStatus :: . . E A T I N G . . \n");
	}
	
	else if(arrCustomerStatus[CustomerId] == 3)
	{
		printf("\nStatus :: . . YOU HAVE ALREADY PAID . . \n");
	}
	CustomerAction(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is for the waiter actions
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (void) no return value]
*/
void Waiter(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	char cChar;
	int isDigit = 0; // just a variable
	int nConvert; // converting the user input
	
	printf("\n");
	
	for(i = 1; i <= 49; i++)
		printf("-");
		
	printf("\n - - - - - - - - - W A I T E R - - - - - - - - - \n");
	
	for(i = 1; i <= 49; i++)
		printf("-");
	
	printf("\n[1]	Send order to chef");
	printf("\n[2]	List pending order");
	printf("\n[3]	Serve dish");
	printf("\n[4]	List current customers and ordered food");
	printf("\n[5]	Display income for the day");
	printf("\n[6]	Close the restaurant");
	printf("\n[7]	Exit");	
		
	printf("\nEnter choice :: ");
	while((cChar = getchar()) !='\n' && cChar != EOF) // to check if user input is integer only
    {
    	if(cChar < 0)
    		Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
	
		nConvert = (int)cChar - (int)48 ; //converting the lowercase of the alphabet and the inputted integer
		if(isdigit(cChar)) // is digit is a function
		{
			printf("\n");
		}
		else
			isDigit = 1;   	
	}
  	
	if(isDigit == 1) // if user input has a character involved	
		Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
	
	switch(nConvert)
	{
		case 1:	
				SendOrder(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 2:	
				PendingOrder(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 3:	
				ServeDish(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 4:	
				WaiterList(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 5:	
				if(TotalIncome == 0) // if the customer has already paid
					printf("\tNO CUSTOMER PAYMENT FOUND\n");
				else
					printf("\n\tTotal income for the day is P%.2f\n", TotalIncome);
				Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);	
				break;
		case 6:	
				Status = 1; // close the restaurant
				printf("\n\t X x X x RESTAURANT IS CLOSING x X x X\n");
				MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 7:	
				MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		default :
				printf("\t\tINVALID INPUT!!\n");
				Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
	}			
	
	Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);			
}

/* This function is for sending the order to the chef after the customers have ordered
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (<void>) no return value]
*/
void SendOrder(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCustomer;
	unsigned int nChef = ChefList;
	int nCounter;
	int nCount1;
	int nCount2;

	if(CustomerId > 0)
	{
		printf("\n");
			
		for(i = 1; i <= 49; i++)
			printf("-");
				
		printf("\n\tL I S T  O F  O R D E R ( S )\n");
			
		for(i = 1; i <= 49; i++)
			printf("-");
		
		for(nCustomer = 1; nCustomer <= 20; nCustomer++)
		{
			if(arrCustomer[nCustomer] >= 0 && (arrCustomerStatus[nCustomer] == 1 ||arrCustomerStatus[nCustomer] == 2))
			{
				printf("\nCustomer #%02d \n",  nCustomer);
					
				nCounter = 2; // re-initialize
					
				for(nCount1 = 1; nCount1 <= 3; nCount1++)
				{
					printf("\tCustomer Order # %d \n",  arrCustomerOrder[nCustomer * 3 - nCounter]);
					arrSendToChef[nCustomer * 3 - nCounter] = arrCustomerOrder[nCustomer * 3 - nCounter];
					nCounter--;
				}
			}
		}
		printf("\nEnter Customer ID :: " );
		scanf("%u", &nChef);
		
		if(nChef < 0)
		{
			printf("\nINVALID INPUT!\n");
			Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
		}
			
				
		arrPending[ChefList] = nChef;
		
		for(nCount2 = 0; nCount2 <= ChefList; nCount2++)
		{
			printf("\nChef List :: %d", arrPending[nCount2]);
		}
		ChefList = ChefList + 1 ;
		printf("\nChef Count :: %d\n", ChefList);
	}
	
	else
		printf("\t\tNO ORDER(S) FOUND\n");
	
	Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);

}

/* This function is for sending the order to the chef after the customers have ordered
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (<void>) no return value]
*/
void PendingOrder(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCount;
	int nCounter = 2;
	int nCustomer;
	
	if(CustomerId > 0)
	{
		printf("\n");
		
		for(i = 1; i <= 49; i++)
			printf("-");
					
		printf("\n   L I S T  O F  P E N D I N G  O R D E R ( S )\n");
				
		for(i = 1; i <= 49; i++)
			printf("-");
				
		for(nCustomer = 1; nCustomer <= 20; nCustomer++)
		{
			if(arrCustomer[nCustomer] >= 0 && (arrCustomerStatus[nCustomer] == 1 ||arrCustomerStatus[nCustomer] == 2))
			{
				printf("\nCustomer # %d \n",  nCustomer);
					
				nCounter = 2; // re-initialize
						
				for(nCount = 1; nCount <= 3; nCount++)
				{
					printf("\tCustomer Order # %d \n",  arrSendToChef[nCustomer * 3 - nCounter]);
					nCounter--;
				}
			}
		}
	}
	
	else
		printf("\t\tNO ORDER(S) FOUND\n");
		
	Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is to send the dish that the chef have delivered to the customer
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (void) no return value]
*/
void ServeDish(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCounter = 2;
	int nCustomer;
    int nCount;
    int nDeliver;
		
	for(i = 1; i <= 49; i++)
		printf("-");
				
	printf("\n\tS E R V E  D I S H\n");
			
	for(i = 1; i <= 49; i++)
		printf("-");
		
	for(nDeliver = 0; nDeliver <= 20; nDeliver++)
	{
		nCustomer = arrPending[nDeliver];
	
		if(nCustomer > 0 )
		{
			printf("\nCustomer #%02d \n", nCustomer);
				
			nCounter = 2; // re-initialize
				
			for(nCount = 1; nCount <= 3; nCount++)
			{
				printf("\tCustomer Order # %d \n",  arrDoneCooking[nCustomer* 3 - nCounter]);
				arrChefServed[nCustomer * 3 - nCounter] = arrDoneCooking[nCustomer * 3 - nCounter];
				nCounter--;
			}
		}
	}
	
	printf("\nDELIVER");
	printf("\nCustomer number :: ");
	scanf("%d", &nCustomer);

	for(nDeliver = 0; nDeliver <= 20; nDeliver++)
	{
		if(arrPending[nDeliver] == nCustomer)
		{
			nCounter = 2; // re-initialize
				
			for(nCount = 1; nCount <= 3; nCount++)
			{	
				printf("\tCustomer Order # %d \n",  arrDoneCooking[nCustomer* 3 - nCounter]);
				arrDoneCooking[nCustomer * 3 - nCounter] = 0;
				arrSendToChef[nCustomer * 3 - nCounter] = 0;
				nCounter--;
			}
			printf("\n\tSUCCESSFULLY DELIVERED!\n");
			arrCustomerStatus[nCustomer] = 2; // the status of the customer will change to eating
			break;
		}	
		else
		{
			printf("\n\tSORRY, CUSTOMER NUMBER NOT FOUND!\n");
		}
	}
	Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is to check for the list of current customers and their ordered food
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (void) no return value]
*/
void WaiterList(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCustomer;
	int nCount;
	int nCountCustomer;
	int nCounter = 2;
	
	if(CustomerId == 0)
		printf("\t\tNO CUSTOMER(S) FOUND\n");
	else
	{
		for(i = 1; i <= 49; i++)
			printf("-");
				
			printf("\n  LIST OF CURRENT CUSTOMERS AND ORDERED FOOD\n");
			
		for(i = 1; i <= 49; i++)
			printf("-");
		
		for(nCustomer = 1; nCustomer <= 20; nCustomer++)
		{
			if	(arrCustomer[nCustomer] >= 0 && (arrCustomerStatus[nCustomer] == 1 || arrCustomerStatus[nCustomer] == 2)) // to check the current customers
			{
				printf("\nCustomer # %02d \n", nCustomer);
				for(nCount = 1; nCount <= 3; nCount++)
				{
					printf("\tCustomer Order # %d \n", arrCustomerOrder[nCustomer * 3 - nCounter]);
					nCounter--;
				}
				if(arrCustomer[nCustomer] >= 0 && arrCustomerStatus[nCustomer] == 1)
					printf("\tCustomer Status :: Waiting \n");
					
				else if(arrCustomer[nCustomer] >= 0 && arrCustomerStatus[nCustomer] == 2)
					printf("\tCustomer Status :: Eating \n");
					
			}
		} 
	}
	Waiter(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is for the chef's action
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (void) no return value]
*/
void Chef(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	char cChar;
	int nConvert;
	int isDigit;
	
	printf("\n");
		
	for(i = 1; i <= 49; i++)
		printf("-");
	
	printf("\n - - - - - - - - - - C H E F - - - - - - - - - - \n");
	
	for(i = 1; i <= 49; i++)
		printf("-");
	
	printf("\n[1]	Cook N Dishes");
	printf("\n[2]	Deliver");
	printf("\n[3]	Exit");
	printf("\nEnter choice :: ");
	while((cChar = getchar()) !='\n' && cChar != EOF) // to check if user input is integer only
    {
    	if(cChar < 0)
    		Chef(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
		
		nConvert = (int)cChar - (int)48 ; //converting the lowercase of the alphabet and the inputted integer
		if(isdigit(cChar)) // is digit is a function
		{
			printf("\n");
		}
		else
			isDigit = 1;   	
	}
  	
	if(isDigit == 1) // if user input has a character involved	
		Chef(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
	
	switch(nConvert)
	{
		case 1: 
				CookedNDish(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking,  Status, Five);
				break;
		case 2: 
				DeliverOrder(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		case 3:	
				MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
				break;
		default:
				printf("\n\tINVALID INPUT!!\n");
				Chef(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status,Five);
				break;
	}
	Chef(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is to check for the dish that were sent by the waiter and cook the dish = max of 3 dishes can be cooked
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (void) no return value]
*/
void CookedNDish(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCount;
	int nCounter = 2;
	int nCountNumber;
	int nCustomer;
	unsigned int nCookDish;
	int nCNumber;

	printf("\n");
			
	for(i = 1; i <= 49; i++)
		printf("-");
			
	printf("\n\t\tC H E F \' S  L I S T\n");
		
	for(i = 1; i <= 49; i++)
		printf("-");

	for(nCustomer = 0; nCustomer <= 20; nCustomer++)
	{
		if(arrPending[nCustomer] > 0 )
		{
			printf("\nCustomer #%02d \n",  arrPending[nCustomer]);
			nCNumber =arrPending[nCustomer];
			nCounter = 2; // re-initialize
				
			for(nCount = 1; nCount <= 3; nCount++)
			{
				printf("\tCustomer Order # %d \n",  arrSendToChef[nCNumber * 3 - nCounter]);
				arrDoneCooking[nCNumber * 3 - nCounter] = arrSendToChef[nCNumber * 3 - nCounter];
				nCounter--;
			}
		}
	}	
	printf("\n[MAX 3 DISHES ONLY]\n");
	printf("Enter number of dishes to be cooked :: ");
	scanf("%u", &nCookDish);

	if(nCookDish > 3) // if exceeded 3 dishes
	{
		printf("\n\tYou can only cook 3 dishes\n");
		CookedNDish(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
	}
	
	printf("\n\tFINISHED COOKING\n");
	
	Chef(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

/* This function is to be delivered by the chef after cooking the food
[@param (int) CustomerId is the customer number]
[@param (float) TotalIncome is the total income for the day of the restaurant]
[@param (int) ChefList is the first and last arrangement of the customers who the waiter sent to chef]
[@param (int*) arrCustomer is the number of customers]
[@param (int*) arrCustomerOrder is the ordered dishes of the customer]
[@param (float*) arrCustomerPrice is the price of the ordered dishes of the customer]
[@param (int*) arrCustomerStatus is the current status of the customer]
[@param (int*) arrSendToChef is the dishes sent to chef]
[@param (int*) arrPending is the dish currently at the chef]
[@param (int*) arrChefServed is the dish that the chef delivered to waiter]
[@param (int*) arrDoneCooking is the dish that the chef have cooked]
[@param (int) Status is the status of the restaurant either open or close]
[@param (int) Five counter of 5 customers at a time]
[@return (void) no return value]
*/
void DeliverOrder(int CustomerId, float TotalIncome, int ChefList, int *arrCustomer, int *arrCustomerOrder, float *arrCustomerPrice, int *arrCustomerStatus, int *arrSendToChef, int *arrPending, int *arrChefServed, int *arrDoneCooking, int Status, int Five)
{
	fflush(stdin);
	int i;
	int nCounter = 2;
	int nCustomer;
	int nDeliver;
	int nCount;
	int cnt;
			
	printf("\n");
			
	for(i = 1; i <= 49; i++)
		printf("-");
			
	printf("\n\t\tD E L I V E R  F O O D\n");
			
	for(i = 1; i <= 49; i++)
		printf("-");
		
		for(nDeliver = 0; nDeliver <= 20; nDeliver++)
		{
        	nCustomer = arrPending[nDeliver];	
			if(nCustomer > 0 )
			{
				printf("\nCustomer #%02d \n", nCustomer);
				
				nCounter = 2; // re initialize
				
				for(nCount = 1; nCount <= 3; nCount++)
				{
					printf("\tCustomer Order # %d \n",  arrDoneCooking[nCustomer* 3 - nCounter]);
					arrChefServed[nCustomer * 3 - nCounter] = arrDoneCooking[nCustomer * 3 - nCounter];
					nCounter--;
				}
			}
		}
		printf("\nDELIVER");
		printf("\nEnter customer number :: ");
		scanf("%d", &nCustomer);
			
		for(nDeliver = 0; nDeliver <= 20; nDeliver++)
		{
			cnt = arrPending[nDeliver];

			if(arrPending[nDeliver] == nCustomer)
			{
				printf("\n\tSUCCESSFULLY DELIVERED\n");
				break;
			}
			else
			{
				printf("\n\tSORRY, CUSTOMER NUMBER NOT FOUND!\n");
			}
		}
	Chef(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking , Status, Five);
}

/* This function is the main
[@return (int) returns to the operating system]
*/
int main()
{
	int i;
	int CustomerId = 0;
	float TotalIncome = 0;
	int ChefList = 0;
	int Status = 0; // restaurant is open
	int Five = 0; //five customers at a time
	
	//customer
	int arrCustomer [21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //number of customers
	int arrCustomerOrder [63] = {0}; // customer order
	float arrCustomerPrice [21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // food price
	int arrCustomerStatus [21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // customer status	
	
	//waiter
	int arrSendToChef[63] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // orders to be sent to chef
	int arrPending[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // orders currently at chef
	
	//chef
	int arrDoneCooking[63] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // finished cooking by chef
	int arrChefServed[63] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // served by chef
	
	printf("\n");
	printf("\n== WELCOME TO ");
	for(i = 1; i <= 35; i++)
		printf("=");
	
	printf("\n = = = = = = = H A V E N  B R O O K = = = = = = = \n");
	
	for(i = 1; i <= 35; i++)
		printf("=");
		printf(" RESTAURANT ==");
	
	printf("\n");	
	
	printf("\n NOTE :: ONLY ENTER THE NUMBER OF YOUR CHOICE!! \n");
	
	MainMenu(CustomerId, TotalIncome, ChefList, arrCustomer, arrCustomerOrder, arrCustomerPrice, arrCustomerStatus, arrSendToChef, arrPending, arrChefServed, arrDoneCooking, Status, Five);
}

