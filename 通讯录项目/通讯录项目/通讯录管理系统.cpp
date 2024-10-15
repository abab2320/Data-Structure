#include <iostream>
#include <string>
#define Max 1000
using namespace std;
//�˵�
void showMenu()
{
	cout << "1. �����ϵ��" << endl;
	cout << "2. ��ʾ��ϵ��" << endl;
	cout << "3. ɾ����ϵ��" << endl;
	cout << "4. ������ϵ��" << endl;
	cout << "5. �޸���ϵ��" << endl;
	cout << "6. �����ϵ��" << endl;
	cout << "0. �˳�ͨѶ¼" << endl;
}

struct Person  //��ϵ�˽ṹ��
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

struct Addressbooks  //ͨѶ¼�ṹ��
{
	struct Person personArray[Max];
	int size;                             //ͨѶ¼�е�����
};

//�����ϵ��
void addPerson(Addressbooks *abs)
{
	if (abs->size == Max)
	{
		cout << "ͨѶ¼����,�޷����"<<endl;
		return;
	}
	else//�����ϵ��
	{	//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;
		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "�� ���� 1" << endl;
		cout << "Ů ���� 2" << endl;
		do
		{//��������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			else { cout << "����������������룺"; }
		} while (true);
		//����
		int age = 0;
		cout << "���������䣺" << endl;
		do
		{
			cin >> age;
			if (age > 0)
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			else { cout << "����������������룺"; }
		} while (true);
		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->size].addr = addr;
		//��������
		abs->size++;
		cout << "����ӳɹ�" << endl;

		system("pause");
		system("cls");//��������
	}
}

//��ʾ��ϵ��
void showPerson(Addressbooks const* abs)
{	//�ж��Ƿ�����
	if(abs->size == 0)
	{
		cout << "��ǰ�ļ�¼Ϊ��" << endl;
	}
	for (int i = 0; i < abs->size; i++)
	{
		cout << "������" << abs->personArray[i].name << "\t";
		cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��":"Ů") << "\t";
		cout << "���䣺" << abs->personArray[i].age << "\t";
		cout << "�绰��" << abs->personArray[i].phone << "\t";
		cout << "סַ��" << abs->personArray[i].addr << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ����ؾ���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name)
{
	int flag = -1;
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			flag = i;
			break;
		}
	}
	return flag;
}

//ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{	cout << "������ɾ����ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) cout << "���޴���" << endl;
	else
	{//��������ǰ����
		for (int i = ret; i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;//��������
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) cout << "���޴���";
	else
	{
		cout << "������" << abs->personArray[ret].name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].age << "\t";
		cout << "�绰��" << abs->personArray[ret].phone << "\t";
		cout << "סַ��" << abs->personArray[ret].addr << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "�����������޸ĵ���ϵ��" << endl;
	string m_name;
	cin >> m_name;
	int ret = isExist(abs, m_name);
	if (ret == -1) cout << "���޴���" << endl;
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;
		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "�� ���� 1" << endl;
		cout << "Ů ���� 2" << endl;
		while (true)
		{//��������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			else { cout << "����������������룺"; }
		}
		//����
		int age = 0;
		cout << "���������䣺" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0)
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			else { cout << "����������������룺"; }
		}
		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;
		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->size].addr = addr;

		cout << "�޸����" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void cleanPerson(Addressbooks *abs)
{
	cout << "��ȷ���Ƿ�Ҫȫ�����" << endl;
	cout << "ȷ�� ���� 1" << endl;
	cout << "ȡ�� ���� 0" << endl;
	int flag = 0;
	cin >> flag;
	if (flag == 1)
	{
		//��size����
		abs->size = 0;
		cout << "ͨѶ¼�����";
	}
	system("pause");
	system("cls");
}

int main()
{	
	//ͨѶ¼�ṹ�����
	Addressbooks abs;  //ע��abs������������Ŷ����abs���������顣
	//��ʼ����Ա����
	abs.size = 0;
	int select = 0;
	while (true) 
	{
		//�˵��ĵ���
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs); //���õ�ַ����
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");   //�����������
	return 0;
}
