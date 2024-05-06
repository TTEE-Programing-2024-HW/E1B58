#include<stdio.h>
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
	 	 return 0; 
		  }
   	
   	else{
   	printf("you have %d chance enter again:",3-attempt);
   		}
   }
} 
//第一題結束
//第二題開始 
    printf("~=welcome=~\n");
    printf("■■■■■■■■■■■■■■■■■■\n");
    printf("■a.畫出直角三角形■\n");
    printf("■b.顯示乘法表    ■\n");
    printf("■c.結束          ■\n");
    printf("■■■■■■■■■■■■■■■■■■\n");
//第二題結束
//第三題開始
    fflush(stdin);
    char ch;
    	scanf("%c",&ch);
    	if(ch=='A'||ch=='a'){
    		printf("you're best!'");
		}
    	
    return 0;
}
