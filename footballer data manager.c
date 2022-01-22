#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//	Declaration of Structure Globally
struct footballer
{
	int regNum;
	char name[50];
	int age;
	int matchesPlayed;
	int totalGoalsScored;
};
struct footballer footballerData[10];

//	Declaration of Funtion
void addFootballer();
void deleteFootballer();
void searchFootaballerByName();
void searchFootaballerByMatchesPlayed();
void searchFootaballerByTotalGoalsScored();
void displayAllRecords();
void readFileRecords();

int noOfRecords = 10;

main()
{
	while(1)
	{
		int op;
		
		printf("\t\t\t\tFOOTBALLER RECORDS\n");
		printf("\t\t\t\t==================");
		printf("\n\nMAIN MENU\n\n");
		printf("1. Add Footballer\n2. Delete Footballer\n3. Search Footballer (by name)\n4. Search Footballer (by no. of match played)\n5. Search Footballer (by no. of goals scored)\n6. Display All Record\n7. Exit\n\n");
		printf("=> Please enter from the given choice (1 - 7): ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1:
				addFootballer();
				break;
			case 2:
				deleteFootballer();
				break;
			case 3:
				searchFootaballerByName();
				break;
			case 4:
				searchFootaballerByMatchesPlayed();
				break;
			case 5:
				searchFootaballerByTotalGoalsScored();
				break;
			case 6:
				displayAllRecords();
				break;
			case 7:
				exit(0);
				break;
		}
	}
}

//	Definition of User-Defined Funtions
void addFootballer()
{
	system("cls");
	int regNum;
	char name[50];
	int age;
	int matchesPlayed;
	int totalGoalsScored;

	printf("\t\t\t\tADD FOOTBALLER\n");
	printf("\t\t\t\t==============\n\n");
	printf("=> Enter Footballer Registration Number: ");
	scanf("%d", &regNum);
	printf("=> Enter Footballer Name: ");
	scanf("%s", &name);
	printf("=> Enter Footballer Age: ");
	scanf("%d", &age);
	printf("=> Enter Match Played: ");
	scanf("%d", &matchesPlayed);
	printf("=> Enter Total Goals Scored: ");
	scanf("%d", &totalGoalsScored);
	
	footballerData[regNum-1].regNum = regNum;
	strcpy(footballerData[regNum-1].name, name);
	footballerData[regNum-1].age = age;
	footballerData[regNum-1].matchesPlayed = matchesPlayed;
	footballerData[regNum-1].totalGoalsScored = totalGoalsScored;

	//	File Pointer to write data by using file mode "a = append"
	FILE *fbwptr;	
	fbwptr = (fopen("footballer.txt", "a"));
		fprintf(fbwptr, "\n============================================================================");
		fprintf(fbwptr, "\nFootballer Registration Number: %d", footballerData[regNum-1].regNum);
		fprintf(fbwptr, "\nFootballer Name: %s", footballerData[regNum-1].name);
		fprintf(fbwptr, "\nFootballer Age: %d", footballerData[regNum-1].age);
		fprintf(fbwptr, "\nMatch Played: %d", footballerData[regNum-1].matchesPlayed);
		fprintf(fbwptr, "\nTotal Goals Scored: %d", footballerData[regNum-1].totalGoalsScored);
		fprintf(fbwptr, "\n============================================================================");
	fclose(fbwptr);
	printf("\nFootballer Added in Record!\n\n");
}

void deleteFootballer()
{
	system("cls");
	int flag, regNum;
	char name[50], delName[50];
	printf("\t\t\t\tDELETE FOOTBALLER\n");
	printf("\t\t\t\t=================\n\n");
	printf("Enter Name of Footballer to Delete it\'s Record: ");
	scanf("%s", &name);
	
	for(regNum = 0;regNum < noOfRecords;regNum++)
	{
		if(strcmp(footballerData[regNum].name, name) == 0)
		{
			flag = 1;
		}
		if(flag == 1)
		{
			footballerData[regNum].regNum = 0;
			strcpy(footballerData[regNum].name, "");
			footballerData[regNum].age = 0;
			footballerData[regNum].matchesPlayed = 0;
			footballerData[regNum].totalGoalsScored = 0;
			
			printf("\nRecord Deleted Successfully!");
		}
	}
	printf("\n\n");
}

void searchFootaballerByName()
{
	system("cls");
	int regNum;
	char name[50];
	
	printf("\n\t\t\t\tSearch Footaballer By Matches Played\n");
	printf("\t\t\t\t====================================\n\n");
	printf("=> Enter Footballer Name: ");
	scanf("%s", &name);
	
	for(regNum = 0; regNum < noOfRecords;regNum++)
	{
		if(strcmp(footballerData[regNum].name, name) == 0)
		{
			printf("\nFootballer Registration Number: %d", footballerData[regNum].regNum);
			printf("\nFootballer Name: %s", footballerData[regNum].name);
			printf("\nFootballer Age: %d", footballerData[regNum].age);
			printf("\nMatch Played: %d", footballerData[regNum].matchesPlayed);
			printf("\nTotal Goals Scored: %d", footballerData[regNum].totalGoalsScored);
		}
	}
	printf("\n\n");
}
void searchFootaballerByMatchesPlayed()
{
	system("cls");
	int matchPlayed, regNum;
	
	printf("\n\t\t\t\tSearch Footaballer By Matches Played\n");
	printf("\t\t\t\t====================================\n\n");
	printf("=> Enter Match Played by Footballer: ");
	scanf("%d", &matchPlayed);
	
	for(regNum = 0;regNum < noOfRecords;regNum++)
	{
		if(footballerData[regNum].matchesPlayed == matchPlayed)
		{
			printf("\nFootballer Registration Number: %d", footballerData[regNum].regNum);
			printf("\nFootballer Name: %s", footballerData[regNum].name);
			printf("\nFootballer Age: %d", footballerData[regNum].age);
			printf("\nMatch Played: %d", footballerData[regNum].matchesPlayed);
			printf("\nTotal Goals Scored: %d", footballerData[regNum].totalGoalsScored);
		}
	}
	printf("\n\n");
}
void searchFootaballerByTotalGoalsScored()
{
	system("cls");
	int totalGoalsScored, regNum;
	
	printf("\n\t\t\t\tSEARCH FOOTBALLER BY TOTAL GOALS SCORED\n");
	printf("\t\t\t\t====================================\n\n");
	printf("=> Enter Total Goals Scored by Footballer: ");
	scanf("%d", &totalGoalsScored);
	
	for(regNum = 0;regNum < noOfRecords;regNum++)
	{
		if(footballerData[regNum].totalGoalsScored == totalGoalsScored)
		{
			printf("\nFootballer Registration Number: %d", footballerData[regNum].regNum);
			printf("\nFootballer Name: %s", footballerData[regNum].name);
			printf("\nFootballer Age: %d", footballerData[regNum].age);
			printf("\nMatch Played: %d", footballerData[regNum].matchesPlayed);
			printf("\nTotal Goals Scored: %d", footballerData[regNum].totalGoalsScored);
			break;
		}
	}
	printf("\n\n");
}
void displayAllRecords()
{
	system("cls");
	printf("\t\t\t\tDISPLAY ALL RECORDS\n");
	printf("\t\t\t\t===================");
	
	readFileRecords();
}

void readFileRecords()
{
	//	File Pointer to read file data by using file mode "r = read"
	FILE *fbrptr;
	char fileData[500];
	fbrptr = (fopen("footballer.txt", "r"));
    
	//	to check the file is empty
    fseek(fbrptr, 0, SEEK_END);	//	goto end of file
	if(ftell(fbrptr) == 0)
 	{
 		printf("\n\nFILE IS EMPTY");
	}
	fseek(fbrptr, 0, SEEK_SET);	//	goto start of file
	
    //	reads and prints file all data present in the file
    while(!feof(fbrptr))
    {
    	fgets(fileData, 500, fbrptr);
    	puts(fileData);
	}
    fclose(fbrptr);
    printf("\n\n");
}
