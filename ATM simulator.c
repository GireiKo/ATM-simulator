#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char ac1[] = "1100", ac2[] = "1111";		//�˻�1���˻�2���˺�
char psw1[] = "123456", psw2[] = "654321";	//�˻�1���˻�2������
double balance1 = 10000.0, balance2 = 20000.0;	//�˻�1���˻�2�����
double withdrawn = 0.0;						//�ۼ�ȡ���
int a1 = 0, a2 = 0;							//�˻�1��2�ۼ������������Ĵ���
int ac = 0;									//�˻�ѡ����������ڼ�¼����ʹ�õ�����һ���˻�

void deposit(int ac) {

}

void withdraw(int ac) {

}

void inqbalance(int ac) {
	switch (ac)
	{
	case 1: printf("�������Ϊ%.2lf\n", balance1); break;
	case 2: printf("�������Ϊ%.2lf\n", balance2); break;
	default:
		break;
	}
}

void transfer(int ac) {

}


void menu() {
	printf("��ѡ���ܣ�1.��� 2.ȡ�� 3.��ѯ��� 4.ת��\n");
}

int main() {

	int choice = 0;							//�˵�ѡ�����
	char inputpsw[6];						//��¼�û����������
	puts("��������п� (1.1100 2.1111)");	//����1��2��ѡ�������˻�,�����������1/2�����
	scanf("%d", &ac);
	for (;a1<3 && a2<3;) {
		puts("���������룺");
			scanf("%s", inputpsw);	//������δ����6λ�����
			if (ac == 1) {
				if (strcmp(psw1, inputpsw) == 0)break;
				else a1++;
			}
			if (ac == 2) {
				if (strcmp(psw2, inputpsw) == 0)break;
				else a2++;
			}
	}
	
	if (ac == 1 && a1 <= 3 || ac == 2 && a2 <= 3) {
		for (;;) {
			menu();
			scanf("%d", &choice);
			switch (choice)
			{
				case 1: deposit(ac); break;
				case 2: withdraw(ac); break;
				case 3: inqbalance(ac); break;
				case 4: transfer(ac); break;
				default:break;
			}
			puts("�Ƿ����ʹ�ã�1.�� 2.��");
			scanf("%d", &choice);
			if (choice == 1) break;
		}
	}

	return 0;
}
