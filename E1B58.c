#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>

#define ROWS 9
#define COLS 9
// 函數宣告
void generateSeats(char seats[ROWS][COLS]);
void displaySeats(char seats[ROWS][COLS]);

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
	system("CLS");
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
		}
	}
	continue;
}//第三題結束 
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
