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
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�����������,���·������Ա��" << endl;
}

string Manager::getDeptName() {
	return string("����");
}