/*below are three define elements that will be used thoughout the file
and this is why they are at the header file*/
#define EXIT 999
#define MAX 100
#define LENGTH 1000

/*Below are two structures that will be used to store details of a subscriber*/
struct subscriberDetail
{
	char name[50],contactNo[15],history[50];
	int id, age, choice,type;
	struct
	{
		char street[15], city[15], state[3];
	}address;
};
struct claimProcess {
	int id, claimYear, claimedAmount, remainingAmount;
};
struct updatedClaim {
	int id, claimYear, claimedAmount, remainingAmount;
};

/*Since we have made a structure, we will need to create an array of structure 
to store details of multiple subscribers*/
struct subscriberDetail detail[MAX];
struct claimProcess claim[MAX];
struct updatedClaim uclaim[MAX];

/*Below are functions that will be accessible to the main source file*/
getData();
subscriberDetails(); //1
claimProcess(); //2
accountsInformation(); //3
search(); //4