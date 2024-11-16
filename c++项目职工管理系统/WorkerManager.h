#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"
#include <fstream>
#define  FILENAME "empFile.txt"

class WorkerManager {
public:
	//该变量判断文件是否为空
	bool m_FileIsEmpty;

	WorkerManager();

	~WorkerManager();

	void showManager();

	void exsitSystem();

	//记录人员个数
	int m_Empnum;
	//员工数组指针
	Worker ** m_EmpArray;

	//添加人员功能
	void addEmp();

	//显示职工功能
	void showEmp();

	//保存文件
	void save();

	//保存职工数据
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//判断员工是否存在
	int isExist(int id);

	//删除员工
	void deleteWorker();

	//修改员工
	void Mod_Emp();

	//查找员工
	void find_Emp();
};
