using namespace std;
#include <iostream>
#include "Worker.h"
#include "employee.h"

employee::employee(int m_Id, string name, int Did) {
	this->m_Id = m_Id;
	this->m_Name = name;
	this->m_DeptId = Did;
}

void employee::showInfo() {
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�����������" << endl;
}

string employee::getDeptName() {
	return string("Ա��");
}