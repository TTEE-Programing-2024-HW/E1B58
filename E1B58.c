#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>

#define ROWS 9
#define COLS 9
// ��ƫŧi
void generateSeats(char seats[ROWS][COLS]);
void displaySeats(char seats[ROWS][COLS]);

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
}//�ĤT�D���� 
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
