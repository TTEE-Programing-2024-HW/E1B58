#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int main(){
    
    //�Ĥ@�D�ӤH����e��
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��************************************************��\n");
	printf("��************************************************��\n");
	printf("��****EEEEEE**1***BBBB*********555555**888888*****��\n");
	printf("��****E******11***B***B********5*******8****8*****��\n");
	printf("��****E*******1***B***B********5*******8****8*****��\n");
	printf("��****E*******1***B***B********5*******8****8*****��\n");
	printf("��****E*******1***B***B********5*******8****8*****��\n");
	printf("��****EEEEE***1***BBBBB********555555**888888*****��\n");
	printf("��****E*******1***B****B************5**8****8*****��\n");
	printf("��****E*******1***B****B************5**8****8*****��\n");
	printf("��****E*******1***B****B************5**8****8*****��\n");
	printf("��****E*******1***B****B************5**8****8*****��\n");
	printf("��****EEEEEE*111**BBBBB********555555**888888*****��\n");
	printf("��************************************************��\n");
	printf("��************************************************��\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	
	system("PAUSE");//�Ȱ��{������õ��ݨϥΪ̫��U���N��
	system("CLS");//�M���ù�
	
    
    char password[] = "2024"; // ���T���K�X
    char input[20]; // �Ω󱵦��K�X��J
    int attempt = 0; // �K�X���զ���
    
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
//�Ĥ@�D����
//�ĤG�D�}�l 
	while(1){
    printf("~=welcome=~\n");
    printf("������������������������������������\n");
    printf("��a.�e�X�����T���Ρ�\n");
    printf("��b.��ܭ��k��    ��\n");
    printf("��c.����          ��\n");
    printf("������������������������������������\n");
//�ĤG�D����
//�ĤT�D�}�l
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
		for( i = ch ; i >= 'a'; i--){ //�C�@�滼�� �����a
			int j=i-'a';
			for(j=i-'a';j>0;j--){	//�L�Ů�	
				printf(" ");
				}
		for(j=i;j<=ch;j++){			//�C�@��Ʊqi�}�l
				printf("%c",j);
				}
				printf("\n");	
		}
	system("PAUSE");//�Ȱ��{������õ��ݨϥΪ̫��U���N��
	system("CLS");
	}
	else if(ch=='B'||ch=='b'){	//�ĥ|�D�}�l 
		printf("enter 1~9\n:");
		
		while(1){
				scanf("%d",&g);
				if(g>=1&&g<=9){	//�P�_��J�Ʀr 
						break;	//����j�� 
					}
				else{
					printf("enter again\n:");
				}
			}
		for( k=1;k<=g;k++){		//��ܤE�E���k��
		for( u=1;u<=g;u++){
			printf("%d��%d=%d ",u,k,u*k);
			}
			printf("\n");
			}
		system("PAUSE");//�Ȱ��{������õ��ݨϥΪ̫��U���N��
		system("CLS");	//�ĥ|�D���� 
		}				//�Ĥ��D�}�l 
	else if(ch=='C'||ch=='c'){
			printf("Continue?(y/n)\n");
			scanf("%c",&ps);
		while(1){
			fflush(stdin);	//�M�żȦs 
			scanf("%c",&ps);
			if(ps=='Y'||ps=='y'){
				break;
			}
			else if(ps=='N'||ps=='n'){
				return 0;	//�{������
			}			
			else{
			printf("error,pls enter y/n>>");	
			}	
		}
		system("CLS");
	}
	else{					//��L 
		printf("error,pls enter a b c");
		system("PAUSE");//�Ȱ��{������õ��ݨϥΪ̫��U���N��
		system("CLS");
		}
	}
    return 0;		//�{������
}
