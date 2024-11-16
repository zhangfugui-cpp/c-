#pragma once
using namespace std;
#include <iostream>
#include "Worker.h"

class Manager :public Worker {
public:
	Manager(int m_Id, string name, int Did);

	virtual void showInfo();

	virtual string getDeptName();
};