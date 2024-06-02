#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MAX_STUDENTS 10
#define NUM_SUBJECTS 3

// 學生結構體定義
typedef struct {
    char name[50]; // 學生姓名
    int id; // 學生學號
    float grades[NUM_SUBJECTS]; // 學生成績
    float average; // 平均成績
} Student;

Student students[MAX_STUDENTS]; // 學生數組
int studentCount = 0; // 學生數量

// 清空螢幕函數
void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Windows 系統清屏指令
    #else
        system("clear"); // UNIX 系統清屏指令
    #endif
}

// 等待用戶按下任意鍵函數
void waitForKeyPress() {
    printf("按任意鍵返回主選單...\n");
    getchar(); // 捕獲Enter鍵
    getchar(); // 等待用戶按下任意鍵
}

// 輸入學生成績函數
void enterGrades() {
    int n;
    printf("請輸入學生數量（5~10的整數）: ");
    // 驗證輸入的學生數量
    while (scanf("%d", &n) != 1 || n < 5 || n > 10) {
        printf("輸入錯誤，請輸入5到10之間的整數: ");
        while (getchar() != '\n'); // 清空輸入緩衝區
    }

    // 依次輸入每個學生的信息
    int i;
    for ( i = 0; i < n; i++) {
        if (studentCount >= MAX_STUDENTS) {
            printf("學生數量已達上限。\n");
            return;
        }

        printf("輸入學生姓名: ");
        scanf("%s", students[studentCount].name);

        printf("輸入學號（6位整數）: ");
        // 驗證輸入的學號
        while (scanf("%d", &students[studentCount].id) != 1 || students[studentCount].id < 100000 || students[studentCount].id > 999999) {
            printf("輸入錯誤，請輸入6位整數的學號: ");
            while (getchar() != '\n'); // 清空輸入緩衝區
        }

        float sum = 0;
        // 依次輸入各科成績
        int j;
        for (j = 0; j < NUM_SUBJECTS; j++) {
            const char* subjects[] = {"數學", "物理", "英文"};
            printf("輸入%s成績（0~100分）: ", subjects[j]);
            // 驗證輸入的成績
            while (scanf("%f", &students[studentCount].grades[j]) != 1 || students[studentCount].grades[j] < 0 || students[studentCount].grades[j] > 100) {
                printf("輸入錯誤，請輸入0到100之間的成績: ");
                while (getchar() != '\n'); // 清空輸入緩衝區
            }
            sum += students[studentCount].grades[j];
        }
        students[studentCount].average = sum / NUM_SUBJECTS; // 計算平均成績
        studentCount++;
    }
}

// 顯示學生成績函數
void displayGrades() {
    clearScreen();
    int i,j;
    for ( i = 0; i < studentCount; i++) {
        printf("學生姓名: %s\n", students[i].name);
        printf("學號: %d\n", students[i].id);
        printf("各科成績: ");
        for ( j = 0; j < NUM_SUBJECTS; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\n平均成績: %.2f\n", students[i].average);
    }
    waitForKeyPress(); // 等待用戶按下任意鍵
}

// 查詢學生成績函數
void searchGrades() {
    clearScreen();
    char searchName[50];
    printf("輸入要查詢的學生姓名: ");
    scanf("%s", searchName);
    int i,j;
    for ( i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("學生姓名: %s\n", students[i].name);
            printf("學號: %d\n", students[i].id);
            printf("各科成績: ");
            for ( j = 0; j < NUM_SUBJECTS; j++) {
                printf("%.2f ", students[i].grades[j]);
            }
            printf("\n平均成績: %.2f\n", students[i].average);
            waitForKeyPress(); // 等待用戶按下任意鍵
            return;
        }
    }
    printf("未找到學生 %s 的成績。\n", searchName);
    waitForKeyPress(); // 等待用戶按下任意鍵
}

int main(){
    
    //第一題個人風格畫面
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■************************************************■\n");
	printf("■************************************************■\n");
	printf("■****EEEEEE**1***BBBB*********555555**888888*****■\n");
	printf("■****E******11***B***B********5*******8****8*****■\n");
	printf("■****E*******1***B***B********5*******8****8*****■\n");
	printf("■****E*******1***B***B********5*******8****8*****■\n");
	printf("■****E*******1***B***B********5*******8****8*****■\n");
	printf("■****EEEEE***1***BBBBB********555555**888888*****■\n");
	printf("■****E*******1***B****B************5**8****8*****■\n");
	printf("■****E*******1***B****B************5**8****8*****■\n");
	printf("■****E*******1***B****B************5**8****8*****■\n");
	printf("■****E*******1***B****B************5**8****8*****■\n");
	printf("■****EEEEEE*111**BBBBB********555555**888888*****■\n");
	printf("■************************************************■\n");
	printf("■************************************************■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	
	system("PAUSE");//暫停程式執行並等待使用者按下任意鍵
	system("CLS");//清除螢幕
	
    
    char password[] = "2024"; // 正確的密碼
    char input[20]; // 用於接收密碼輸入
    int attempt = 0; // 密碼嘗試次數
    
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
} 
//第一題結束
