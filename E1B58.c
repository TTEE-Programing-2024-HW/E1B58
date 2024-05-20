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
	 //第一題個人風格畫面
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                ■\n");
	printf("■                                                ■\n");
	printf("■    EEEEEE  1   BBBB         555555  888888     ■\n");
	printf("■    E      11   B   B        5       8    8     ■\n");
	printf("■    E       1   B   B        5       8    8     ■\n");
	printf("■    E       1   B   B        5       8    8     ■\n");
	printf("■    E       1   B   B        5       8    8     ■\n");
	printf("■    EEEEE   1   BBBBB        555555  888888     ■\n");
	printf("■    E       1   B    B            5  8    8     ■\n");
	printf("■    E       1   B    B            5  8    8     ■\n");
	printf("■    E       1   B    B            5  8    8     ■\n");
	printf("■    E       1   B    B            5  8    8     ■\n");
	printf("■    EEEEEE 111  BBBBB        555555  888888     ■\n");
	printf("■                                                ■\n");
	printf("■                                                ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	
	system("PAUSE");//暫停程式執行並等待使用者按下任意鍵
	system("CLS");//清除螢幕
	char password[] = "2024"; // 正確的密碼
    char input[20]; // 用於接收密碼輸入
    int attempt = 0; // 密碼嘗試次數
    char seats[ROWS][COLS];
    // 讀取密碼並檢查
    while (1) {
  		attempt++;
        printf("Enter the password: ");
        scanf("%s", input);
   if(strcmp(input,password)==0)
   		break;
   		else{
   	if(attempt==3)//累計三次，程式結束 
   	{	printf("Too many incorrect password attempts. Exiting program.\n");
	 	 return 0; //程式結束
		  }
   	
   	else{
   	printf("you have %d chance enter again:",3-attempt);
   		}
   }
} 
	//system("PAUSE");//暫停程式執行並等待使用者按下任意鍵
	system("CLS");//清除螢幕
//第一題結束
//第二題開始
	while(1){
	printf("----------[BookingSystem]----------\n");
	printf("|  a. Available seats             |\n");
	printf("|  b. Arrange for you             |\n");
	printf("|  c. Choose by yourself          |\n");
	printf("|  d. Exit                        |\n");
	printf("-----------------------------------\n");
//第二題結束
//第三題開始
	char choice;
	choice = _getch(); // 使用 _getch 讀取單個字符
	system("CLS");//清除螢幕
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
		}//第三題結束 
		//第四題開始 
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




//展示座位 
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
    // 初始化所有座位為空
    int i,j,k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            seats[i][j] = 'O'; // 'O' 表示空座位
        }
    }

    // 隨機選擇10個座位設置為已預訂
    for (k = 0; k < 10; k++) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (seats[row][col] == '*'); // 確保不重複選擇同一個座位

        seats[row][col] = '*'; // '*' 表示已預訂
    }
}
// 自動安排座位
void arrangeSeats(char seats[ROWS][COLS], int seatsNeeded){
	// 清除之前的建議座位
	int i,j;
    for ( i = 0; i < ROWS; i++) {
        for ( j = 0; j < COLS; j++) {
            if (seats[i][j] == '@') {
                seats[i][j] = 'O';
            }
        }
         // 尋找並建議座位
    int found = 0; // 標記是否找到合適的座位

    // 尋找連續座位
    if (seatsNeeded == 1 || seatsNeeded == 2 || seatsNeeded == 3) {
        // 單行中連續座位
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
        // 單行中連續4個座位
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
        // 若無法找到單行連續4個座位，則尋找相鄰兩行各兩個連續座位
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
   

