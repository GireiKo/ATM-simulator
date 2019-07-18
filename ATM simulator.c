#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char ac1[] = "1100", ac2[] = "1111";		//账户1和账户2的账号
char psw1[] = "123456", psw2[] = "654321";	//账户1和账户2的密码
double balance1 = 10000.0, balance2 = 20000.0;	//账户1和账户2的余额
double withdrawn = 0.0;						//累计取款额
int a1 = 0, a2 = 0;							//账户1和2累计密码输入错误的次数
int ac = 0;									//账户选择变量，用于记录本次使用的是哪一个账户

void deposit(int ac) {
    double num;
    if (!(ac==1||ac==2)) return;
    printf("请输入存款金额：");
    scanf("%lf",&num);
    if (ac==1) balance1 += num;
    else balance2 += num;
}

void withdraw(int ac) {

}

void inqbalance(int ac) {
	switch (ac)
	{
	case 1: printf("您的余额为%.2lf\n", balance1); break;
	case 2: printf("您的余额为%.2lf\n", balance2); break;
	default:
		break;
	}
}

void transfer(int ac) {

}


void menu() {
	printf("请选择功能：1.存款 2.取款 3.查询余额 4.转账\n");
}

int main() {

	int choice = 0;							//菜单选项变量
	char inputpsw[6];						//记录用户输入的密码
	puts("请插入银行卡 (1.1100 2.1111)");	//输入1或2来选择登入的账户,不考虑输入非1/2的情况
	scanf("%d", &ac);
	for (;a1<3 && a2<3;) {
		puts("请输入密码：");
			scanf("%s", inputpsw);	//不考虑未输入6位的情况
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
			puts("是否结束使用？1.是 2.否");
			scanf("%d", &choice);
			if (choice == 1) break;
		}
	}

	return 0;
}
