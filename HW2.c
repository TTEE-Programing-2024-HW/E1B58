#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

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
//第一題結束
//第二題開始 
	while(1){
    printf("~=welcome=~\n");
    printf("■■■■■■■■■■■■■■■■■■\n");
    printf("■a.畫出直角三角形■\n");
    printf("■b.顯示乘法表    ■\n");
    printf("■c.結束          ■\n");
    printf("■■■■■■■■■■■■■■■■■■\n");
//第二題結束
//第三題開始
    fflush(stdin);
    char ch,i,j,ps;
    int g,u,k;
    	scanf("%c",&ch);
    	if(ch=='A'||ch=='a'){
    		system("CLS");
    		printf("please enter a~n\n:");
    	while(1){
    		fflush(stdin);
    		ch=0;
    		scanf("%c",&ch);
			if(ch>='a'&&ch<='n')
				break;
			else{
				printf("error,please enter a~n\n:");
				} 
			}
		for( i = ch ; i >= 'a'; i--){ //每一行遞減 遞減到a
			int j=i-'a';
			for(j=i-'a';j>0;j--){	//印空格	
				printf(" ");
				}
		for(j=i;j<=ch;j++){			//每一橫排從i開始
				printf("%c",j);
				}
				printf("\n");	
		}
	system("PAUSE");//暫停程式執行並等待使用者按下任意鍵
	system("CLS");
	}
	else if(ch=='B'||ch=='b'){	//第四題開始 
		printf("enter 1~9\n:");
		
		while(1){
				scanf("%d",&g);
				if(g>=1&&g<=9){	//判斷輸入數字 
						break;	//跳脫迴圈 
					}
				else{
					printf("enter again\n:");
				}
			}
		for( k=1;k<=g;k++){		//顯示九九乘法表
		for( u=1;u<=g;u++){
			printf("%d×%d=%d ",u,k,u*k);
			}
			printf("\n");
			}
		system("PAUSE");//暫停程式執行並等待使用者按下任意鍵
		system("CLS");	//第四題結束 
		}				//第五題開始 
	else if(ch=='C'||ch=='c'){
			printf("Continue?(y/n)\n");
			scanf("%c",&ps);
		while(1){
			fflush(stdin);	//清空暫存 
			scanf("%c",&ps);
			if(ps=='Y'||ps=='y'){
				break;
			}
			else if(ps=='N'||ps=='n'){
				return 0;	//程式結束
			}			
			else{
			printf("error,pls enter y/n>>");	
			}	
		}
		system("CLS");
	}
	else{					//其他 
		printf("error,pls enter a b c");
		system("PAUSE");//暫停程式執行並等待使用者按下任意鍵
		system("CLS");
		}
	}
    return 0;		//程式結束
}
