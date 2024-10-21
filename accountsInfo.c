#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "details.h"

/*this is the third function of the system and is used to access 2 types of account information*/

accountsInformation() {
	FILE* f;
	int choice, ch, counter = 0,k,totalAmount=0,no=0,z=1;
	f = fopen("updatedclaims.txt", "r");
	if (f == NULL) {
		printf("\nFile not found");
		return 0;
	}
	else {
		for (ch = getc(f); ch != EOF; ch = getc(f))
			if (ch == '\n')
				counter += 1;

		printf("\n1) Total amount claimed by Lifetime claim subscribers\n");
		printf("2) Total number of Annual Claim subscribers with exhaused amounts\n");
		printf("Choice: ");
		scanf_s("%d", &choice);

		//we use counter to set limit for the for loop

		if (choice == 1) {
			for (k = 0; k < counter; k++) {
				/*here choice refers to the lifetime claim subscriber amount, 
				and detail[counter].type is the type of subscription; type 1 is annual while type 2 is lifetime subscription*/ 

				if (detail[k].type == 1) {
					//we calculate the amount of total claimed amount and z is used to count the number of subscribers hence z is initialized to 1

					totalAmount += uclaim[k].claimedAmount;
					z++;

				}
			}
			printf("Total amount claimed by %d lifetime subscibers is %d", z, totalAmount);
		}
		else if (choice == 2) {
			for (k = 0; k < counter; k++) {
				//here we check for type 2 (which is lifetime subscription AND if that user has 0 amount left

				if (detail[k].type == 2 && uclaim[k].remainingAmount == 0) {
					no++;
				}
			}
			printf("The total number of subscribers who have exhaused their Annual claims are %d", no);
		}
		else {
			printf("Invalid Input");
			return 0;
		}
	}
	fclose(f);
	return 0;
}