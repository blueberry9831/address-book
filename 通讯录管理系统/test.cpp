#include<iostream>
#include<string>

#define MAX 1000//最大人数

using namespace std;


//联系人结构体
struct Person
{
	string m_name;
	int m_sex;//1、男  2、女
	int m_age;
	string m_phone;
	string m_addr;//住址
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};

//添加联系人
void addPerson(Addressbooks* abs) 
{
	//判断通讯录是否已满，如果满了就不在添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		//年龄
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是1或是2可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age < 120 && age>3)
			{
				abs->personArray[abs->m_Size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;

		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_addr = address;

		//更新通讯录人数
		abs->m_Size++;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");//清屏
	}

}

//显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中的人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++) 
		{
			cout << "姓名：" << abs->personArray[i].m_name;
			cout << "\t性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女");
			cout << "\t年龄：" << abs->personArray[i].m_age;
			cout << "\t电话：" << abs->personArray[i].m_phone;
			cout << "\t住址：" << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入删除的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//查找到人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_name;
		cout << "\t性别：" << (abs->personArray[ret].m_sex == 1 ? "男" : "女");
		cout << "\t年龄：" << abs->personArray[ret].m_age;
		cout << "\t电话：" << abs->personArray[ret].m_phone;
		cout << "\t住址：" << abs->personArray[ret].m_addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (age < 120 && age>3)
			{
				abs->personArray[ret].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_phone = phone;
		//住址
		string address;
		cout << "请输入住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_addr = address;

	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks* abs)
{
	int a = 0;
	cout << "是否清空通讯录" << endl;
	cout << "1--确认" << endl;
	cout << "2--取消" << endl;
	while (true)
	{
		cin >> a;
		if (a == 1)
		{
			abs->m_Size = 0;
			cout << "通讯录已清空" << endl;
			break;
		}
		else if(a == 2)
		{
			break;
		}
		else
		{
			cout << "选择错误，请重新选择" << endl;
		}
	}

	system("pause");
	system("cls");
}

//菜单界面
void showMenu() 
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main() 
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;
	while (true) 
	{
		//菜单调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1://1、添加联系人
			addPerson(&abs);//利用地址传递，可以修改实参
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			deletePerson(&abs);
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}

	system("pause");
	return 0;
}