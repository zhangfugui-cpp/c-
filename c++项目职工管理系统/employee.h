#pragma once
using namespace std;
#include <iostream>
#include "Worker.h"

class employee :public Worker{
public:
	employee(int m_Id, string name, int Did);

	virtual void showInfo();

	virtual string getDeptName();
};
