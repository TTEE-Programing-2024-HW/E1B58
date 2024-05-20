#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h> 

#define ROWS 9
#define COLS 9
#define RESERVED_SEATS 10

void generateSeats(char seats[ROWS][COLS]);
void displaySeats(char seats[ROWS][COLS]);
void arrangeSeats(char seats[ROWS][COLS], int seatsNeeded);
void chooseSeats(char seats[ROWS][COLS]);
void updateSeats(char seats[ROWS][COLS]);
void clearScreen();
void showMenu();

int main(void){
	 //�Ĥ@�D�ӤH����e��
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��    EEEEEE  1   BBBB         555555  888888     ��\n");
	printf("��    E      11   B   B        5       8    8     ��\n");
	printf("��    E       1   B   B        5       8    8     ��\n");
	printf("��    E       1   B   B        5       8    8     ��\n");
	printf("��    E       1   B   B        5       8    8     ��\n");
	printf("��    EEEEE   1   BBBBB        555555  888888     ��\n");
	printf("��    E       1   B    B            5  8    8     ��\n");
	printf("��    E       1   B    B            5  8    8     ��\n");
	printf("��    E       1   B    B            5  8    8     ��\n");
	printf("��    E       1   B    B            5  8    8     ��\n");
	printf("��    EEEEEE 111  BBBBB        555555  888888     ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	
	system("PAUSE");//�Ȱ��{������õ��ݨϥΪ̫��U���N��
	system("CLS");//�M���ù�
	char password[] = "2024"; // ���T���K�X
    char input[20]; // �Ω󱵦��K�X��J
    int attempt = 0; // �K�X���զ���
    char seats[ROWS][COLS];
    // Ū���K�X���ˬd
    while (1) {
  		attempt++;
        printf("Enter the password: ");
        scanf("%s", input);
   if(strcmp(input,password)==0)
   		break;
   		else{
   	if(attempt==3)//�֭p�T���A�{������ 
   	{	printf("Too many incorrect password attempts. Exiting program.\n");
	 	 return 0; //�{������
		  }
   	
   	else{
   	printf("you have %d chance enter again:",3-attempt);
   		}
   }
} 
	//system("PAUSE");//�Ȱ��{������õ��ݨϥΪ̫��U���N��
	system("CLS");//�M���ù�
//�Ĥ@�D����
//�ĤG�D�}�l
	while(1){
	printf("----------[BookingSystem]----------\n");
	printf("|  a. Available seats             |\n");
	printf("|  b. Arrange for you             |\n");
	printf("|  c. Choose by yourself          |\n");
	printf("|  d. Exit                        |\n");
	printf("-----------------------------------\n");
//�ĤG�D����
//�ĤT�D�}�l
	char choice;
	choice = _getch(); // �ϥ� _getch Ū����Ӧr��
	system("CLS");//�M���ù�
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
		}//�ĤT�D���� 
		//�ĥ|�D�}�l 
		case 'b':{
			int seatsNeeded;
			printf("How many seats would you need?(1-4):");
			scanf("%d",&seatsNeeded);
			arrangeSeats(seatsNeeded);
			break;
		}
		case 'B':{
			
			break;
		}
	}
	continue;
}
	
return 0;}




//�i�ܮy�� 
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
    // ��l�ƩҦ��y�쬰��
    int i,j,k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            seats[i][j] = 'O'; // 'O' ��ܪŮy��
        }
    }

    // �H�����10�Ӯy��]�m���w�w�q
    for (k = 0; k < 10; k++) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (seats[row][col] == '*'); // �T�O�����ƿ�ܦP�@�Ӯy��

        seats[row][col] = '*'; // '*' ��ܤw�w�q
    }
}
// �۰ʦw�Ʈy��
void arrangeSeats(char seats[ROWS][COLS], int seatsNeeded){
	// �M�����e����ĳ�y��
	int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            if (seats[i][j] == '@') {
                seats[i][j] = 'O';
            }
        }
         // �M��ë�ĳ�y��
    int found = 0; // �аO�O�_���X�A���y��

    // �M��s��y��
    if (seatsNeeded == 1 || seatsNeeded == 2 || seatsNeeded == 3) {
        // ��椤�s��y��
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
        // ��椤�s��4�Ӯy��
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
        // �Y�L�k�����s��4�Ӯy��A�h�M��۾F���U��ӳs��y��
        if (!found) {
        	int i,j;
            for ( i = 0; i < ROWS - 1 && !found; i++) {
                for ( j = 0; j < COLS - 1; j++) {
                    if (seats[i][j] == 'O' && seats[i + 1][j] == 'O' && seats[i][j + 1] == 'O' && seats[i + 1][j + 1] == 'O') {
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

    }
void chooseSeats(char seats[ROWS][COLS]) {
    int row, col;
    char buffer[10];

    // Clear previous suggestions
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
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
    }
}
void updateSeats(char seats[ROWS][COLS]) {
    // Update '@' to '*'
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
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
   

