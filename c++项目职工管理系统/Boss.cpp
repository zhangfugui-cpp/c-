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
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}