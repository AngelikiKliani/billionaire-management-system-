/*
Aggeliki Kliani
AM 2022202300205
dit23205@go.uop.gr

Christianna Tsouko
AM 2022202300014
dit23014@go.uop.gr

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} mydate;

typedef struct {
    int hour;
    int minutes;
} mytime;

typedef struct bilList {
    char name[50];
    char location[50];
    char source[100];
    char birthcountry[50];
    char gender[10];
    mydate birthdate;
    mytime birthtime;
    double money;
    int *billCode;
    struct bilList *next;
    struct bilList *prev;
} billionaire;

int *billCode(void);
void insertBillionaire(billionaire **head, billionaire newBillionaire);
void saveBillionaires(billionaire *head, const char *filename);
void loadBillionaires(billionaire **head, int n, const char *filename);
void deleteNewBillionaire(billionaire **head);
void deleteOldBillionaire(billionaire **head);
void sumBillionaires(billionaire *head);
void freeBillionaires(billionaire **head);

int main(void){
	int n=0;
    char a, input[200], *token, *token1, *token2;
    billionaire newBillionaire;
    char *infoTable[5], *TimeTable[2], *dateTable[3];
    billionaire *head = NULL;
    char *filename;

    printf("Welcome! Do you want instructions for the commands you may want to use? Yes[Y/y] or No[N/n]\n");
    do {
        scanf("%c", &a);
        if (a == 'Y' || a == 'y') 
        {
            printf("-To CREATE a new bill type 'newbil Name Surname;City/Country;Source of income;Country of birth;Gender;00/00/0000 00:00; billions;'\n"
                   "Be very careful to type everything as shown; filling every field with information about the billionaire with the exact position of semicolons and spaces. If you don't know something type '?' or 'Unknown'.\n"
                   "Note: In the field :'00/00/0000 00:00' you must type the date and time of birth.\n\n");
            printf("-To PRINT all the billions summarized type 'sum'\n\n");
            printf("-To FIND billionaires with a specific name, location or source of income you should type 'findN/findC/findS' accordingly followed by the word you are searching for\n\n");
            printf("-To PRINT a billionaire with specific billions, time or date of birth you should type 'print' followed by the numbers of the thing you are searching. Be careful to follow the correct form of the thing you are searching. For example type 11:06 for the time and not 1106. By typing 'print-' all the billionaires lower from your input will be printed as well and typing 'print+' will have the opposite results.\n\n");
            printf("-To DELETE the new bill you have created type 'deleteN' and to delete the first bill type 'deleteO'.\n\n");
            printf("-To SAVE all the billionaires you entered in the file type 'save' followed by the name of the file.\n\n");
            printf("-To LOAD billionaires from the file to your existing list type 'load' followed by the number of billionaires you want to load and the name of the file.\n\n");
            printf("-To EXIT the program type exit\n\n");
        } 
        else if (a == 'N' || a == 'n') 
        {
            break;
        } 
        else 
        {
            printf("You have typed something wrong. Try again.\n");
        }
    }while (a != 'y' && a != 'Y' && a != 'n' && a != 'N');

    getchar();

    while (1){
        printf("Enter your command:\n");
        printf("$> ");
        fgets(input, 200, stdin);
        input[strcspn(input, "\n")] = 0;  // Remove trailing newline character
        char *command = input;

        if (strncmp(command, "newbil", 6) == 0)
        {
            token = strtok(command + 7, ";");  // skip "newbil " part
            int i = 0, j = 0, k = 0;
            while (token != NULL){  // checks for ;
                if (i == 5) 
                {
                    token1 = strtok(token, " /");
                    while (token1 != NULL){  // checks for /,space
                        if (j == 3) 
                        {
                            token2 = strtok(token1, ":");
                            while (token2 != NULL){  // checks for :
                                TimeTable[k] = token2;
                                token2 = strtok(NULL, ":");
                                k++;
                            }
                        }
                        else 
                        {
                            dateTable[j] = token1;
                            token1 = strtok(NULL, " /");
                        }
                        j++;
                    }
                } 
                else if (i == 6) 
                {
                    newBillionaire.money = atof(token);  // atof for floating point numbers
                } 
                else
                {
                    infoTable[i] = token;
                }
                token = strtok(NULL, ";");
                i++;
            }

            strcpy(newBillionaire.name, infoTable[0]);
            strcpy(newBillionaire.location, infoTable[1]);
            strcpy(newBillionaire.source, infoTable[2]);
            strcpy(newBillionaire.birthcountry, infoTable[3]);
            strcpy(newBillionaire.gender, infoTable[4]);
            newBillionaire.birthdate.day = atoi(dateTable[0]);
            newBillionaire.birthdate.month = atoi(dateTable[1]);
            newBillionaire.birthdate.year = atoi(dateTable[2]);
            newBillionaire.birthtime.hour = atoi(TimeTable[0]);
            newBillionaire.birthtime.minutes = atoi(TimeTable[1]);

           /* printf("%s;%s;%s;%s;%s;%02d/%02d/%04d;%02d:%02d;%0.1f\n", newBillionaire.name, newBillionaire.location, newBillionaire.source, newBillionaire.birthcountry, newBillionaire.gender, newBillionaire.birthdate.day, newBillionaire.birthdate.month, newBillionaire.birthdate.year, newBillionaire.birthtime.hour, newBillionaire.birthtime.minutes, newBillionaire.money);*/

            insertBillionaire(&head, newBillionaire);
        } 
        else if (strncmp(command, "sum", 3) == 0) 
        {
             sumBillionaires(head);
        } 
        else if (strncmp(command, "find", 4) == 0) 
        {
            char lastChar = command[4];  
            if (lastChar == 'N') 
            {      
                
            } 
            else if (lastChar == 'C') 
            {  
                
            } 
            else if (lastChar == 'S') 
            {  
                
            } 
            else 
            {
                printf("You wrote something wrong.. Check it again.\n");
            }
        } 
        else if (strncmp(command, "print", 5) == 0) 
        {
            char lastSymbol = command[5];  
            if (lastSymbol == '+') 
            {      
                
            } 
            else if (lastSymbol == '-') 
            {  
                
            } 
            else 
            {
                
            }
        } 
	else if (strncmp(command, "delete", 6) == 0) 
	{
            char lastLetter = command[6];  
            if (lastLetter == 'N') 
            {       
                deleteNewBillionaire(&head); 
            } 
            else if (lastLetter == 'O') 
            {  
                deleteOldBillionaire(&head);  
            } 
            else 
            {
                printf("You wrote something wrong.. Check it again.\n");
            }
        } 
        else if (strncmp(command, "save", 4) == 0) 
        {
            char *filename = command + 5;  
            saveBillionaires(head, filename);
        } 
        else if (strncmp(command, "load", 4) == 0) 
        {
        	token = strtok(command + 5, " "); //pairnei to noumero
           	if(token != NULL) 
           	{
              	  	n = atoi(token);
		        token = strtok(NULL, " "); //parinei to onoma
		        if(token != NULL) 
		        {
		            strcpy(filename, token);
		             loadBillionaires(&head, n, filename);
		       	}
		       	else 
		       	{
		           	printf("Invalid command. Filename missing.\n");
		        }
           	 }
           	 else 	
           	 {
                	printf("Invalid command. Number of billionaires to load missing.\n");
            	 }
  		
        } 
        else if(strcmp(command, "exit") == 0){
		printf("Goodbye.\n");
		freeBillionaires(&head);
		return 0;
	}
        else 
        {
            printf("You wrote something wrong.. Check it again.\n");
        }
    }

   
}


// Function to generate a bill code
int *billCode(void) {
    srand(time(NULL));

    // Allocate memory for billCode array
    int *billCode = (int *)malloc(11 * sizeof(int));
    if (billCode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int i, sum = 0, checkDigit;

    for (i = 0; i < 10; i++) {
        billCode[i] = rand() % 10;
        if (i % 2 != 0) {  // Check if index is odd
            billCode[i] *= 2;
            if (billCode[i] > 9) {
                billCode[i] = (billCode[i] % 10) + 1;
            }
        }
        sum += billCode[i];
    }

    checkDigit = sum * 9;
    checkDigit %= 10;

    billCode[10] = checkDigit;

    return billCode;
}


// Function to insert a new billionaire into the doubly circular linked list
void insertBillionaire(billionaire **head, billionaire newBillionaire){
        int i;
    	billionaire *newNode = (billionaire *)malloc(sizeof(billionaire));
    	if (!newNode) 
    	{
        printf("Memory allocation error..\n");
        return;
    	}

    *newNode = newBillionaire;
    newNode->next = newNode;
    newNode->prev = newNode;
    
    // Generate bill code and assign to newBillionaire
    newNode->billCode = billCode();
    
		     printf("Generated bill code: ");
		    for ( i = 0; i < 11; ++i) {
			printf("%d", newNode->billCode[i]);
		    }
		    printf("\n");

    if (*head == NULL) 
    {
        *head = newNode;
    }
    else 
    {
        billionaire *tail = (*head)->prev;

        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
    }
}


void deleteNewBillionaire(billionaire **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    billionaire *newBillionaire = (*head)->prev;
    if (newBillionaire == *head) {  // Only one element in the list
        free(*head);
        *head = NULL;
    } else {
        billionaire *prevBillionaire = newBillionaire->prev;
        prevBillionaire->next = *head;
        (*head)->prev = prevBillionaire;
        free(newBillionaire);
    }
}


void deleteOldBillionaire(billionaire **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    billionaire *oldBillionaire = *head;
    if (oldBillionaire->next == *head) {  // Only one element in the list
        free(*head);
        *head = NULL;
    } else {
        billionaire *nextBillionaire = oldBillionaire->next;
        billionaire *lastBillionaire = oldBillionaire->prev;
        lastBillionaire->next = nextBillionaire;
        nextBillionaire->prev = lastBillionaire;
        *head = nextBillionaire;
        free(oldBillionaire);
    }
}

//Function to Save
void saveBillionaires(billionaire *head, const char *filename){
    	FILE *file = fopen(filename, "r+"); //enhmerwnei to arceio dld diabazei kai grafei
   	if (!file) 
   	{
        	printf("Could not open file for writing..\n");
       		return;
   	}
   	else
   	{
   		fseek(file, 0, SEEK_END); //metakinei deikth sto telos kai bazei ta nea dedomena sto telos tou arxeiou xwris na diagraftoyn h na ephreastoun ta alla.
   	}
   	
	billionaire *current = head;
	do{
		fprintf(file, "%s;%s;%s;%s;%s;%d/%d/%d;%d:%d;%0.2f\n", current->name, current->location, current->source, current->birthcountry, current->gender, current->birthdate.day, current->birthdate.month, current->birthdate.year, current->birthtime.hour, current->birthtime.minutes, current->money);
		current = current->next;
	}while(current != head);
	
	fclose(file);
    	printf("Billionaires saved to %s\n", filename);
}

//FUnction to Load
void loadBillionaires(billionaire **head, int n, const char *filename) {
	char *dFilename = malloc(strlen(filename) + 1); //dunamikh mnhmh kai to strlen metraei arithmo grammatwn +1 to /0.
	if (!dFilename) 
	{
        	printf("Memory allocation failed for filename.\n");
        	return;
    	}
	strcpy(dFilename, filename); // anrigrafei to onoma sto dFilename
	
    	FILE *file = fopen(dFilename, "r"); // Ανοίγει το αρχείο για ανάγνωση
    	if (!file) 
    	{
       	 	printf("Could not open file %s for reading.\n", dFilename);
       	 	free(dFilename);
       	 	return;
    	}
    
    	int totalBillionaires = 0;
    	billionaire newBillionaire;
    	while (totalBillionaires < n && fscanf(file, "%s;%s;%s;%s;%s;%d/%d/%d;%d:%d;%lf\n",newBillionaire.name, newBillionaire.location, newBillionaire.source,newBillionaire.birthcountry,newBillionaire.gender,&newBillionaire.birthdate.day, &newBillionaire.birthdate.month ,&newBillionaire.birthdate.year, &newBillionaire.birthtime.hour,&newBillionaire.birthtime.minutes, &newBillionaire.money) == 11){ 	
        	totalBillionaires++;
        	if (totalBillionaires <= n) 
        	{
            		insertBillionaire(head, newBillionaire);
        	} 
        	else 
        	{
            		break;
        	}
   	}
    
    	fclose(file);
   	printf("Billionaires loaded from %s\n", dFilename);
    
   	if (totalBillionaires < n) 
    	{
      	  printf("Only %d billionaire(s) available in the file. Loaded all.\n", totalBillionaires);
    	}
	free(dFilename);
}

// Function to sum the money of all billionaires and print the total
void sumBillionaires(billionaire *head) {
    if (head == NULL) {
        printf("No billionaires in the list.\n");
        return;
    }

    double totalMoney = 0.0;
    billionaire *current = head;

    do {
        totalMoney += current->money;
        current = current->next;
    } while (current != head);

    printf("Total money of all billionaires: %.2f billions\n", totalMoney);
}

// Function to free all allocated memory
void freeBillionaires(billionaire **head) {
    if (*head == NULL) {
        return;
    }

    billionaire *current = *head;
    do {
        billionaire *next = current->next;
        free(current->billCode);  // Free the bill code
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}
