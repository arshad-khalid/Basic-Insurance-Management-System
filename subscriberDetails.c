#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include "details.h"

/*This is the first function and will be used to capture subscribers details and store them*/

subscriberDetails() {
    /*two files are opened, "details.txt" to store the subscribers details
    such as name, age, id, address, contact number, history, plan and subscription type
    while "claim.txt" will store the id, claimed amount, claim year and remaining amount*/

    FILE* F;
    FILE* f;
    F = fopen("details.txt", "a+");
    f = fopen("claim.txt", "a+");
    int counter = 0;
    char c;
    bool Flag;
    if (f == NULL) {
        printf("File not found\n\n");
        return 0;
    }
    if (F == NULL) {
        printf("File not found\n\n");
        return 0;
    }
    /*here we set initialize counter to zero, then we count the number of lines in the "details.txt" file, 
    this will also be the source of our ID generation*/

    else {
        for (c = getc(F); c != EOF; c = getc(F))
            if (c == '\n') {
                counter += 1;
            }
        int babyAge;
        printf("Please enter age or enter 999 to exit: ");
        scanf_s("%d",&detail[counter].age);

        while (detail[counter].age != EXIT)
        {
            if (detail[counter].age > 55) {
                printf("\n\nIneligible for the service\n\n");
                break;
            }
            else if (detail[counter].age == 0)
            {
                /*if the age is 0, we ask for days of the baby and see if baby is eligible for the service*/

                printf("\nEnter baby's age in days: ");
                scanf_s("%d", &babyAge);

                if (babyAge < 15)
                {
                    printf("\nNot eligible for the service until the baby is at least 15 days old");
                    break;
                }
                else {
                    Flag = true;
                    printf("\nBaby is eligible! \nBelow are the available plans:");
                    printf("\n\n 1) --------Plan 120 (RM)--------\n\n Monthly Subscription: 120RM\n Annual claim limit: 120,000RM\n Lifetime claim limit: 600,000RM");
                    printf("\n\n Benefits include:\n 120/day room charge.\n 250/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                    printf("\n\n 2) --------Plan 150 (RM)--------\n Monthly Subscription: 150RM\n Annual claim limit: 150,000RM\n Lifetime claim limit: 750,000RM");
                    printf("\n\n Benefits include:\n 200/day room charge.\n 400/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                    printf("\n\n 3) --------Plan 200 (RM)--------\n Monthly Subscription: 200RM\n Annual claim limit: 200,000RM\n Lifetime claim limit: 1,000,000RM");
                    printf("\n\n Benefits include:\n 200/day room charge.\n 700/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                    printf("\n\n Enter choice: ");
                    detail[counter].age = babyAge;
                    scanf_s("%d", &detail[counter].choice);

                   /*here for the baby, when eligible will have the option to choose all the plans available*/

                    while (detail[counter].choice > 0 && detail[counter].choice < 4) {
                        if (detail[counter].choice == 1) {
                            printf("Choose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                            scanf_s("%d", &detail[counter].type);
                            while (detail[counter].type == 1 || detail[counter].type == 2) {
                                if (detail[counter].type == 1) {
                                    claim[counter].remainingAmount = 120000;
                                    printf("\nSubscribed to Annual Claim");

                                }
                                else if (detail[counter].type == 2) {
                                    claim[counter].remainingAmount = 600000;
                                    printf("\nSubscribed to Lifetime Claim");
                                }
                                else {
                                    printf("\nInvalid Input, please try again");
                                    continue;
                                }
                                break;
                            }
                            break;
                        }
                        else if (detail[counter].choice == 2) {
                            printf("Choose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                            scanf_s("%d", &detail[counter].type);
                            while (detail[counter].type == 1 || detail[counter].type == 2) {
                                if (detail[counter].type == 1) {
                                    claim[counter].remainingAmount = 150000;
                                    printf("\nSubscribed to Annual Claim");
                                }
                                else if (detail[counter].type == 2) {
                                    claim[counter].remainingAmount = 750000;
                                    printf("\nSubscribed to Lifetime Claim");
                                }
                                else {
                                    printf("\nInvalid Input, please try again");
                                    continue;
                                }break;
                            }
                            break;
                        }
                        else if (detail[counter].choice == 3) {
                            printf("Choose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                            scanf_s("%d", &detail[counter].type);
                            while (detail[counter].type == 1 || detail[counter].type == 2) {
                                if (detail[counter].type == 1) {
                                    claim[counter].remainingAmount = 200000;
                                    printf("\nSubscribed to Annual Claim");
                                }
                                else if (detail[counter].type == 2) {
                                    claim[counter].remainingAmount = 1000000;
                                    printf("\nSubscribed to Lifetime Claim");
                                }
                                else {
                                    printf("\nInvalid Input, please try again");
                                    continue;
                                }break;
                            }
                            break;
                        }
                        else
                            printf("\nInvalid Input, please try again");
                    }
                }
            }
            /*this is when the age is set between 1-20, this block of code will show up for the user, this age 
            group too, will have all three options available to them */

            else if (detail[counter].age > 0 && detail[counter].age < 21) {
                Flag = true;
                printf("\n Below are the available plans: ");
                printf("\n\n 1) --------Plan 120 (RM)--------\n\n Monthly Subscription: 120RM\n Annual claim limit: 120,000RM\n Lifetime claim limit: 600,000RM");
                printf("\n\n Benefits include:\n 120/day room charge.\n 250/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                printf("\n\n 2) --------Plan 150 (RM)--------\n Monthly Subscription: 150RM\n Annual claim limit: 150,000RM\n Lifetime claim limit: 750,000RM");
                printf("\n\n Benefits include:\n 200/day room charge.\n 400/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                printf("\n\n 3) --------Plan 200 (RM)--------\n Monthly Subscription: 200RM\n Annual claim limit: 200,000RM\n Lifetime claim limit: 1,000,000RM");
                printf("\n\n Benefits include:\n 200/day room charge.\n 700/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                printf("\n\n Enter choice: ");
                scanf_s("%d", &detail[counter].choice);

                while (detail[counter].choice > 0 && detail[counter].choice < 4) {
                    if (detail[counter].choice == 1) {
                        printf("\n\nChoose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                        scanf_s("%d", &detail[counter].type);
                        while (detail[counter].type == 1 || detail[counter].type == 2) {
                            if (detail[counter].type == 1) {
                                claim[counter].remainingAmount = 120000;
                                printf("\nSubscribed to Annual Claim");
                            }
                            else if (detail[counter].type == 2) {
                                claim[counter].remainingAmount = 600000;
                                printf("\nSubscribed to Lifetime Claim\n");
                            }
                            else {
                                printf("Invalid Input, please try again");
                                continue;
                            }
                            break;
                        }
                        break;
                    }
                    else if (detail[counter].choice == 2) {
                        printf("Choose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                        scanf_s("%d", &detail[counter].type);
                        while (detail[counter].type == 1 || detail[counter].type == 2) {
                            if (detail[counter].type == 1) {
                                claim[counter].remainingAmount = 150000;
                                printf("\nSubscribed to Annual Claim");
                            }
                            else if (detail[counter].type == 2) {
                                claim[counter].remainingAmount = 750000;
                                printf("\nSubscribed to Lifetime Claim");
                            }
                            else {
                                printf("\nInvalid Input, please try again");
                                continue;
                            }break;
                        }
                        break;
                    }
                    else if (detail[counter].choice == 3) {
                        printf("Choose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                        scanf_s("%d", &detail[counter].type);
                        while (detail[counter].type == 1 || detail[counter].type == 2) {
                            if (detail[counter].type == 1) {
                                claim[counter].remainingAmount = 200000;
                                printf("\nSubscribed to Annual Claim");
                            }
                            else if (detail[counter].type == 2) {
                                claim[counter].remainingAmount = 1000000;
                                printf("\nSubscribed to Lifetime Claim");
                            }
                            else {
                                printf("\nInvalid Input, please try again");
                                continue;
                            }break;
                        }
                        break;
                    }
                    else {
                        printf("\nInvalid Input, please try again");
                        continue;
                    }
                }
            }
            /*here, for the ages between 21 to 40, only two plans will be available for them*/

            else if (detail[counter].age > 20 && detail[counter].age < 41) {
                Flag = true;
                printf("\n\n 1) --------Plan 150 (RM)--------\n Monthly Subscription: 150RM\n Annual claim limit: 150,000RM\n Lifetime claim limit: 750,000RM");
                printf("\n\n Benefits include:\n 200/day room charge.\n 400/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                printf("\n\n 2) --------Plan 200 (RM)--------\n Monthly Subscription: 200RM\n Annual claim limit: 200,000RM\n Lifetime claim limit: 1,000,000RM");
                printf("\n\n Benefits include:\n 200/day room charge.\n 700/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                printf("\n\n Enter choice: ");
                scanf_s("%d", &detail[counter].choice);

                while (detail[counter].choice > 0 && detail[counter].choice < 3) {
                    if (detail[counter].choice == 1) {
                        printf("Choose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                        scanf_s("%d", &detail[counter].type);
                        while (detail[counter].type == 1 || detail[counter].type == 2) {
                            if (detail[counter].type == 1) {
                                claim[counter].remainingAmount = 150000;
                                printf("\nSubscribed to Annual Claim");
                            }
                            else if (detail[counter].type == 2) {
                                claim[counter].remainingAmount = 750000;
                                printf("\nSubscribed to Lifetime Claim");
                            }
                            else {
                                printf("\nInvalid Input, please try again");
                                continue;
                            }break;
                        }
                        break;
                    }
                    else if (detail[counter].choice == 2) {
                        printf("Choose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                        scanf_s("%d", &detail[counter].type);
                        while (detail[counter].type == 1 || detail[counter].type == 2) {
                            if (detail[counter].type == 1) {
                                claim[counter].remainingAmount = 200000;
                                printf("\nSubscribed to Annual Claim");
                            }
                            else if (detail[counter].type == 2) {
                                claim[counter].remainingAmount = 1000000;
                                printf("\nSubscribed to Lifetime Claim");
                            }
                            else {
                                printf("\nInvalid Input, please try again");
                                continue;
                            }break;
                        }
                        break;
                    }
                    else {
                        printf("\nInvalid Input, please try again");
                        continue;
                    }
                }
            }
            /*finally for the ages above 40, they will have only one option for the insurance, 
            if the age is above 54, they will not be prompted for their input*/

            else if (detail[counter].age > 40) {
                Flag = true;
                printf("\n\n 1) --------Plan 200 (RM)--------\n Monthly Subscription: 200RM\n Annual claim limit: 200,000RM\n Lifetime claim limit: 1,000,000RM");
                printf("\n\n Benefits include:\n 200/day room charge.\n 700/day Intensive Care Unit (ICU).\n While hospital supplies & services, surgical fees and miscellaneous fees are subject to approval by ZeeMediLife ");
                printf("\n\n Enter choice: ");
                scanf_s("%d", &detail[counter].choice);

                while (detail[counter].choice == 1) {
                    if (detail[counter].choice == 1) {
                        printf("Choose subscription type\n\n1) Annual Subscription Claim\n2)Lifetime Subscription Claim\nOption: ");
                        scanf_s("%d", &detail[counter].type);
                        while (detail[counter].type == 1 || detail[counter].type == 2) {
                            if (detail[counter].type == 1) {
                                claim[counter].remainingAmount = 200000;
                                printf("\nSubscribed to Annual Claim");
                            }
                            else if (detail[counter].type == 2) {
                                claim[counter].remainingAmount = 1000000;
                                printf("\nSubscribed to Lifetime Claim");
                            }
                            else {
                                printf("\nInvalid Input, please try again");
                                continue;
                            }break;
                        }
                        break;
                    }
                    else
                    {
                        printf("\nInvalid input, please try again");
                        continue;
                    }
                }
            }
            else {
                printf("\nInvalid Input, please try again");
                continue;
            }
            if (Flag == true) {

                /*here we read inputs from the user*/
                getchar();
                detail[counter].id = counter;
                printf("\n\nEnter Full name: ");
                gets(detail[counter].name);
                printf("\nEnter Contact Number: ");
                gets(detail[counter].contactNo);
                printf("\nEnter Street: ");
                gets(detail[counter].address.street);
                printf("\nEnter City: ");
                gets(detail[counter].address.city);
                printf("\nEnter State (2 letters): ");
                gets(detail[counter].address.state);
                printf("\nAny extra information? (Previous diagnosis/ Medications/ Tests Results): ");
                gets(detail[counter].history);

                /*here we provide the summary of the user's data entered*/

                printf("Name: %s\n", detail[counter].name);
                printf("Age: %d\n", detail[counter].age);
                printf("ID number: %03d\n", detail[counter].id);
                printf("Choice chosen: %d\n", detail[counter].choice);
                printf("Subscription type: %d\n", detail[counter].type);
                printf("Contact No: %s\n", detail[counter].contactNo);
                printf("Address: %s, %s, %s.\n", detail[counter].address.street, detail[counter].address.city, detail[counter].address.state);
                printf("Previous History: %s\n", detail[counter].history);
                
                /*finally we assign the details and claim information to their respective structures, 
                and print the information entered to theie respective files*/

                claim[counter].id = detail[counter].id;
                claim[counter].claimedAmount = claim[counter].claimedAmount;

                //we set the year to 2018 since assumption made is that the system is being tested for one year only
                claim[counter].claimYear = 2018;

                fprintf(f, "%03d\t%d\t%d\t%d\n", claim[counter].id, claim[counter].claimYear, claim[counter].claimedAmount, claim[counter].remainingAmount);
                fprintf(F, "%s\t%d\t%03d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\n", detail[counter].name, detail[counter].age, detail[counter].id, detail[counter].choice, detail[counter].type, detail[counter].contactNo, detail[counter].address.street, detail[counter].address.city, detail[counter].address.state, detail[counter].history);
                break;
            }
        }
        printf("\n\n---Thank you---\n\n");
    }
    fclose(f);
    fclose(F);
    return 0;
}