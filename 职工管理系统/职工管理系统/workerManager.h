#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define filename "empFile.txt"
using namespace std;

class workerManager
{
public:
	//��־�ļ��Ƿ�Ϊ��
	bool FileIsEmpty;
	//ͳ������
	int get_Empnum();
	//��ʼ��Ա������
	void init_Emp();
	//��¼ְ������
	int Empnum;
	//ְ������ָ��
	worker** EmpArry;

	workerManager();
	//�ж�ְ���Ƿ����
	int IsExit(int id);
	
	//��ʾ�˵�
	void Show_Menu();
	//���Ա��
	void Add_Emp();
	//�����ļ�
	void save();
	//��ʾԱ����
	void show_Emp();
	//ɾ��ְ��
	void del_Emp();
	//�޸�Ա��
	void mod_Emp();
	//����Ա��
	void find_Emp();
	//����ְ��
	void sort_Emp();
	//����ļ�
	void clean_File();
	void exitSystem();

	//ð������
	void bubble();
	~workerManager();
};

