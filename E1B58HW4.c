#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MAX_STUDENTS 10
#define NUM_SUBJECTS 3

// �ǥ͵��c��w�q
typedef struct {
    char name[50]; // �ǥͩm�W
    int id; // �ǥ;Ǹ�
    float grades[NUM_SUBJECTS]; // �ǥͦ��Z
    float average; // �������Z
} Student;

Student students[MAX_STUDENTS]; // �ǥͼƲ�
int studentCount = 0; // �ǥͼƶq

// �M�ſù����
void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Windows �t�βM�̫��O
    #else
        system("clear"); // UNIX �t�βM�̫��O
    #endif
}

// ���ݥΤ���U���N����
void waitForKeyPress() {
    printf("�����N���^�D���...\n");
    getchar(); // ����Enter��
    getchar(); // ���ݥΤ���U���N��
}

// ��J�ǥͦ��Z���
void enterGrades() {
    int n;
    printf("�п�J�ǥͼƶq�]5~10����ơ^: ");
    // ���ҿ�J���ǥͼƶq
    while (scanf("%d", &n) != 1 || n < 5 || n > 10) {
        printf("��J���~�A�п�J5��10���������: ");
        while (getchar() != '\n'); // �M�ſ�J�w�İ�
    }

    // �̦���J�C�Ӿǥͪ��H��
    int i;
    for ( i = 0; i < n; i++) {
        if (studentCount >= MAX_STUDENTS) {
            printf("�ǥͼƶq�w�F�W���C\n");
            return;
        }

        printf("��J�ǥͩm�W: ");
        scanf("%s", students[studentCount].name);

        printf("��J�Ǹ��]6���ơ^: ");
        // ���ҿ�J���Ǹ�
        while (scanf("%d", &students[studentCount].id) != 1 || students[studentCount].id < 100000 || students[studentCount].id > 999999) {
            printf("��J���~�A�п�J6���ƪ��Ǹ�: ");
            while (getchar() != '\n'); // �M�ſ�J�w�İ�
        }

        float sum = 0;
        // �̦���J�U�즨�Z
        int j;
        for (j = 0; j < NUM_SUBJECTS; j++) {
            const char* subjects[] = {"�ƾ�", "���z", "�^��"};
            printf("��J%s���Z�]0~100���^: ", subjects[j]);
            // ���ҿ�J�����Z
            while (scanf("%f", &students[studentCount].grades[j]) != 1 || students[studentCount].grades[j] < 0 || students[studentCount].grades[j] > 100) {
                printf("��J���~�A�п�J0��100���������Z: ");
                while (getchar() != '\n'); // �M�ſ�J�w�İ�
            }
            sum += students[studentCount].grades[j];
        }
        students[studentCount].average = sum / NUM_SUBJECTS; // �p�⥭�����Z
        studentCount++;
    }
}

// ��ܾǥͦ��Z���
void displayGrades() {
    clearScreen();
    int i,j;
    for ( i = 0; i < studentCount; i++) {
        printf("�ǥͩm�W: %s\n", students[i].name);
        printf("�Ǹ�: %d\n", students[i].id);
        printf("�U�즨�Z: ");
        for ( j = 0; j < NUM_SUBJECTS; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\n�������Z: %.2f\n", students[i].average);
    }
    waitForKeyPress(); // ���ݥΤ���U���N��
}

// �d�߾ǥͦ��Z���
void searchGrades() {
    clearScreen();
    char searchName[50];
    printf("��J�n�d�ߪ��ǥͩm�W: ");
    scanf("%s", searchName);
    int i,j;
    for ( i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("�ǥͩm�W: %s\n", students[i].name);
            printf("�Ǹ�: %d\n", students[i].id);
            printf("�U�즨�Z: ");
            for ( j = 0; j < NUM_SUBJECTS; j++) {
                printf("%.2f ", students[i].grades[j]);
            }
            printf("\n�������Z: %.2f\n", students[i].average);
            waitForKeyPress(); // ���ݥΤ���U���N��
            return;
        }
    }
    printf("�����ǥ� %s �����Z�C\n", searchName);
    waitForKeyPress(); // ���ݥΤ���U���N��
}

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
} 
//�Ĥ@�D����
