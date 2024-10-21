/* Arshad Khalid Nazir (TP058473)
	12 October 2020 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "details.h"

/*This is going to be the main menu of the system
and all the functions from the other sources are going to be ran here*/

int main()
{
	int choice;
		do{
			getData();
			printf("\n\n~~~~~~~~ ZEE MEDI LIFE INSURANCE ~~~~~~~~\n\n");
			printf("1) Insurance Plan Subscription\n");
			printf("2) Claim Processing\n");
			printf("3) Account Information\n");
			printf("4) Search\n");
			printf("5) Exit\n\n");
			printf("Option: ");
			scanf_s("%d", &choice);

			if (choice == 0) {
				printf("Invalid Input, please try again");
				continue;
			}
			if (choice > 5) {
				printf("Invalid Input, please try again");
				continue;
			}
			if (choice == 1) {
				subscriberDetails();
				continue;
			}
			if (choice == 2) {
				claimProcess();
				continue;
			}
			if (choice == 3) {
				accountsInformation();
				continue;
			}
			if (choice == 4) {
				search();
			}
		} while (choice !=5);
	return 0;
}