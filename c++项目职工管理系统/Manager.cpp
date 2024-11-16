using namespace std;
#include <iostream>
#include "Worker.h"
#include "Manager.h"

Manager::Manager(int m_Id, string name, int Did) {
	this->m_Id = m_Id;
	this->m_Name = name;
	this->m_DeptId = Did;
}

void Manager::showInfo() {
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成经理交给的任务,并下发任务给员工" << endl;
}

string Manager::getDeptName() {
	return string("经理");
}