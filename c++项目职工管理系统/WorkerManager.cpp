#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"


WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件未创建
	if (!ifs.is_open()) {
		cout << "该文件为空" << endl;
		this->m_Empnum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//文件存在且数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_Empnum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//文件存在且保存职工数据
	int num = this->get_EmpNum();
	cout << "职工个数为：" << num << endl; 
	this->m_Empnum = num;  //更新成员属性 

	this->m_EmpArray = new Worker * [this->m_Empnum];
	init_Emp();
	for (int i = 0; i < m_Empnum; i++)
	{
		cout << "职工号： " << this->m_EmpArray[i]->m_Id
			<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
			<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	}
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
}

void WorkerManager::showManager() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exsitSystem() {
	cout << "退出系统" << endl;
	system("pause");
}

void WorkerManager::addEmp() {
	cout << "请输入要添加员工数量" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0) {
		//计算新空间大小
		int newsize = addnum + this->m_Empnum;

		//创建数组
		Worker** newspace = new Worker * [newsize];

		//将原空间放到新空间之下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_Empnum; i++) {
				newspace[i] = this->m_EmpArray[i];
			}
		}

		//输入新的数据
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int Dselect;

			cout << "请输入第" << this->m_Empnum + i << "个员工的编号" << endl;
			cin >> id;
			cout << "请输入第" << this->m_Empnum + i << "个员工的姓名" << endl;
			cin >> name;
			cout << "请选择该员工的岗位" << endl;
			cout << "1.老板" << endl;
			cout << "2.经理" << endl;
			cout << "3.员工" << endl;
			cin >> Dselect;

			Worker* worker = NULL;
			switch (Dselect) {
			case 1:
				worker = new Boss(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new employee(id, name, 3);
				break;
			}
		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向和大小
		this->m_EmpArray = newspace;
		this->m_Empnum = newsize;
		this->m_FileIsEmpty = false;

		cout << "成功添加" << addnum << "名员工" << endl;
		this->save();
	
    }
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::showEmp() {
	cout << "员工的信息为" << endl;
	cout << "总共有" << this->m_Empnum << "名员工" << endl;
	for (int i = 0; i < this->m_Empnum; i++) {
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_Empnum; i++) {
		ofs << this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_DeptId;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Boss(id, name, 1);
		}
		if (dId == 2) {
			worker = new Manager(id, name, 2);
		}
		if (dId == 3) {
			worker = new employee(id, name, 3);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}

int WorkerManager::isExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_Empnum; i++) {
		if (id == this->m_EmpArray[i]->m_Id) {
			index = i;
		}
	}
	return index;
}

void WorkerManager::deleteWorker() {
	if (this->m_FileIsEmpty) {
		cout << "该员工不存在" << endl;
	}
	else {
		cout << "请输入要删除的员工号" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {
			for (int i=index; i < this->m_Empnum; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "该员工不存在" << endl;
	}
	else {
		cout << "请输入要修改的员工编号" << endl;
		int id;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {
			delete this->m_EmpArray[index];

			int Id;
			string Name;
			int Dselect;

			cout << "请输入新的员工编号" << endl;
			cin >> id;
			cout << "请输入新的员工姓名" << endl;
			cin >> Name;
			cout << "请选择该员工的岗位" << endl;
			cout << "1.老板" << endl;
			cout << "2.经理" << endl;
			cout << "3.员工" << endl;
			cin >> Dselect;

			Worker* worker = NULL;
			switch (Dselect) {
			case 1:
				worker = new Boss(id, Name, 1);
			case 2:
				worker = new Manager(id, Name, 2);
			case 3:
				worker = new employee(id, Name, 3);
			}

			this->m_EmpArray[index] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else {
			cout << "修改失败，该员工不存在" << endl;
		}
	}
	//按任意键 清屏
	system("pause");
	system("cls");
}

void WorkerManager::find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "该员工不存在" << endl;
	}
	else {
		cout << "请输入要查找的员工编号" << endl;
		int id;
		cin >> id;
		int index = this->isExist(id);
		if (id != -1) {
			cout << "查找到该员工" << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
}