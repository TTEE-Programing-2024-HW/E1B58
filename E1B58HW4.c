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
