#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h> 

#define ROWS 9
#define COLS 9
#define RESERVED_SEATS 10
// function declaration
void generateSeats(char seats[ROWS][COLS]);
void displaySeats(char seats[ROWS][COLS]);
void arrangeSeats(char seats[ROWS][COLS], int seatsNeeded);
void chooseSeats(char seats[ROWS][COLS]);
void updateSeats(char seats[ROWS][COLS]);
void clearScreen();
void showMenu();

int main(void){
	 //Question 1 personal style picture
	printf("――――――――――――――――――――――――――――――――――――――――――――――――――\n");
	printf("―                                                ―\n");
	printf("―                                                ―\n");
	printf("―    EEEEEE  1   BBBB         555555  888888     ―\n");
	printf("―    E      11   B   B        5       8    8     ―\n");
	printf("―    E       1   B   B        5       8    8     ―\n");
	printf("―    E       1   B   B        5       8    8     ―\n");
	printf("―    E       1   B   B        5       8    8     ―\n");
	printf("―    EEEEE   1   BBBBB        555555  888888     ―\n");
	printf("―    E       1   B    B            5  8    8     ―\n");
	printf("―    E       1   B    B            5  8    8     ―\n");
	printf("―    E       1   B    B            5  8    8     ―\n");
	printf("―    E       1   B    B            5  8    8     ―\n");
	printf("―    EEEEEE 111  BBBBB        555555  888888     ―\n");
	printf("―                                                ―\n");
	printf("―                                                ―\n");
	printf("――――――――――――――――――――――――――――――――――――――――――――――――――\n");
	
	system("PAUSE");//Pauses program execution and waits for the user to press any key
	system("CLS");//clear screen
	char password[] = "2024"; // correct password
    char input[20]; //Used to receive password input
    int attempt = 0; // Password attempts
    char seats[ROWS][COLS];
    // Read the password and check
    while (1) {
  		attempt++;
        printf("Enter the password: ");
        scanf("%s", input);
   if(strcmp(input,password)==0)
   		break;
   		else{
   	if(attempt==3)//Accumulated three times, the program ends
   	{	printf("Too many incorrect password attempts. Exiting program.\n");
	 	 return 0; //End of program
		  }
   	
   	else{
   	printf("you have %d chance enter again:",3-attempt);
   		}
   }
} 
	//system("PAUSE");//Pauses program execution and waits for the user to press any key
	system("CLS");//clear screen
//End of first question
//The second question begins
	while(1){
	printf("----------[BookingSystem]----------\n");
	printf("|  a. Available seats             |\n");
	printf("|  b. Arrange for you             |\n");
	printf("|  c. Choose by yourself          |\n");
	printf("|  d. Exit                        |\n");
	printf("-----------------------------------\n");
//End of second question
//The third question begins
	char choice;
	choice = _getch(); // Use _getch to read a single character
	system("CLS");//clear screen
	switch(choice){
		case 'a':{
			generateSeats(seats);
			displaySeats(seats);
			system("PAUSE");
			system("CLS");
			break;
		}
		case 'A':{
			generateSeats(seats);
			displaySeats(seats);
			system("PAUSE");
			system("CLS");
			break;
		}//End of the third question
		//The fourth question begins
		case 'b':
		case 'B':{
			int seatsNeeded;
                clearScreen();
                printf("How many seats do you need (1-4)? ");
                scanf("%d", &seatsNeeded);
                if (seatsNeeded < 1 || seatsNeeded > 4) {
                    printf("Invalid number of seats. Press any key to return to main menu...");
                    _getch();
                    clearScreen();
                    break;
                }
                arrangeSeats(seats, seatsNeeded);
                clearScreen();
                displaySeats(seats);
                printf("Are you satisfied with the arrangement (y/n)? ");
                char satisfied = _getch();
                if (satisfied == 'y') {
                    updateSeats(seats);
                }
                clearScreen();
                break;
            }//4end
		case 'c'://5start
		case 'C':{
				clearScreen();
                chooseSeats(seats);
                clearScreen();
                displaySeats(seats);
                printf("Press any key to confirm and return to main menu...");
                _getch();
                updateSeats(seats);
                displaySeats(seats);
                clearScreen();
				break;
			}//5end
		case 'd'://6start
		case 'D':{
				clearScreen();
	            printf("Continue? (y/n): ");
	            char cont = _getch();
	            if (cont == 'n') {
	            return 0;
	            }
	            clearScreen();
	            break;	
			}        
		break;
	}
	continue;
}
	//6end
return 0;}




//display seating
void displaySeats(char seats[ROWS][COLS]) {
    int i,j;
    printf(" \\123456789\n");
    for ( i = ROWS - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for ( j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}
void generateSeats(char seats[ROWS][COLS]) {
    // Initialize all seats to be empty
    int i,j,k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            seats[i][j] = 'O'; // 'O' Indicates an empty seat
        }
    }

    // Randomly select 10 seats and set them as reserved
    for (k = 0; k < 10; k++) {
        int row, col;
        do {// Initialize random number generator
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (seats[row][col] == '*'); // Make sure you don・t select the same seat twice

        seats[row][col] = '*'; // '*' Indicates a reservation
    }
}
// Automatically arrange seats
void arrangeSeats(char seats[ROWS][COLS], int seatsNeeded) {
    // Clear previous suggestions
    int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
        	
            if (seats[i][j] == '@') {
                seats[i][j] = 'O';
            }
        }
    }

    // Find and suggest seats
    int found = 0;
    if (seatsNeeded == 1 || seatsNeeded == 2 || seatsNeeded == 3) {
    	int i,j,k;
        for ( i = 0; i < ROWS && !found; i++) {
            for ( j = 0; j <= COLS - seatsNeeded; j++) {
                int available = 1;
                for ( k = 0; k < seatsNeeded; k++) {
                    if (seats[i][j + k] != 'O') {
                        available = 0;
                        break;
                    }
                }
                if (available) {
                	int k;
                    for ( k = 0; k < seatsNeeded; k++) {
                        seats[i][j + k] = '@';
                    }
                    found = 1;
                    break;
                }
            }
        }
    } else if (seatsNeeded == 4) {
    	int i,j,k;
        for ( i = 0; i < ROWS && !found; i++) {
            for ( j = 0; j <= COLS - 4; j++) {
                int available = 1;
                for ( k = 0; k < 4; k++) {
                    if (seats[i][j + k] != 'O') {
                        available = 0;
                        break;
                    }
                }
                if (available) {
                	int k;
                    for ( k = 0; k < 4; k++) {
                        seats[i][j + k] = '@';
                    }
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
        	int i,j;
            for ( i = 0; i < ROWS - 1 && !found; i++) {
                for ( j = 0; j < COLS; j++) {
                    if (seats[i][j] == 'O' && seats[i + 1][j] == 'O') {
                        seats[i][j] = '@';
                        seats[i + 1][j] = '@';
                        seats[i][j + 1] = '@';
                        seats[i + 1][j + 1] = '@';
                        found = 1;
                        break;
                    }
                }
            }
        }
    }
}

    
void chooseSeats(char seats[ROWS][COLS]) {
    int row, col;
    char buffer[10];

    // Clear previous suggestions
    int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            if (seats[i][j] == '@') {
                seats[i][j] = 'O';
            }
        }
    }

    while (1) {
        printf("Enter seat (row-col) or 'done' to finish: ");
        scanf("%s", buffer);
        if (strcmp(buffer, "done") == 0) {
            break;
        }

        if (sscanf(buffer, "%d-%d", &row, &col) != 2 || row < 1 || row > ROWS || col < 1 || col > COLS || seats[row - 1][col - 1] != 'O') {
            printf("Invalid input or seat already taken. Please try again.\n");
        } else {
            seats[row - 1][col - 1] = '@';
        }
        break;
    }   
	displaySeats(seats); 
}



void updateSeats(char seats[ROWS][COLS]) {
    // Update '@' to '*'
    int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            if (seats[i][j] == '@') {
                seats[i][j] = '*';
            }
        }
    }
}
void clearScreen() {
    system("cls");
}

void showMenu() {
    printf("----------[Booking System]----------\n");
    printf("| a. Available seats               |\n");
    printf("| b. Arrange for you               |\n");
    printf("| c. Choose by yourself            |\n");
    printf("| d. Exit                          |\n");
    printf("------------------------------------\n");
}
   
//This assignment was quite challenging, especially parts B 
//and C. Dealing with the complexities involved and the 
//length of the code made it difficult to grasp and even harder
// to implement. Simply thinking through the logic required a 
// considerableeffort. Moreover, working with tools I wasn't 
// previouslyfamiliar with added an extra layer of complexity, 
//forcing me to learn and adapt on the fly.

//Overall, this assignment pushed me out of my comfort zone. 
//It required me to navigate through unfamiliar territory and 
//dive deep into understanding the intricacies of the code. 
//While it was undoubtedly challenging, it was also a valuable 
//learning experience that expanded my skills and knowledge in 
//programming.







