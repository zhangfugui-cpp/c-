#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"

//void test() {
//	Worker* worker = NULL;
//	worker = new employee(1, "张三", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "李四", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "王五", 3);
//	worker->showInfo();
//	delete worker;
//}

int main() {

	WorkerManager wm;
	int choice = 0;
	while (true) {
		wm.showManager();
		cin >> choice;
		switch (choice) {
		case 0: //退出系统
			break;
		case 1: //添加职工
			wm.addEmp();
			break;
		case 2: //显示职工
			wm.showEmp();
			break;
		case 3: //删除职工
			wm.deleteWorker();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.find_Emp();
			break;
		case 6: //排序职工
			break;
		case 7: //清空文件
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");

	return 0;
}