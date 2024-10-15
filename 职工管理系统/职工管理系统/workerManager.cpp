#include "workerManager.h"
#include <iostream>
#include <string>
using namespace std;



workerManager::workerManager()
{
	//�ļ������ڣ���һ��ʹ��
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ��ָ��
		this->EmpArry = NULL;
		//��ʼ������
		this->Empnum = 0;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ��ָ��
		this->EmpArry = NULL;
		//��ʼ������
		this->Empnum = 0;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	else//�ļ������Ҳ�Ϊ��
	{
		int num = this->get_Empnum();
		//cout << "ְ������Ϊ" << num << endl;
		this->Empnum = num;
		//���ٿռ�
		this->EmpArry = new worker* [this->Empnum];
		//���ļ��е����ݴ浽������
		this->init_Emp();
	}
}
int workerManager::get_Empnum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	
	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//ͳ����������
		num++;
	}
	return num;
}

//���ĵ��е���Ϣ¼�����
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(filename, ios::in);

	int id;
	string name;
	int did;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* wo = NULL;

		if (did == 1)//��ְͨ��
		{
			wo = new employee(id, name, 1);
		}
		else if (did == 2)//����
		{
			wo = new manager(id, name, 2);
		}
		else if (did == 3)//Ա��
		{
			wo = new boss(id, name, 3);
		}
		this->EmpArry[i] = wo;
		i++;
	}
	ifs.close();
}

int workerManager::IsExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->Empnum; i++)
	{
		if (id == this->EmpArry[i]->ID)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workerManager::Show_Menu()
{
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "*****0.�˳�����ϵͳ" << endl;
	cout << "*****1.����ְ����Ϣ" << endl;
	cout << "*****2.��ʾְ����Ϣ" << endl;
	cout << "*****3.ɾ����ְְ��" << endl;
	cout << "*****4.�޸�ְ����Ϣ" << endl;
	cout << "*****5.����ְ����Ϣ" << endl;
	cout << "*****6.���ձ������" << endl;
	cout << "*****7.���������ĵ�" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

void workerManager::Add_Emp()
{
	cout << "��������ӵ�ְ������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)//���
	{
		//������ӵ��µĿռ��С
		int newSize = this->Empnum + addNum;

		//�����¿ռ�
		worker** newSpace = new worker * [newSize];

		//��ԭ���ռ�����ݼ����¿ռ���
		if (this->EmpArry != NULL)
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				newSpace[i] = this->EmpArry[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << "����ְ���ı�ţ�" << endl;
			while (true)
			{
				cin >> id;
				if (this->IsExit(id) == -1)
				{
					break;
				}
				else
				{
					cout << "ְ������ظ�������������:" << endl;
				}
				
			}
			cout << "������� " << i + 1 << "����ְ����������" << endl;
			cin >> name;
			while (true)
			{
				cout << "��ѡ���ְ���ĸ�λ" << endl;
				cout << "1.��ְͨ��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3) break;
				else cout << "�����������������" << endl;
			}
			worker* wo = NULL;
			switch (dSelect)
			{
			case 1:
				wo = new employee(id, name, 1);
				break;
			case 2:
				wo = new manager(id, name, 2);
				break;
			case 3:
				wo = new boss(id, name, 3);
				break;
			}
			//��������ְ��ָ�뱣�ֵ�������
			newSpace[this->Empnum + i] = wo;
		}
		
		//�ͷ�ԭ�еĿռ�
		delete[]this->EmpArry;

		//�����¿ռ��ָ��
		this->EmpArry = newSpace;
		//����ְ������
		this->Empnum = newSize;

		//����ְ����Ϊ�յ����
		this->FileIsEmpty = false;
		//��ʾ
		cout << "�ɹ����" << addNum << "����Ա��" << endl;
	}
	else {
		cout << "�������" << endl;
		return;
	}

	//�����ݱ������ļ���
	this->save();
}


void workerManager::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);//������ķ�ʽ���ļ���д�ļ�

	//��ÿ���˵���Ϣд���ļ���
	for (int i = 0; i < this->Empnum; i++)
	{
		ofs << this->EmpArry[i]->ID << " " << this->EmpArry[i]->name << " " << this->EmpArry[i]->depID << endl;
	}
	ofs.close();
}

void workerManager::show_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->Empnum; i++)
		{
			this->EmpArry[i]->showInfo();
		}
	}
	//�������������
	
	
}

//ɾ��ְ��  �����е�����ɾ���������Ͼ�������ǰ��
void workerManager::del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//����Ա�����ɾ��Ա��
		cout << "��������Ҫɾ����Ա����ţ�" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);

		if (index != -1)//˵��ְ���Ƿ���ڣ�����ɾ����Ա��
		{
			for (int i = index; i < this->Empnum; i++)
			{
				this->EmpArry[i] = this->EmpArry[i++];
			}
			this->Empnum--;//���������м�¼����Ա
			//���µ��ļ���
			this->save();

			cout << "ɾ���ɹ�" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" << endl;
		}
	}
	
}

void workerManager::mod_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)
		{
			delete this->EmpArry[index];
			int newID;
			string newName;
			int newdid;

			cout << "�鵽" << id << "��Ա�����������¹��ţ�" << endl;
			cin >> newID;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "��������ְ��" << endl;
			cout << "1����ְͨ��" << endl << "2������" << endl << "3���ϰ�" << endl;
			cin >> newdid;

			worker* wo = NULL;
			if (newdid == 1)
			{
				wo = new employee(newID, newName, 1);
			}
			else if (newdid == 2)
			{
				wo = new manager(newID, newName, 2);
			}
			else if (newdid == 3)
			{
				wo = new boss(newID, newName, 3);
			}
			this->EmpArry[index] = wo;
			cout << "�޸ĳɹ�" << this->EmpArry[index]->depID << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "���޴���" << endl;
		}
	}
}
void workerManager::find_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�Ĳ��ҷ�ʽ" << endl;
		cout << "1������Ų���" << endl;
		cout << "2������������" << endl;
		int select;
		while (true)
		{	
			cin >> select;
			if (select == 1 || select == 2) break;
			else cout << "�����������������" << endl;
		}
		if (select == 1)
		{
			cout << "��������Ҫ���ҵı��" << endl;
			int id;
			cin >> id;
			int ret = this->IsExit(id);
			if (ret == -1)
			{
				cout << "���޴���" << endl;
			}
			else 
			{
				this->EmpArry[ret]->showInfo();
				return;
			}
		}
		else if (select == 2)
		{
			cout << "��������Ҫ���ҵ����֣�" << endl;
			string name;
			cin >> name;
			
			int flag = 0;
			for (int i = 0; i < this->Empnum; i++)
			{
				if (this->EmpArry[i]->name == name)
				{
					this->EmpArry[i]->showInfo();
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "���޴���" << endl;
			}
		}
	}
}

void workerManager::sort_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������Ҫ������ʽ" << endl;
		cout << "1���Ӵ�С" << endl;
		cout << "2����С����" << endl;
		int select;
		while (true)
		{
			cin >> select;
			if (select == 1 || select == 2) break;
			else cout << "�����������������" << endl;
		}
		this->bubble();
		if (select == 1)
		{
			for (int i = this->Empnum - 1; i >= 0; i--)
			{
				this->EmpArry[i]->showInfo();
			}		
		}
		else
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				this->EmpArry[i]->showInfo();
			}
		}
	}
}

void workerManager::bubble()
{
	for (int i = 0; i < this->Empnum; i++)
	{
		int flag = 0;
		for (int j = 0; j < this->Empnum -i-1; j++)
		{
			if (this->EmpArry[j]->ID > this->EmpArry[j + 1]->ID)
			{
				worker* temp = this->EmpArry[j];
				this->EmpArry[j] = this->EmpArry[j + 1];
				this->EmpArry[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void workerManager::clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs(filename, ios::trunc);
		ofs.close();

		if (this->EmpArry != NULL)
		{
			for (int i = 0; i < this->Empnum; i++)
			{
				if (this->EmpArry[i] != NULL)
				{
					delete this->EmpArry[i];
				}
			}
			this->Empnum = 0;
			delete[]this->EmpArry;
			this->EmpArry = NULL;
			this->FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
}

workerManager::~workerManager()
{
	if (this->EmpArry != NULL)
	{
		for (int i = 0; i < this->Empnum; i++)
		{
			if (this->EmpArry[i] != NULL)
			{
				delete this->EmpArry[i];
			}
		}
		this->Empnum = 0;
		delete[]this->EmpArry;
		this->EmpArry = NULL;
		this->FileIsEmpty = true;
	}
}