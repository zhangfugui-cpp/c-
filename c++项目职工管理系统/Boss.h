#pragma once
using namespace std;
#include <iostream>
#include "Worker.h"

//æ≠¿Ì¿‡
class Boss:public Worker{
public:
	Boss(int id, string name, int Did);

	virtual void showInfo();

	virtual string getDeptName();
};