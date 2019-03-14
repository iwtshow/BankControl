#include<iostream>

#include<cstdio>

#include<cstdlib>
#include<atltime.h>

using namespace std;

#include<string>

#include<fstream>

#include<iomanip>
static double dayInterestRate=0.0001;

	static double taxRate=0.001;
	string managercode;
	static void setDailyInterestRate(double a)

	{
		dayInterestRate = a;

		cout << "�ɹ�����������!" << endl;

		cout << "����Ϊ��" << dayInterestRate << "%" << endl;
	}

	static void setTaxRate(double a)

	{
		taxRate = a;

		cout << "�ɹ�����˰��!" << endl;

		cout << "����Ϊ��" << taxRate << "%" << endl;
	} 

	static void setmanagercode(string a)

	{
		managercode = a;

		cout << "�������óɹ���" << endl;
	}

class information //�������information,���������û���Ϣ

{

public:

	

	string userNum;

	string userName;

	string userID;

	string password;

	string status;

	double money;

	int day, month, year;

	int countday;

public:

	

	void change_money_li(int cday)

	{
		money = money + money*(dayInterestRate / (double)100)*(double)countday*(1 - (taxRate / (double)100));
	}

	void add_money(double mon)

	{
		money += mon;
	}

	information() {}
	information(string a, string b, string c, string d, string e, int g, int y, int m, int da) //��������information�е�7������

	{
		userNum = a;

		userName = b;

		userID = c;

		password = d;

		status = e;

		money = g;

		day = da;

		month = m;

		year = y;

	}



	void set_password(string a)

	{
		password = a;
	}

	string get_userNum() //��ȡ���п���

	{

		return userNum;

	}

	string get_password() //��ȡ����

	{

		return password;

	}

	string get_status() //��ȡ�û�״̬

	{

		return status;

	}

	double get_money() //��ȡ�û����

	{

		return money;

	}

	void display() //����û�������Ϣ

	{
		cout << "�������û���Ϣ��" << endl;

		cout << "********************\n";

		cout << "���п��ţ�" << userNum << endl;

		cout << "�û�������" << userName << endl;

		cout << "�û����֤�ţ�" << userID << endl;

		cout << "�û����룺" << password << endl;

		cout << "����ʱ�䣺" << year << "��" << month << "��" << day << "��" << endl;
		cout << "�û����룺" << password << endl;

		cout << "�û�״̬��" << status << endl;

		cout << "�û���" << setiosflags(ios::fixed) << setprecision(3) << money << endl;

		cout << "********************\n";

		cout << endl;

	}



	void Wait()

	{

		long j = 0;

		for (double i = 1000000; i > 0;)

		{

			i = i - 0.002;

			j++;

			j--;

		}

	}

	void writeDailyInterRate()

	{
		ofstream stuf1("E:\\�߲��������������.txt", ios::out);

		stuf1 << setiosflags(ios::fixed) << setprecision(3) << dayInterestRate << " "; stuf1.close();

		cout << "����ɹ���" << endl;

		cout << endl;

	}

	
	void writesui()

	{
		ofstream stuf2("E:\\�߲��������˰��.txt", ios::out);

		stuf2 << setiosflags(ios::fixed) << setprecision(3) << taxRate << " "; stuf2.close();

		cout << "����ɹ���" << endl;

		cout << endl;

	}
};

class manager :public information//������manager���û���Ϣ���й���

{

private:

	information B[1000];

	int sum;


public:
	manager()

	{
		sum = 0;
	}

	 

	void showuserAccountNumber()

	{

		cout << "�������п��˺�Ϊ��" << setw(6) << setfill('#') << sum << endl;

	}

	void OpenAccount(information a) //����

	{

		B[sum] = a;

		sum++;

		cout << "�����ɹ�!" << endl;

		cout << endl;

		write();

	}

	void CloseAccount(information a) //����

	{
		string code; char c;

		int flag = 0;

		int count = 0;

		if (sum == 0)

		{

			cout << "�����ڸ��û�������ʧ�ܣ�" << endl;

		}

		else

		{

			for (int i = 0; i < sum; i++)

			{

				if (B[i].get_userNum() == a.get_userNum())

				{

					cout << "�ҵ����û�" << endl;

					cout << "���������룺" << endl;

					cin >> code;

					while (B[i].get_password() != code&&count <= 3)

					{
						cout << "�������,����������: (��ֻ�����λ��ᣩ";

						cin >> code;

						count++;
					}

					if (B[i].get_password() == code)

					{
						B[i].display();

						count++;

						cout << "ȷ��-Y/ȡ��-N: ";

						cin >> c;

						if (c == 'Y' || c == 'y')

						{
							for (int j = i; j < sum - 1; j++)

							{

								B[j] = B[j + 1];

							}

							flag = 1;

							sum--;

							cout << "�����ɹ���" << endl; break;

						}
					}

					if (count > 3) break;

				}

			}

			if (!flag)

			{

				cout << "���û�������!" << endl;

			}

		}
		write();


	}

	void HookAccount(information a) //�û���ʧ

	{
		char c;

		int flag = 0;

		for (int i = 0; i < sum; i++)

		{

			if (B[i].get_userNum() == a.userNum)

			{

				if (B[i].get_status() == "HOOK")

				{

					cout << "���û��ѹ�ʧ��" << endl;

					cout << endl;

					break;

				}

				else

				{
					cout << endl;

					B[i].display();

					cout << "ȷ��-Y/ȡ��-N: ";

					cin >> c;

					if (c == 'Y' || c == 'y')

					{
						flag = 1;

						B[i].status = "HOOK";

						cout << "��ʧ�ɹ���" << endl;

						cout << endl;
					}

				}

			}

		}

		if (flag == 0)

		{

			cout << "���û�������!" << endl; cout << endl;

		}

	}

	void UnhookAccount(information a)

	{
		char c; int i;

		int flag = 0;

		for (i = 0; i < sum; i++)

		{

			if (B[i].get_userNum() == a.userNum)

			{

				if (B[i].get_status() == "UNHOOK")

				{

					cout << "���û��޽��й���ʧ����" << endl; cout << endl;

					break;

				}

				else

				{

					B[i].display();

					cout << "ȷ��-Y/ȡ��-N: ";

					cin >> c;

					if (c == 'Y')

					{
						flag = 1;

						B[i].status = "UNHOOK";

						cout << "ȡ����ʧ�ɹ���" << endl; cout << endl;

					}

				}

			}

		}

		if (flag == 0)

		{

			cout << "���󣡸��û�������!" << endl; cout << endl;

		}

	}

	void Saving( information & a, double mon) //���

	{
		int i;

		for (i = 0; i < sum; i++)

		{

			if (B[i].get_userNum() == a.userNum)

			{
				if (B[i].get_status() == "HOOK")

				{
					cout << "�Բ����û��ѱ����ᣬ�޷��޸ģ�" << endl; cout << endl;
				}

				else

				{

					//������ת����Ϣ 

					{

						CTime begintime = CTime(year, month, day);

						CTime curtime = CTime::GetCurrentTime();

						CTimeSpan span;

						span = curtime - begintime;

						B[i].change_money_li(span.GetDays());

						B[i].year = curtime.GetYear();

						B[i].month = curtime.GetMonth();

						B[i].day = curtime.GetDay();

					}

					B[i].add_money(mon);

					cout << "�ɹ���" << mon << endl;

					cout << endl;
				}

			}

		}

		if (i == sum + 1)

		{
			cout << "������û������ڣ�" << endl; cout << endl;
		}

	}

	void Drawing(information a, double mon) //ȡ��

	{
		int i; char c;

		for (i = 0; i <= sum; i++)

		{

			if (B[i].get_userNum() == a.userNum)

			{
				if (B[i].get_status() == "HOOK")

				{
					cout << "�Բ����û��ѱ����ᣬ�޷��޸ģ�" << endl; cout << endl;
				}

				else

				{

					if (mon > B[i].money)

					{
						cout << "�������㣡�޷�����ȡ�" << endl; cout << endl;
					}

					else

					{
						//������ת����Ϣ 

						{

							CTime begintime = CTime(year, month, day);

							CTime curtime = CTime::GetCurrentTime();

							CTimeSpan span;

							span = curtime - begintime;

							B[i].change_money_li(span.GetDays());

							B[i].year = curtime.GetYear();

							B[i].month = curtime.GetMonth();

							B[i].day = curtime.GetDay();
						
						}

						B[i].add_money(-mon);

						cout << "�ɹ�ȡ�" << mon << endl;

						cout << "��ӡƴ����y/n" << endl;

						cin >> c;

						if (c == 'y' || c == 'Y')

						{
							cout << "ƾ����ӡ�У����Ժ�" << endl;

							B[i].Wait();

							cout << "��" << setiosflags(ios::fixed) << setprecision(3) << B[i].get_money() << endl; cout << endl;

						}

					}

				}

			}

		}

		if (i == sum + 1)

		{
			cout << "������û������ڣ�" << endl; cout << endl;
		}

	}

	void Transfering(information a) //ת��

	{
		string usernum1;

		int j;

		int i;

		int mon;

		char c;

		for (i = 0; i <= sum; i++)

		{

			if (B[i].get_userNum() == a.userNum)

			{
				if (B[i].get_status() == "HOOK")

				{
					cout << "�Բ����û��ѱ����ᣬ�޷��޸ģ�" << endl; cout << endl;
				}

				else

				{


					//������ת����Ϣ 

					{


						CTime begintime = CTime(year, month, day);

						CTime curtime = CTime::GetCurrentTime();

						CTimeSpan span;

						span = curtime - begintime;

						B[i].change_money_li(span.GetDays());

						B[i].year = curtime.GetYear();

						B[i].month = curtime.GetMonth();

						B[i].day = curtime.GetDay();

					}
					cout << "������Ҫת�˵����п��ţ�";

					cin >> usernum1;

					for (j = 0; j < sum; j++)

					{

						if (B[j].get_userNum() == usernum1)

						{
							cout << "������Ҫת�˵Ľ�" << endl;

							cin >> mon;

							if (mon > B[i].money)

							{
								cout << "�������㣡�޷�����ת�ˣ�" << endl; cout << endl;
							}

							else

							{


								B[i].add_money(-mon);

								B[j].add_money(mon);

								cout << "�ɹ����û���" << B[i].get_userNum() << "ת�˵��û���" << B[j].get_userNum() << endl;



								cout << "ת�˽��Ϊ��" << mon; cout << endl;
							}

						}

					}

				}

					

						

				

			}

		}
		
		if (j == sum + 1)

			cout << "���û������ڣ�" << endl; cout << endl;
	}

	void Inquiring(information a) //��ѯ

	{
		int i;

		for (i = 0; i <= sum; i++)

		{

			if (B[i].get_userNum() == a.userNum)

			{

				//������ת����Ϣ 

				{


					CTime begintime = CTime(year, month, day);

					CTime curtime = CTime::GetCurrentTime();

					CTimeSpan span;

					span = curtime - begintime;

					B[i].change_money_li(span.GetDays());

					B[i].year = curtime.GetYear();

					B[i].month = curtime.GetMonth();

					B[i].day = curtime.GetDay();

					

				}
				B[i].display();

			}

		}

		if (i == sum + 1)

			cout << "���û������ڣ�" << endl;

	}

	void ModifyPassword(information a, string pass) //��������

	{

		for (int i = 0; i < sum; i++)

		{

			if (B[i].get_userNum() == a.userNum)

			{

				B[i].set_password(pass);

				cout << "�ɹ��޸����룡" << endl;

			}

		}

	}

	void read() //�����ļ�����ļ��ж�ȡ��Ϣ

	{

		ifstream instuf1("E:\\bank.txt", ios::in);

		if (!instuf1 )  //

		{

			ofstream outstuff("E:\\bank.txt", ios::out);


			outstuff.close();

			ofstream p("E:\\�߲�������ݹ�������.txt", ios::out);

			p.close();

			ofstream pp("E:\\�߲���������û���.txt", ios::out);

			pp.close();

			ofstream s("E:\\�߲��������˰��.txt", ios::out);

			s.close();


			cout << "�����ĵ��ɹ�!" << endl;

			cout << endl;

		}

		else

		{

			ifstream stuf("E:\\�߲�������ݹ�������.txt", ios::in);

			stuf >> managercode;

			stuf.close();

			ifstream stuf1("E:\\�߲��������������.txt", ios::in);

			stuf1 >>dayInterestRate;

			stuf1.close();

			ifstream stuf2("E:\\�߲��������˰��.txt", ios::in);

			stuf2 >> taxRate;

			stuf2.close();

			ifstream stuf3("E:\\�߲���������û���.txt", ios::in);

			stuf3 >> sum;

			stuf3.close();
			

			for (int i = 0; i<sum; i++)

			{
				instuf1 >> B[i].userNum >> B[i].userName >> B[i].userID >> B[i].password >> B[i].status >> B[i].money 
					>> B[i].year >> B[i].month >> B[i].day ;
			}

			cout << "��ȡ���ݳɹ�!" << endl;

			cout << endl;

		}

		instuf1.close();

	}

	void writemanagercode()//����

	{
		ofstream outstuf("E:\\�߲�������ݹ�������.txt", ios::out);

		outstuf << managercode << " "; outstuf.close();

		cout << "����ɹ���" << endl;

		cout << endl;

	}

	void write() //����Ϣ�����ļ�"E:\\bank.txt"

	{
		ofstream pp("E:\\�߲���������û���.txt", ios::out);

		pp << sum;

		pp.close();

		ofstream f1("E:\\bank.txt", ios::out);

		if (!f1)

		{
			cout << "error" << endl;

			exit(1);

		}
		else 
		
		{



			for (int i = 0; i < sum; i++)

			{
				f1 << B[i].userNum << " " << B[i].userName << " " << B[i].userID << " " << B[i].password << " " << B[i].status << " " << setiosflags(ios::fixed) << setprecision(3) << B[i].money;

				f1 << " " << B[i].year << " " << B[i].month << " " << B[i].day  << endl;

			}
		}
		f1.close();

	}

	void tongji()

	{
		double countsum = 0;

		cout << "����ѽ������û������ͳ��:" << endl;

		cout << "���п��� " << " " << "���" << endl;

		for (int i = 0; i< sum; i++)

		{
			cout << B[i].userNum << " " << B[i].money << endl;
		}

		cout << endl;

		for (int i = 0; i< sum; i++)

		{
			countsum += B[i].money;
		}

		cout << "�û�����" << countsum << endl;

		cout << endl;

		cout << endl;

	}

};


int main()

{
	int choice1; int choice2; int y1, m1, d1; int r1; double x, y; string a, a1;

	while (1)

	{


		cout << "************************************************\n";

		cout << "* �����˻�����ϵͳ *\n";

		cout << "* *\n";

		cout << "* ѡ��һ������: *\n";

		cout << "* (1) ��߹���ģʽ *\n";

		cout << "* (2) ����Աģʽ (Administrator Module) *\n";

		cout << "* (3) �û�ģʽ (User Module) *\n";

		cout << "* (4) �˳�ϵͳ *\n";

		cout << "************************************************\n";

		cout << "* Your Choice (1-4):";

		cin >> choice1;

		if (choice1 == 1) //��߹���ģʽ��

		{
			char c1;

			manager worker; information user;

			int choice2;

			worker.read();

			while (1)

			{
				cout << "***********************************************\n";

				cout << "* ��߹���ģʽ *\n";

				cout << "* *\n";

				cout << "* ѡ��һ������: *\n";

				cout << "* (1) ������Ϣ(%) *\n";

				cout << "* (2) ����˰��(%) *\n";

				cout << "* (3) �������й���ԱȨ������ *\n";

				cout << "* (4) �������˵� *\n";

				cout << "***********************************************\n";

				cout << "* Your Choice (1-4):";

				cin >> choice2;

				if (choice2 == 1)

				{
					cout << "�����뱾����������(%):" << endl;

					cin >> x;

					setDailyInterestRate(x);

					user.writeDailyInterRate();

				}

				else if (choice2 == 2)

				{
					cout << "�����뱾����˰��(%):" << endl;

					cin >> y;

					cout << "ȷ��-Y/ȡ��-N" << endl;

					cin >> c1;

					if (c1 == 'Y' || c1 == 'y')

					{
						setTaxRate(y);

						user.writesui();

					}

				}

				else if (choice2 == 3)

				{
					cout << "���������й���Ա���룺" << endl;

					cin >> a;

					cout << "���ٴ��������й���Ա���룺" << endl;

					cin >> a1;

					while (a != a1)

					{
						cout << "�����������������й���Ա���룺" << endl;

						cin >> a;

						cout << "���ٴ��������й���Ա���룺" << endl;

						cin >> a1;

					}

					setmanagercode(a);

					worker.writemanagercode();

				}

				else if (choice2 == 4)

				{

					for (int i = 0; i<3; i++)

					{

						cout << " " << endl;

					}

					for (int i = 0; i<48; i++)

					{

						cout << "*";

					}

					cout << endl;

					cout << "�����˳���ģʽϵͳ��ϵͳ���������ܲ˵������Ժ�!" << endl;


					break;

				}

			}

	 }

		else if (choice1 == 2) //����Աģʽ

		{

			manager worker; worker.read(); int choice2;

			string w;

			cout << "���������Աͨ������:" << endl;

			cin >> w;

			if (w == managercode)

			{
				cout << "����������ȷ�������Խ��������˻�����ϵͳ(����Ա)" << endl;

				cout << endl;

				cout << endl;

				while (1)

				{
					cout << "***********************************************\n";

					cout << "* �����˻�����ϵͳ(����Ա) *\n";

					cout << "* *\n";

					cout << "* ѡ��һ������: *\n";

					cout << "* (1) ���� *\n";

					cout << "* (2) ��ʧ *\n";

					cout << "* (3) �����ʧ *\n";

					cout << "* (4) ���� *\n";

					cout << "* (5) ͳ�� *\n";

					cout << "* (6) �������˵� *\n";

					cout << "***********************************************\n";

					cout << "* Your Choice (1-6):";

					cin >> choice2;

					cout << endl;

					if (choice2 == 1)

					{
						string a, b, c, d1, d2; int e, f, g, h; char c1;

						cout << "�������û����ţ�6λ����" << endl;

						cin >> a;

						cout << "�������û�������" << endl;

						cin >> b;

						cout << "�������û����֤�ţ���18λ��" << endl;

						cin >> c;

						cout << "�������û����룺��6λ��" << endl;

						cin >> d1;

						cout << "���ٴ������û����룺" << endl;

						cin >> d2;

						while (d1 != d2)

						{
							cout << "���������������û����룺" << endl;

							cin >> d1;

							cout << "���ٴ������û����룺" << endl;

							cin >> d2;

						}

						cout << "�����뿪��ʱ�䣺";

						cin >> f;

						cin >> g;

						cin >> h;

						cout << "�����봢���" << endl;

						cin >> e;

						cout << endl;

						information newuser(a, b, c, d1, "UNHOOK", e, f, g, h);

						newuser.display();

						cout << "ȷ��-Y/ȡ��-N" << endl;

						cin >> c1;

						if (c1 == 'Y' || c1 == 'y')

						{
							worker.OpenAccount(newuser); worker.write();
						}

					}

					else if (choice2 == 2)//ѡ���ʧ

					{
						string a;

						cout << "������Ҫ���ʧ�Ŀ��ţ�" << endl;

						cin >> a;

						information newuser(a, " ", " ", " ", " ", 0, 0, 0, 0);

						worker.HookAccount(newuser); worker.write();

					}

					else if (choice2 == 3)//ȡ����ʧ

					{
						string a;

						cout << "������Ҫ��ȡ����ʧ�Ŀ��ţ�" << endl;

						cin >> a;

						information newuser(a, " ", " ", " ", " ", 0, 0, 0, 0);

						worker.UnhookAccount(newuser); worker.write();

					}

					else if (choice2 == 4)//����

					{
						string a;

						cout << "������Ҫ�������Ŀ��ţ�" << endl;

						cin >> a;

						information newuser(a, " ", " ", " ", " ", 0, 0, 0, 0);

						worker.CloseAccount(newuser); worker.write();

					}

					else if (choice2 == 5) {
						worker.tongji();
					}

					else if (choice2 == 6)

					{

						

						cout << endl;

						cout << "�����˳���ģʽϵͳ��ϵͳ���������ܲ˵������Ժ�!" << endl;

						cout << endl;

						break;

					}

					

				}

			}

			else {
				cout << "��������޷��������Աģʽ!" << endl;

				cout << endl;
			}

		}

		else if (choice1 == 3) //�û�ģʽ

		{
			manager worker;

			int choice2;

			worker.read();

			while (1)

			{

				cout << "***********************************************\n";

				cout << "* �����˻�����ϵͳ(�û�) *\n";

				cout << "* *\n";

				cout << "* ����ѡ��: *\n";

				cout << "* (1) ��� *\n";

				cout << "* (2) ȡ�� *\n";

				cout << "* (3) ��ѯ *\n";

				cout << "* (4) ת�� *\n";

				cout << "* (5) �������� *\n";

				cout << "* (6) ȡ�� *\n";

				cout << "***********************************************\n";

				cout << "* Your Choice (1-6):" << endl;

				cin >> choice2;

				if (choice2 == 1)

				{
					string a, b; char c; double mon;

					cout << "���������п��˺ţ�" << endl;

					cin >> a;

					cout << "�������룺" << endl;

					cin >> b;

					information newuser(a, " ", " ", b, " ", 0, 0, 0, 0);

					cout << "ȷ��-Y/ȡ��-N" << endl;

					cin >> c;

					if (c == 'Y' || c == 'y')

					{
						cout << "���������Ľ�" << endl;

						cin >> mon;

						worker.Saving(newuser, mon); worker.write();

					}

					else

					{
						cout << "����" << endl;
					}

				}

				else if (choice2 == 2)

				{
					string a, b; char c; double mon;

					cout << "���������п��˺ţ�" << endl;

					cin >> a;

					information newuser(a, " ", " ", " ", " ", 0, 0, 0, 0);

					cout << "ȷ��-Y/ȡ��-N" << endl;

					cin >> c;

					if (c == 'Y' || c == 'y')

					{
						cout << "������Ҫȡ���Ľ�" << endl;

						cin >> mon;

						worker.Drawing(newuser, mon); worker.write();

					}

					else

					{
						cout << "����" << endl;
					}

				}

				else if (choice2 == 4)

				{
					string a, b; char c; double mon;

					cout << "���������п��˺ţ�" << endl;

					cin >> a;

					information newuser(a, " ", " ", " ", " ", 0, 0, 0, 0);

					cout << "ȷ��-Y/ȡ��-N" << endl;

					cin >> c;

					if (c == 'Y' || c == 'y')

					{

						worker.Transfering(newuser); worker.write();

					}

					else

					{
						cout << "����" << endl;
					}

				}

				else if (choice2 == 3)

				{
					string a, b; char c; double mon;

					cout << "���������п��˺ţ�" << endl;

					cin >> a;

					information newuser(a, " ", " ", " ", " ", 0, 0, 0, 0);

					cout << "ȷ��-Y/ȡ��-N" << endl;

					cin >> c;

					if (c == 'Y' || c == 'y')

					{

						worker.Inquiring(newuser); worker.write();

					}

					else

					{
						cout << "����" << endl;
					}

				}

				else if (choice2 == 5)

				{
					string a, f1, f2; char c;

					cout << "���������п��˺ţ�" << endl;

					cin >> a;


					information newuser(a, " ", " ", " ", " ", 0, 0, 0, 0);

					cout << "ȷ��-Y/ȡ��-N" << endl;

					cin >> c;

					if (c == 'Y' || c == 'y')

					{
						cout << "�����������룺" << endl;

						cin >> f1;

						cout << "���ٴ��������룺" << endl;

						cin >> f2;

						while (f1 != f2)

						{
							cout << "�����������������룺" << endl;

							cin >> f1;

							cout << "���ٴ��������룺" << endl;

							cin >> f2;
						}

						worker.ModifyPassword(newuser, f1); worker.write();

					}

					else

					{
						cout << "����" << endl;
					}

				}

				else if (choice2 == 6)

				{

				

					cout << endl;

					cout << "�����˳���ģʽϵͳ��ϵͳ���������ܲ˵������Ժ�!" << endl;

				 cout << endl;

					break;
				}

			}

		}

		else if (choice1 == 4) 
		{
			
			
			
			
			break; }

	}

}