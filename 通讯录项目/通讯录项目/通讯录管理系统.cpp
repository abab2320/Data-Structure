#include <iostream>
#include <string>
#define Max 1000
using namespace std;
//菜单
void showMenu()
{
	cout << "1. 添加联系人" << endl;
	cout << "2. 显示联系人" << endl;
	cout << "3. 删除联系人" << endl;
	cout << "4. 查找联系人" << endl;
	cout << "5. 修改联系人" << endl;
	cout << "6. 清空联系人" << endl;
	cout << "0. 退出通讯录" << endl;
}

struct Person  //联系人结构体
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};

struct Addressbooks  //通讯录结构体
{
	struct Person personArray[Max];
	int size;                             //通讯录中的人数
};

//添加联系人
void addPerson(Addressbooks *abs)
{
	if (abs->size == Max)
	{
		cout << "通讯录已满,无法添加"<<endl;
		return;
	}
	else//添加联系人
	{	//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;
		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "男 —— 1" << endl;
		cout << "女 —— 2" << endl;
		do
		{//如果输入错误，则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			else { cout << "输入错误，请重新输入："; }
		} while (true);
		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		do
		{
			cin >> age;
			if (age > 0)
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			else { cout << "输入错误，请重新输入："; }
		} while (true);
		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->size].addr = addr;
		//更新人数
		abs->size++;
		cout << "已添加成功" << endl;

		system("pause");
		system("cls");//清屏功能
	}
}

//显示联系人
void showPerson(Addressbooks const* abs)
{	//判断是否有人
	if(abs->size == 0)
	{
		cout << "当前的记录为空" << endl;
	}
	for (int i = 0; i < abs->size; i++)
	{
		cout << "姓名：" << abs->personArray[i].name << "\t";
		cout << "性别：" << (abs->personArray[i].sex == 1 ? "男":"女") << "\t";
		cout << "年龄：" << abs->personArray[i].age << "\t";
		cout << "电话：" << abs->personArray[i].phone << "\t";
		cout << "住址：" << abs->personArray[i].addr << endl;
	}
	system("pause");
	system("cls");
}

//检查联系人是否存在，如果存在，返回具体位置，不存在返回-1
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

//删除联系人
void deletePerson(Addressbooks* abs)
{	cout << "请输入删除联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) cout << "查无此人" << endl;
	else
	{//将数据向前覆盖
		for (int i = ret; i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;//更新人数
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks *abs)
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) cout << "查无此人";
	else
	{
		cout << "姓名：" << abs->personArray[ret].name << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "电话：" << abs->personArray[ret].phone << "\t";
		cout << "住址：" << abs->personArray[ret].addr << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入你想修改的联系人" << endl;
	string m_name;
	cin >> m_name;
	int ret = isExist(abs, m_name);
	if (ret == -1) cout << "查无此人" << endl;
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;
		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "男 —— 1" << endl;
		cout << "女 —— 2" << endl;
		while (true)
		{//如果输入错误，则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			else { cout << "输入错误，请重新输入："; }
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (age > 0)
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			else { cout << "输入错误，请重新输入："; }
		}
		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->size].addr = addr;

		cout << "修改完成" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks *abs)
{
	cout << "请确定是否要全部清空" << endl;
	cout << "确定 —— 1" << endl;
	cout << "取消 —— 0" << endl;
	int flag = 0;
	cin >> flag;
	if (flag == 1)
	{
		//将size归零
		abs->size = 0;
		cout << "通讯录已清空";
	}
	system("pause");
	system("cls");
}

int main()
{	
	//通讯录结构体变量
	Addressbooks abs;  //注意abs是数不是数组哦，是abs包含了数组。
	//初始化人员个数
	abs.size = 0;
	int select = 0;
	while (true) 
	{
		//菜单的调用
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs); //利用地址传递
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}

	system("pause");   //按任意键继续
	return 0;
}
