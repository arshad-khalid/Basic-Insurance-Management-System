#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "details.h"
#include <ctype.h>

/*the fourth and last function is the search function, we use this
to search by id, name , age, claim limit type or plan*/
search() {
	FILE* f;
	FILE* F;
	int ch, counter = 0, option, id, z, plan, cLimit,age;
	char name[50], n;
	F = fopen("claim.txt", "r");
	f = fopen("details.txt", "r");

	if (f == NULL || F == NULL) {
		printf("\nFile(s) not found");
		return 0;
	}
	else {
		for (ch = getc(f); ch != EOF; ch = getc(f))
			if (ch == '\n')
				counter += 1;
	}
	//we ask user in what way do they want to search 

	printf("\n1) Search by ID\n2) Search by Name\n3) Search by Plan\n4) Search by Claim limit type\n5) Search by Age ");
	printf("\n\nOption: ");
	scanf_s("%d", &option);

	if (option == 1) {
		printf("\n\nEnter ID: ");
		scanf_s("%03d", &id);

		/*Option one is to search by id, and hence we ask for id and verify if that id is availabe*/

		for (z = 0; z < counter; z++) {
			if (detail[z].id == id) {
				//if id is found, relating data is printed
				printf("\n\nName: %s", detail[z].name);
				printf("\nAge: %d", detail[z].age);
				printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
				printf("\nContact No: %s", detail[z].contactNo);
				printf("\nHistory: %s", detail[z].history);
				printf("\nPlan type: %d", detail[z].choice);
				printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
				printf("\nClaimed Year: %d", claim[z].claimYear);
				printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
				printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
				printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				break;
			}
		}
	}
	else if (option == 2) {

		//second option is to search by name
		printf("\n\nEnter Name: ");
		getchar();
		gets(name);

		//tolower() function is used to make all the input characters small
		n = tolower(name);

		for (z = 0; z < counter; z++) {
			if (tolower(detail[z].name) == n) {
				printf("\n\nID No: %03d", detail[z].id);
				printf("\nAge: %d", detail[z].age);
				printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
				printf("\nContact No: %s", detail[z].contactNo);
				printf("\nHistory: %s", detail[z].history);
				printf("\nPlan type: %d", detail[z].choice);
				printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
				printf("\nClaimed Year: %d", claim[z].claimYear);
				printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
				printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
				printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
			}
		}
	}
	else if (option == 3) {
		/*third option is by plan type, this again depends on the age group 
		of the users, since they all registered with different choices*/

		printf("\n\nEnter Plan type: ");
		scanf_s("%d", &plan);



		for (z = 0; z < counter; z++) {
			/*since the choices are mixed up we arrange them */

			if (detail[z].age > 40) {
				if (detail[z].choice == 1) {
					detail[z].choice = 3;
				}
			}
			else {
				if (detail[z].age > 20 && detail[z].age < 41) {
					if (detail[z].choice == 1) {
						detail[z].choice = 2;
					}
					else
						detail[z].choice = 3;
				}
			}

			if (detail[z].choice == plan) {
				if (detail[z].age > 0 && detail[z].age < 21) {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				}
				else if (detail[z].age > 20 && detail[z].age < 41) {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				}
				else if (detail[z].age > 40) {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				}
			}
		}
	}
	else if (option == 4) {
		printf("\n\nEnter Claim limit amount: ");
		scanf_s("%d", &cLimit);

		//this is by claim amount type, and there are 6 claim limit types

		for (z = 0; z < counter; z++) {
			if (claim[z].remainingAmount == cLimit) {
				if (claim[z].remainingAmount == 120000) {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				}
				else if (claim[z].remainingAmount == 600000) {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				}
				else if (claim[z].remainingAmount == 150000) {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				}
				else if (claim[z].remainingAmount == 750000) {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				}
				else if (claim[z].remainingAmount == 200000) {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
				}
				else {
					printf("\n\nName: %s", detail[z].name);
					printf("\nID: %03d", detail[z].id);
					printf("\nAge: %d", detail[z].age);
					printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
					printf("\nContact No: %s", detail[z].contactNo);
					printf("\nHistory: %s", detail[z].history);
					printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
					printf("\nClaimed Year: %d", claim[z].claimYear);
					printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
					printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
					printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
					
				}
			}
		}
	}
	else if (option == 5) {
		printf("\n\nEnter Age: ");
		scanf_s("%d", &age);

		//last option is to search by age

		for (z = 0; z < counter; z++) {
			if (detail[z].age == age) {
				printf("\n\nName: %s", detail[z].name);
				printf("\nID: %03d", detail[z].id);
				printf("\nAge: %d", detail[z].age);
				printf("\nAddress: %s, %s, %s.", detail[z].address.street, detail[z].address.state, detail[z].address.city);
				printf("\nContact No: %s", detail[z].contactNo);
				printf("\nHistory: %s", detail[z].history);
				printf("\nType of subscription (1- Annual / 2- Lifetime): %d", detail[z].type);
				printf("\nClaimed Year: %d", claim[z].claimYear);
				printf("\nClaimed Limit type: %d", claim[z].remainingAmount);
				printf("\nClaimed Amount: %d", uclaim[z].claimedAmount);
				printf("\nRemaining Amount: %d", uclaim[z].remainingAmount);
			}
		}
	}
	else {
		printf("Invalid Option");
		return 0;
	}
	fclose(f);
	fclose(F);
	return 0;
}