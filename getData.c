#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include"details.h"

/*this function is to take all the data from the files before the system is started,
split the strings and store them in their respective structures accordingly*/

getData() {
	char l[LENGTH];
	FILE* ff;
	FILE* aa;
	FILE* zz;
	int count = 0,c=0;
	//we split the characters after every \t and \n since that is how we saved the data to the files
	const char* split = "\t\n";
	ff = fopen("details.txt", "r");
	aa = fopen("claim.txt", "r");
	zz = fopen("updatedclaims.txt", "r");

	if (ff == NULL || aa == NULL||zz==NULL) {
		//printf("File not found");
		return 0;
	}
	while (ff != NULL) {
		//here we get every line in the file and will be splitted below
		if (fgets(l, LENGTH - 1, ff) == NULL)
			break;
		if (l[1] == '\0')
			break;

		/*we use strcpy to copy the first split string to that particular structure, 
		while we use atoi for the numbers because they are strings in the file, 
		so they will be needed to be converted back to integers*/

		strcpy(detail[count].name, strtok(l, split));
		//strcpy copies the first split string (name) to the detail[count].name

		detail[count].age = atoi(strtok(NULL, split));
		detail[count].id = atoi(strtok(NULL, split));
		//atoi converts the string(number) back to an integer and is assigned to detail[count].id

		detail[count].choice = atoi(strtok(NULL, split));
		detail[count].type = atoi(strtok(NULL, split));
		strcpy(detail[count].contactNo, strtok(NULL, split));
		strcpy(detail[count].address.street, strtok(NULL, split));
		strcpy(detail[count].address.city, strtok(NULL, split));
		strcpy(detail[count].address.state, strtok(NULL, split));
		strcpy(detail[count].history, strtok(NULL, split));
		strcpy(l, "\0");
		count++;
	}

	//below is the same process, but for the claim file
	while (aa != NULL)
	{
		if (fgets(l, LENGTH - 1, aa) == NULL)
			break;
		if (l == "\n")
			break;
		claim[c].id = atoi(strtok(l, split));
		claim[c].claimYear = atoi(strtok(NULL, split));
		claim[c].claimedAmount = atoi(strtok(NULL, split));
		claim[c].remainingAmount = atoi(strtok(NULL, split));
		strcpy(l, "\0");
		c++;
	}
	//below again, same process for the updatedclaims file
	c = 0;
	while (zz != NULL)
	{
		if (fgets(l, LENGTH - 1, zz) == NULL)
			break;
		if (l == "\n")
			break;
		uclaim[c].id = atoi(strtok(l, split));
		uclaim[c].claimYear = atoi(strtok(NULL, split));
		uclaim[c].claimedAmount = atoi(strtok(NULL, split));
		uclaim[c].remainingAmount = atoi(strtok(NULL, split));
		strcpy(l, "\0");
		c++;
	}
	fclose(zz);
	fclose(ff);
	fclose(aa);
	return 0;
}