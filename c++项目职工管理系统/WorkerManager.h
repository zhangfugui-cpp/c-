#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"
#include <fstream>
#define  FILENAME "empFile.txt"

class WorkerManager {
public:
	//�ñ����ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	WorkerManager();

	~WorkerManager();

	void showManager();

	void exsitSystem();

	//��¼��Ա����
	int m_Empnum;
	//Ա������ָ��
	Worker ** m_EmpArray;

	//�����Ա����
	void addEmp();

	//��ʾְ������
	void showEmp();

	//�����ļ�
	void save();

	//����ְ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//�ж�Ա���Ƿ����
	int isExist(int id);

	//ɾ��Ա��
	void deleteWorker();

	//�޸�Ա��
	void Mod_Emp();

	//����Ա��
	void find_Emp();
};
