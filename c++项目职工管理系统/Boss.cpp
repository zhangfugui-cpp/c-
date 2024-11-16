#include <iostream>
using namespace std;
#include "Worker.h"
#include "Boss.h"

Boss::Boss(int id, string name, int DId) {
	this->m_Id = m_Id;
	this->m_Name = name;
	this->m_DeptId = DId;
}

void Boss::showInfo() {
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName() {
	return string("老板");
}