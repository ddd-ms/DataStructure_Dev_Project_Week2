#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<stdlib.h>
using namespace std;
typedef struct {
	char name[20];
	unsigned int age;
	char sex[5];
	int finshed;
	int appoint;
	int account;
	char code[10];
	unsigned int score[5];
	unsigned int pay[5];
	bool acquired;

}Examinee;
typedef Examinee* Eme;

map<int, Eme>Examinee_sheet;

struct administrator {
	int account;
	string code;
	administrator() {};
};
struct administrator one_adm;
void eme_system();
void System();
void eme_output(Eme);
Eme eme_search(int);
bool eme_login(Eme &);
bool eme_appointment(Eme&);
Eme eme_register();
Eme eme_creat();
void eme_pay(Eme);

void adm_modify(Eme&);
void adm_system();

void adm_creat();

int main() {
	adm_creat();
	int n;
	while (1) {
		System();
		printf("是否退出驾考报名系统 如果退出请输入0\n按任意键重新进入驾考系统\n");//
		printf("Input:");
		cin >> n;
		if (n == 0) break;

	}
	printf("退出报名系统\n");
	printf("感谢您的使用\n");
}

void adm_creat() {
	one_adm.account = 2020204480;
	one_adm.code = "xhh123";
}

void System() {

	printf("\t\t\t\t**********************欢迎使用驾考报名系统*******************\n");
	printf("请选择您的身份\n我是考生请输入：1\n我是管理者请输入: 2\n");

	int sle;

	while (1) {
		printf("Input:");
		cin >> sle;
		system("cls"); 
		if (sle == 1) { //进入考生系统
			printf("\t\t\t\t\t\t\t正在进入考生系统\n");
			eme_system();
			break;

		}
		else if (sle == 2) {
		system("cls"); 
			printf("正在进入管理员系统");
			adm_system();
			break;
		}
		else {
			system("cls"); 
			printf("Error 请重新输入\n");//！！是否需要重新输入
			printf("是否需要重新输入\n");
			printf("如果继续登录请输入1\n,否则退出报名系统\n");
			int chose;
			cin >> chose;
			if (chose == 0) {
				break;
			}

		}
		
	}

	/*printf("正在退出报名系统\n");
	printf("感谢您的使用\n");*/
}

/*管理员系统*/
void adm_system() {
	while (1) {
		printf("请输入管理员账号：");
		int account;
		string code;
		cin >> account;
		printf("请输入管理员密码：");
		cin >> code;

		if (one_adm.account == account && one_adm.code == code) {//登录成功
 		system("cls"); 
			printf("登陆成功\n");
			while (1) {
				
				printf("\t\t\t\t    ******************请选择管理员的操作*****************\n");
				printf("修改考生信息请输入1\n删除考生请输入2\n查看所有考生信息请输入3\n输入0退出\n");
				printf("Input:");
				int slet;
				cin >> slet;
				Eme one_examinee;
				if (slet == 1) {  //修改考生
					//搜索考生账号
					while (1) {
						printf("请输入要搜索的考生账号\n");
						int acc;
						cin >> acc;
						if ((one_examinee = eme_search(acc)) != NULL) { //
							printf("查找成功\n");
							break;
						}
						else {
							printf("查找失败是否继续搜索考生\n如果退出请输入0\n");
							int cho;
							cin >> cho;
							if (cho == 0)break;
						}
					}	
					while(1){
						 adm_modify(one_examinee);
							printf("已成功修改\n");												
							printf("请问是否还需要继续修改：\n");
							printf("退出请按0，继续请按1\n");
							int sle1;
							cin >> sle1;
							if (sle1 == 0) break;												
					} 
				}
				else if (slet == 2) {//搜索考生账号
					while (1) {
						printf("请输入要搜索的考生账号\n");
						int acc;
						cin >> acc;
						if (eme_search(acc)!=NULL) {
							Examinee_sheet[acc]->acquired = false;
						
							printf("成功删除考生\n");
							
						}
						else {
							printf("查找失败\n");							
						}
						printf("是否继续搜索考生,如果退出请输入0\n");
						printf("Input:");
						int cho;
						cin >> cho;
						if (cho == 0)break;

					}


				}
				else if (slet == 3) {
					map<int, Eme>::iterator it;
					int cnt = 1;
					
					for (it = Examinee_sheet.begin(); it != Examinee_sheet.end(); it++) {
						cout << cnt << "：考生的信息\n";
						eme_output(it->second);
						cnt++;
					}
				}
				else if (slet == 0)break;
				else {
					printf("Error 请重新输入\n");//！！是否需要重新输入
					
				}



			}



			break;
		}
		else {//登陆失败
			printf("登陆失败\n");
			printf("是否继续登录如果继续登录请输入1，否则退出\n");
			int chose;
			cin >> chose;
			if (chose == 0) {
				break;
			}
		}
	}
	printf("正在退出管理员系统\n");
	return;
}

Eme eme_creat() {
	Eme examinee = (Eme)malloc(sizeof(Examinee));
	if (!examinee)return NULL;
	examinee->acquired = true;
	examinee->appoint = 0;
	examinee->finshed = 0;
	examinee->pay[1] = 80;
	examinee->pay[2] = 240;
	examinee->pay[3] = 200;
	examinee->pay[4] = 40;
	return examinee;
}

/*考生系统*/
void eme_system() {
 	system("cls"); 
	printf("\t\t\t\t\t      **********请选择登录或注册************\n");
	printf("登录请输入1\n注册请输入2\n退出请输入0\n");
	int slet1;
	Eme examinee;   //!！不需要创建，只会产生废物空账号

	//examinee = eme_creat();
	while (1) {
		printf("Input:");
		cin >> slet1;

		if (slet1 == 1) {
			int loginsucced=0;
			int cho;
			while (1) {
				if (eme_login(examinee)) {
					loginsucced = 1;
					break;
				}
				printf("登陆失败请重新登录\n");
				printf("是否继续登录，否请输入0\n");

				printf("Input:");
				cin >> cho;
				if (cho == 0) break;

			}
			if (loginsucced) {
				int slet2;


				while (1) {
 					system("cls"); 
					printf("\t\t\t\t\t     ************请选择考生服务************\n");
					printf("查询考试信息请输入1\n");
					printf("预约考试请输入2\n");
					printf("退出当前请输入0\n");
					printf("Input:");

					cin >> slet2;
					if (slet2 == 1) {
						eme_output(examinee);
						break;
					}
					else if (slet2 == 2) {
						if (!eme_appointment(examinee))
							printf("预约失败\n");
						else {
							printf("预约成功\n");
							printf("请缴纳考试费用\n");
							eme_pay(examinee);
							//adm_modify();
						}
						break;
					}
					else if (slet2 == 0) break;
					else {
						printf("ERROR 请重新输入\n");
					}
				}

			}
			break;//退出大循环
		}
		else if (slet1 == 2) {
			examinee = eme_register();
			printf("注册完毕\n");
			Examinee_sheet[examinee->account] = examinee;
			//!!注册完毕就存入map
		}
		else if (slet1 == 0) {
			printf("已经退出\n");
			break;
		}
		else printf("Error 请重新输入\n");

		printf("登录请输入1\n注册请输入2\n退出请输入0\n");
	}
	return;//！！不返回
}

void eme_pay(Eme examinee) {
	printf("您需要缴纳科目%d 的费用共%d 元\n", examinee->appoint, examinee->pay[examinee->appoint]);
	printf("恭喜您缴费成功\n");
}

void eme_output(Eme examinee) {
	cout << "该考生的姓名：" << examinee->name << endl;
	cout << "该考生的年龄：" << examinee->age << endl;
	cout << "该考生的性别：" << examinee->sex << endl;
	cout << "该考生的账号：" << examinee->account << endl;
	printf("该考生已完成的考试：");	
	if (examinee->appoint == 0) printf("您还未预约考试！\n");

	else {

		for (int i = 1; i <= examinee->finshed; i++)
		printf("科目 %d  分数：%d \n", i, examinee->score[i]);
		printf("\n该考生成功预约科目%d考试\n", examinee->appoint);
		printf("该考生需要缴纳的费用：%d\n", examinee->pay[examinee->appoint]);
	}
}

bool eme_appointment(Eme& examinee) {
	if (!examinee->acquired)return false;
	if (examinee->finshed == 4) {
		printf("该考生已通过所有考生\n");
		return false;
	}
	examinee->appoint = examinee->finshed + 1;
	return true;
}

/*考生信息注册*/
Eme eme_register() {
	Eme eme = eme_creat();
	printf("请输入姓名：");
	cin >> eme->name;
	printf("请输入年龄： ");
	cin >> eme->age;
	printf("请输入性别： ");
	cin >> eme->sex;
	printf("请输入账号：");
	cin >> eme->account;
	printf("请输入密码：");
	cin >> eme->code;
	for(int i=1;i<=4;i++)
	eme->score[i]=0;
	while (1) {
		printf("请确认密码：");
		char code[10];
		cin >> code;

		if (!strcmp(code, eme->code)) {
			printf("注册成功\n");
			break;
		}
		else {
			printf("密码错误 请重新输入\n");
		}
	}
	return eme;
}

bool eme_login(Eme &examinee) {//!!修改从map中搜索账号然后返回回去，不然永远会错
	int acc;
	char code[20];
	printf("请输入账号：");
	cin >> acc;
	printf("请输入密码：");
	cin >> code;

	map<int, Eme> ::iterator it;
	it = Examinee_sheet.find(acc);
	if (it != Examinee_sheet.end()) {//找到
		if (acc == (it->second)->account && !strcmp(code, (it->second)->code)) {
			examinee = it->second;
			printf("登录成功\n");
			return true;
		}
		else {
			printf("密码错误\n");
			return false;
		}
	}
	else {
		printf("没有找到您输入的账号\n");
		return false;
	}
}
/*修改考生信息*/
void adm_modify(Eme& one) {
	
system("cls"); 		
		printf("\t\t\t\t\t   ************请选择要修改的信息************\n");
		printf("选择修改信息:\n");
		printf("1==修改年龄\n2==修改预约进度\n3==修改密码\n4==修改成绩\n5==修改考试进度\n6==修改缴费情况\n");
		int sle;
		cin >> sle;

		if (sle == 1) {
			int a;
			printf("请输入年龄");
			cin >> a;
			one->age = a;

		}
		else if (sle == 2) {
			int b;
			printf("请输入预约进度：1==科一\n2==科二\n3==科三");
			cin >> b;
			one->appoint = b;
			printf("该考生预约进度：%d", b);


		}
		else if (sle == 3) {
			string s;

			printf("请输入想要修改的密码：不少于10位字符");

			cin >> s;
			for (int i = 0; i < s.size(); i++) {
				one->code[i] = s[i];
			}
			//one->code=s;

		}
		else if (sle == 4) {
			unsigned int c;
			int d;
			printf("请输入成绩科目: 1==科一\n2==科二\n3==科三 ");
			cin >> d;
			cin >> c;
			one->score[d] = c;


		}
		else if (sle == 5) {
			int d;
			printf("请输入考试进度：1==科一完成\n2==科二完成\n3==科三完成");
			cin >> d;
			one->finshed = d;
			printf("该考生考试进度为：%d", d);

		}
		else if (sle == 6) {
			int a;
			int b;
			int c;
			printf("请分别输入科目一、科目二、科目三的缴费情况：0==缴费成功\n1==未缴费");

			cin >> a >> b >> c;

			printf("请选择要查看的科目的缴费进度：\n1==科一缴费情况%d及金额%d\n2==科二缴费情况%d及金额%d\n3==科三缴费情况%d及金额%d", a, one->pay[1], b, one->pay[2], c, one->pay[3]);


		}

		return ;
	
}

Eme eme_search(int acc) {
	map<int, Eme>::iterator it;
	int flag = 0;
	for (it = Examinee_sheet.begin(); it != Examinee_sheet.end(); it++) {
		if (it->first == acc) {
			flag = 1;
			break;
		}
	}
	if (flag)return it->second;
	else return NULL;

}
