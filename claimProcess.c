
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "details.h"

/*Below is the second function for our system, this
is used to file the claims for the subscribers*/

claimProcess() {
	FILE* file;
	FILE* f;
	FILE* F;
	/*we open the files in reand and append+write more respectively*/

	file = fopen("details.txt", "r");
	f = fopen("claim.txt", "r");
	F = fopen("updatedclaims.txt", "w");
	
	int ch, j, id, counter = 0;
	int roomType, roomCost=0, days, ssCost, surgicalFees, other,borne;
	bool flag=false;
	if (file == NULL) {
		printf("\nFile not found");
		return 0;
	}
	else {
		//we count number of lines
		for (ch = getc(file); ch != EOF; ch = getc(file))
			if (ch == '\n')
				counter += 1;

		printf("\nEnter ID: ");
		scanf_s("%03d", &id);

		//we use those number of lines to set the limit for the loop
		for (j = 0; j < counter; j++) {
			if (detail[j].id == id) { //if input matches id in the file, flag is set to true, else it is set to false
				flag = true;
				break;
			}
		}
		if (flag == false) {
			printf("Subscriber/ID does not exist");
			return 0; //maybe try break
		}
		/*after id is verified, we print the users name and age*/

		printf("\n\n Name: %s", detail[j].name);
		printf("\n Age: %d", detail[j].age);
		printf("\n\nEnter the following claim detais:");
		
		while (flag==true){ //here we will ask for details of the room and other relevant data that is needed
			printf("\n\nType of room stayed in:\n1)Normal Room\n2)Intensive Care Unit\nOption: ");
			scanf_s("%d", &roomType);
			if (detail[j].age > 0 && detail[j].age < 21) { 

				//since the options differe for each age group, we divide the options for each age group
				
				if (detail[j].choice == 1) {
					if (roomType == 1) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 120;
					}
					else if (roomType == 2) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 250;
					}
					else {
						printf("\n\nInvalid Room type, please try again");
						continue;
					}
				}
				else if (detail[j].choice == 2) {
					if (roomType == 1) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 150;
					}
					else if (roomType == 2) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 400;
					}
					else {
						printf("\n\nInvalid Room type, please try again");
						continue;
					}
				}
				else { //if choice==3
					if (roomType == 1) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 200;
					}
					else if (roomType == 2) {
					printf("\n\nEnter days stayed in room: ");
					scanf_s("%d", &days);
					roomCost = 700;
					}
					else {
						printf("\n\nInvalid Input, please try again");
						continue;
					}
				}
			}
			else if (detail[j].age > 20 && detail[j].age < 41) {
				if (detail[j].choice == 1) {
					if (roomType == 1) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 150;
					}
					else if (roomType == 2) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 400;
					}
					else {
						printf("\n\nInvalid Room type, please try again");
						continue;
					}
				}
				else {//if choice==2
					if (roomType == 1) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 200;
					}
					else if (roomType == 2) {
						printf("\n\nEnter days stayed in room: ");
						scanf_s("%d", &days);
						roomCost = 700;
					}
				}
			}
			else {//age above 40
				if (roomType == 1) {
					printf("\n\nEnter days stayed in room: ");
					scanf_s("%d", &days);
					roomCost = 200;
				}
				else if (roomType == 2) {
					printf("\n\nEnter days stayed in room: ");
					scanf_s("%d", &days);
					roomCost = 700;
				}
				else {
					printf("\n\nInvalid Input, please try again");
					continue;
				}
			}
			printf("\nEnter cost of supplies & services: ");
			scanf_s("%d", &ssCost);
			printf("\nEnter Surgical fees: ");
			scanf_s("%d", &surgicalFees);
			printf("\nOther extra charges: ");
			scanf_s("%d", &other);

			//we calculate the claim amount and is saved to claim structure
			claim[j].claimedAmount = (roomCost * days) + ssCost + surgicalFees + other;

			// here is when we check if expense is higher than eligible claim amount 
			if (claim[j].claimedAmount >= claim[j].remainingAmount) {
				
				//if expense is higher than claimable amount
				borne = claim[j].claimedAmount - claim[j].remainingAmount;
				claim[j].remainingAmount = 0;
				claim[j].claimedAmount = claim[j].claimedAmount - borne;
				printf("\n\nName: %s\nID: %03d\nClaim Year: %d\nClaimed Amount: %d\nRemaining balance: %d\nAmount to be borne by subscriber: %d", detail[j].name, detail[j].id, claim[j].claimYear, claim[j].claimedAmount,claim[j].remainingAmount, borne);
			}
			else {
				//if claimable amount is higher than expense
				claim[j].remainingAmount -= claim[j].claimedAmount;
				printf("\n\nName: %s\nID: %03d\nClaim Year: %d\nClaimed Amount: %d\nRemaining amount: %d", detail[j].name, detail[j].id, claim[j].claimYear, claim[j].claimedAmount, claim[j].remainingAmount);
			}
			/*finally we assign the id from detail struct to claim struct so it can be saved 
			to file and be able to identify who's information belongs to who, and print those details to claim.txt file*/

			uclaim[j].id = claim[j].id;
			uclaim[j].claimYear = claim[j].claimYear;
			uclaim[j].claimedAmount = claim[j].claimedAmount;
			uclaim[j].remainingAmount = claim[j].remainingAmount;

			claim[j].id = detail[j].id;
			for (j = 0; j < counter; j++) {
				fprintf(F, "%03d\t%d\t%d\t%d\n", uclaim[j].id, uclaim[j].claimYear, uclaim[j].claimedAmount, uclaim[j].remainingAmount);
			}
			//fprintf(f, "%03d\t%d\t%d\t%d\n", claim[j].id, claim[j].claimYear, claim[j].claimedAmount, claim[j].remainingAmount);
			break;
		}
	}
	fclose(F);
	fclose(file);
	fclose(f);
	return 0;
}
		
//changed claim.txt to w only and the for loop below
//changed scanf to gets