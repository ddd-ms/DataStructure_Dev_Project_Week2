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
		printf("�Ƿ��˳��ݿ�����ϵͳ ����˳�������0\n����������½���ݿ�ϵͳ\n");//
		printf("Input:");
		cin >> n;
		if (n == 0) break;

	}
	printf("�˳�����ϵͳ\n");
	printf("��л����ʹ��\n");
}

void adm_creat() {
	one_adm.account = 2020204480;
	one_adm.code = "xhh123";
}

void System() {

	printf("\t\t\t\t**********************��ӭʹ�üݿ�����ϵͳ*******************\n");
	printf("��ѡ���������\n���ǿ��������룺1\n���ǹ�����������: 2\n");

	int sle;

	while (1) {
		printf("Input:");
		cin >> sle;
		system("cls"); 
		if (sle == 1) { //���뿼��ϵͳ
			printf("\t\t\t\t\t\t\t���ڽ��뿼��ϵͳ\n");
			eme_system();
			break;

		}
		else if (sle == 2) {
		system("cls"); 
			printf("���ڽ������Աϵͳ");
			adm_system();
			break;
		}
		else {
			system("cls"); 
			printf("Error ����������\n");//�����Ƿ���Ҫ��������
			printf("�Ƿ���Ҫ��������\n");
			printf("���������¼������1\n,�����˳�����ϵͳ\n");
			int chose;
			cin >> chose;
			if (chose == 0) {
				break;
			}

		}
		
	}

	/*printf("�����˳�����ϵͳ\n");
	printf("��л����ʹ��\n");*/
}

/*����Աϵͳ*/
void adm_system() {
	while (1) {
		printf("���������Ա�˺ţ�");
		int account;
		string code;
		cin >> account;
		printf("���������Ա���룺");
		cin >> code;

		if (one_adm.account == account && one_adm.code == code) {//��¼�ɹ�
 		system("cls"); 
			printf("��½�ɹ�\n");
			while (1) {
				
				printf("\t\t\t\t    ******************��ѡ�����Ա�Ĳ���*****************\n");
				printf("�޸Ŀ�����Ϣ������1\nɾ������������2\n�鿴���п�����Ϣ������3\n����0�˳�\n");
				printf("Input:");
				int slet;
				cin >> slet;
				Eme one_examinee;
				if (slet == 1) {  //�޸Ŀ���
					//���������˺�
					while (1) {
						printf("������Ҫ�����Ŀ����˺�\n");
						int acc;
						cin >> acc;
						if ((one_examinee = eme_search(acc)) != NULL) { //
							printf("���ҳɹ�\n");
							break;
						}
						else {
							printf("����ʧ���Ƿ������������\n����˳�������0\n");
							int cho;
							cin >> cho;
							if (cho == 0)break;
						}
					}	
					while(1){
						 adm_modify(one_examinee);
							printf("�ѳɹ��޸�\n");												
							printf("�����Ƿ���Ҫ�����޸ģ�\n");
							printf("�˳��밴0�������밴1\n");
							int sle1;
							cin >> sle1;
							if (sle1 == 0) break;												
					} 
				}
				else if (slet == 2) {//���������˺�
					while (1) {
						printf("������Ҫ�����Ŀ����˺�\n");
						int acc;
						cin >> acc;
						if (eme_search(acc)!=NULL) {
							Examinee_sheet[acc]->acquired = false;
						
							printf("�ɹ�ɾ������\n");
							
						}
						else {
							printf("����ʧ��\n");							
						}
						printf("�Ƿ������������,����˳�������0\n");
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
						cout << cnt << "����������Ϣ\n";
						eme_output(it->second);
						cnt++;
					}
				}
				else if (slet == 0)break;
				else {
					printf("Error ����������\n");//�����Ƿ���Ҫ��������
					
				}



			}



			break;
		}
		else {//��½ʧ��
			printf("��½ʧ��\n");
			printf("�Ƿ������¼���������¼������1�������˳�\n");
			int chose;
			cin >> chose;
			if (chose == 0) {
				break;
			}
		}
	}
	printf("�����˳�����Աϵͳ\n");
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

/*����ϵͳ*/
void eme_system() {
 	system("cls"); 
	printf("\t\t\t\t\t      **********��ѡ���¼��ע��************\n");
	printf("��¼������1\nע��������2\n�˳�������0\n");
	int slet1;
	Eme examinee;   //!������Ҫ������ֻ�����������˺�

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
				printf("��½ʧ�������µ�¼\n");
				printf("�Ƿ������¼����������0\n");

				printf("Input:");
				cin >> cho;
				if (cho == 0) break;

			}
			if (loginsucced) {
				int slet2;


				while (1) {
 					system("cls"); 
					printf("\t\t\t\t\t     ************��ѡ��������************\n");
					printf("��ѯ������Ϣ������1\n");
					printf("ԤԼ����������2\n");
					printf("�˳���ǰ������0\n");
					printf("Input:");

					cin >> slet2;
					if (slet2 == 1) {
						eme_output(examinee);
						break;
					}
					else if (slet2 == 2) {
						if (!eme_appointment(examinee))
							printf("ԤԼʧ��\n");
						else {
							printf("ԤԼ�ɹ�\n");
							printf("����ɿ��Է���\n");
							eme_pay(examinee);
							//adm_modify();
						}
						break;
					}
					else if (slet2 == 0) break;
					else {
						printf("ERROR ����������\n");
					}
				}

			}
			break;//�˳���ѭ��
		}
		else if (slet1 == 2) {
			examinee = eme_register();
			printf("ע�����\n");
			Examinee_sheet[examinee->account] = examinee;
			//!!ע����Ͼʹ���map
		}
		else if (slet1 == 0) {
			printf("�Ѿ��˳�\n");
			break;
		}
		else printf("Error ����������\n");

		printf("��¼������1\nע��������2\n�˳�������0\n");
	}
	return;//����������
}

void eme_pay(Eme examinee) {
	printf("����Ҫ���ɿ�Ŀ%d �ķ��ù�%d Ԫ\n", examinee->appoint, examinee->pay[examinee->appoint]);
	printf("��ϲ���ɷѳɹ�\n");
}

void eme_output(Eme examinee) {
	cout << "�ÿ�����������" << examinee->name << endl;
	cout << "�ÿ��������䣺" << examinee->age << endl;
	cout << "�ÿ������Ա�" << examinee->sex << endl;
	cout << "�ÿ������˺ţ�" << examinee->account << endl;
	printf("�ÿ�������ɵĿ��ԣ�");	
	if (examinee->appoint == 0) printf("����δԤԼ���ԣ�\n");

	else {

		for (int i = 1; i <= examinee->finshed; i++)
		printf("��Ŀ %d  ������%d \n", i, examinee->score[i]);
		printf("\n�ÿ����ɹ�ԤԼ��Ŀ%d����\n", examinee->appoint);
		printf("�ÿ�����Ҫ���ɵķ��ã�%d\n", examinee->pay[examinee->appoint]);
	}
}

bool eme_appointment(Eme& examinee) {
	if (!examinee->acquired)return false;
	if (examinee->finshed == 4) {
		printf("�ÿ�����ͨ�����п���\n");
		return false;
	}
	examinee->appoint = examinee->finshed + 1;
	return true;
}

/*������Ϣע��*/
Eme eme_register() {
	Eme eme = eme_creat();
	printf("������������");
	cin >> eme->name;
	printf("���������䣺 ");
	cin >> eme->age;
	printf("�������Ա� ");
	cin >> eme->sex;
	printf("�������˺ţ�");
	cin >> eme->account;
	printf("���������룺");
	cin >> eme->code;
	for(int i=1;i<=4;i++)
	eme->score[i]=0;
	while (1) {
		printf("��ȷ�����룺");
		char code[10];
		cin >> code;

		if (!strcmp(code, eme->code)) {
			printf("ע��ɹ�\n");
			break;
		}
		else {
			printf("������� ����������\n");
		}
	}
	return eme;
}

bool eme_login(Eme &examinee) {//!!�޸Ĵ�map�������˺�Ȼ�󷵻ػ�ȥ����Ȼ��Զ���
	int acc;
	char code[20];
	printf("�������˺ţ�");
	cin >> acc;
	printf("���������룺");
	cin >> code;

	map<int, Eme> ::iterator it;
	it = Examinee_sheet.find(acc);
	if (it != Examinee_sheet.end()) {//�ҵ�
		if (acc == (it->second)->account && !strcmp(code, (it->second)->code)) {
			examinee = it->second;
			printf("��¼�ɹ�\n");
			return true;
		}
		else {
			printf("�������\n");
			return false;
		}
	}
	else {
		printf("û���ҵ���������˺�\n");
		return false;
	}
}
/*�޸Ŀ�����Ϣ*/
void adm_modify(Eme& one) {
	
system("cls"); 		
		printf("\t\t\t\t\t   ************��ѡ��Ҫ�޸ĵ���Ϣ************\n");
		printf("ѡ���޸���Ϣ:\n");
		printf("1==�޸�����\n2==�޸�ԤԼ����\n3==�޸�����\n4==�޸ĳɼ�\n5==�޸Ŀ��Խ���\n6==�޸Ľɷ����\n");
		int sle;
		cin >> sle;

		if (sle == 1) {
			int a;
			printf("����������");
			cin >> a;
			one->age = a;

		}
		else if (sle == 2) {
			int b;
			printf("������ԤԼ���ȣ�1==��һ\n2==�ƶ�\n3==����");
			cin >> b;
			one->appoint = b;
			printf("�ÿ���ԤԼ���ȣ�%d", b);


		}
		else if (sle == 3) {
			string s;

			printf("��������Ҫ�޸ĵ����룺������10λ�ַ�");

			cin >> s;
			for (int i = 0; i < s.size(); i++) {
				one->code[i] = s[i];
			}
			//one->code=s;

		}
		else if (sle == 4) {
			unsigned int c;
			int d;
			printf("������ɼ���Ŀ: 1==��һ\n2==�ƶ�\n3==���� ");
			cin >> d;
			cin >> c;
			one->score[d] = c;


		}
		else if (sle == 5) {
			int d;
			printf("�����뿼�Խ��ȣ�1==��һ���\n2==�ƶ����\n3==�������");
			cin >> d;
			one->finshed = d;
			printf("�ÿ������Խ���Ϊ��%d", d);

		}
		else if (sle == 6) {
			int a;
			int b;
			int c;
			printf("��ֱ������Ŀһ����Ŀ������Ŀ���Ľɷ������0==�ɷѳɹ�\n1==δ�ɷ�");

			cin >> a >> b >> c;

			printf("��ѡ��Ҫ�鿴�Ŀ�Ŀ�Ľɷѽ��ȣ�\n1==��һ�ɷ����%d�����%d\n2==�ƶ��ɷ����%d�����%d\n3==�����ɷ����%d�����%d", a, one->pay[1], b, one->pay[2], c, one->pay[3]);


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
