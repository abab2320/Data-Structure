#pragma once
#include "Item.h"
#include <iostream>
//��ʾý����й������Ʒ���࣬��������޸�
#define kinds 3 
using namespace std;

class ManagerSys
{
public:
	//��¼ÿ�ֱַ������
	int num[kinds] = {0};
	int All = 0;
	//�ø���ָ�������ָ��ÿһ������
	Item** itemArry;
	//ȷ���ļ������Ҽ�¼��Ϊ��
	bool FileisExit;

	//���캯��
	ManagerSys();
	
	void show_menu();
	void Exist();


	//�����Ʒ
	void Add_item();
	//��ʾ��Ʒ
	void Show_item();
	//��ѯ��Ʒ
	void Find_item();
	void Find_title();
	
	//������ʾ
	void Sort_item();
	//���������
	void bubble();
	//��������ʾ
	void Sort_author();
	//��������ʾ
	void Sort_rate();

	//���ձ��ɾ����Ʒ
	void Del_item();

	//��ʾ��Ʒ����Ϣ
	void Sta_item();
	//ͳ�Ƹ�����������Ʒ����
	void Sta_rate();
	//�޸���Ʒ����Ϣ
	void Mod_item();
	//������Ϣ
	void Save_item();
	//���ϵͳ
	void Clean_item();


	int get_num();
	int Find_ID(int id);



	~ManagerSys();
};

