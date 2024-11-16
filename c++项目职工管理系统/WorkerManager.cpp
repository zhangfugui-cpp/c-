#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"


WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ�δ����
	if (!ifs.is_open()) {
		cout << "���ļ�Ϊ��" << endl;
		this->m_Empnum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//�ļ�����������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->m_Empnum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//�ļ������ұ���ְ������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl; 
	this->m_Empnum = num;  //���³�Ա���� 

	this->m_EmpArray = new Worker * [this->m_Empnum];
	init_Emp();
	for (int i = 0; i < m_Empnum; i++)
	{
		cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
			<< " ְ�������� " << this->m_EmpArray[i]->m_Name
			<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	}
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
}

void WorkerManager::showManager() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exsitSystem() {
	cout << "�˳�ϵͳ" << endl;
	system("pause");
}

void WorkerManager::addEmp() {
	cout << "������Ҫ���Ա������" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0) {
		//�����¿ռ��С
		int newsize = addnum + this->m_Empnum;

		//��������
		Worker** newspace = new Worker * [newsize];

		//��ԭ�ռ�ŵ��¿ռ�֮��
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_Empnum; i++) {
				newspace[i] = this->m_EmpArray[i];
			}
		}

		//�����µ�����
		for (int i = 0; i < addnum; i++) {
			int id;
			string name;
			int Dselect;

			cout << "�������" << this->m_Empnum + i << "��Ա���ı��" << endl;
			cin >> id;
			cout << "�������" << this->m_Empnum + i << "��Ա��������" << endl;
			cin >> name;
			cout << "��ѡ���Ա���ĸ�λ" << endl;
			cout << "1.�ϰ�" << endl;
			cout << "2.����" << endl;
			cout << "3.Ա��" << endl;
			cin >> Dselect;

			Worker* worker = NULL;
			switch (Dselect) {
			case 1:
				worker = new Boss(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new employee(id, name, 3);
				break;
			}
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��ʹ�С
		this->m_EmpArray = newspace;
		this->m_Empnum = newsize;
		this->m_FileIsEmpty = false;

		cout << "�ɹ����" << addnum << "��Ա��" << endl;
		this->save();
	
    }
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::showEmp() {
	cout << "Ա������ϢΪ" << endl;
	cout << "�ܹ���" << this->m_Empnum << "��Ա��" << endl;
	for (int i = 0; i < this->m_Empnum; i++) {
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_Empnum; i++) {
		ofs << this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_DeptId;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Boss(id, name, 1);
		}
		if (dId == 2) {
			worker = new Manager(id, name, 2);
		}
		if (dId == 3) {
			worker = new employee(id, name, 3);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}

int WorkerManager::isExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_Empnum; i++) {
		if (id == this->m_EmpArray[i]->m_Id) {
			index = i;
		}
	}
	return index;
}

void WorkerManager::deleteWorker() {
	if (this->m_FileIsEmpty) {
		cout << "��Ա��������" << endl;
	}
	else {
		cout << "������Ҫɾ����Ա����" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {
			for (int i=index; i < this->m_Empnum; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_Empnum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��Ա��������" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ�Ա�����" << endl;
		int id;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {
			delete this->m_EmpArray[index];

			int Id;
			string Name;
			int Dselect;

			cout << "�������µ�Ա�����" << endl;
			cin >> id;
			cout << "�������µ�Ա������" << endl;
			cin >> Name;
			cout << "��ѡ���Ա���ĸ�λ" << endl;
			cout << "1.�ϰ�" << endl;
			cout << "2.����" << endl;
			cout << "3.Ա��" << endl;
			cin >> Dselect;

			Worker* worker = NULL;
			switch (Dselect) {
			case 1:
				worker = new Boss(id, Name, 1);
			case 2:
				worker = new Manager(id, Name, 2);
			case 3:
				worker = new employee(id, Name, 3);
			}

			this->m_EmpArray[index] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else {
			cout << "�޸�ʧ�ܣ���Ա��������" << endl;
		}
	}
	//������� ����
	system("pause");
	system("cls");
}

void WorkerManager::find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��Ա��������" << endl;
	}
	else {
		cout << "������Ҫ���ҵ�Ա�����" << endl;
		int id;
		cin >> id;
		int index = this->isExist(id);
		if (id != -1) {
			cout << "���ҵ���Ա��" << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else
		{
			cout << "���޴���" << endl;
		}
	}
}