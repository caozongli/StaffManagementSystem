#include "workerManager.h"
#include <iostream>
using namespace std;

inline
WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open()) 
    {
        cout << "文件不存在" << endl;
        m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空" << endl;
        m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    cout << "文件中人数为：" << getEmpNum() << endl;
}

inline
void WorkerManager::Show_Menu() const
{
    cout << "***********************************************************" << endl;
    cout << "***************** 欢迎使用职工管理系统 ********************" << endl;
    cout << "******************** 0.退出管理程序 ***********************" << endl;
    cout << "******************** 1.增加职工信息 ***********************" << endl;
    cout << "******************** 2.显示职工信息 ***********************" << endl;
    cout << "******************** 3.删除离职职工 ***********************" << endl;
    cout << "******************** 4.修改职工信息 ***********************" << endl;
    cout << "******************** 5.查找职工信息 ***********************" << endl;
    cout << "******************** 6.按照编号排序 ***********************" << endl;
    cout << "******************** 7.清空所有文档 ***********************" << endl;
    cout << "***********************************************************" << endl;
    cout << endl;
}

inline
void WorkerManager::exitSystem() const
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::Add_Emp()
{
    cout << "请输入增加职工数量：" << endl;
    int addNum = 0;
    cin >> addNum;
    int n = 1;
    if(addNum>0)
    {
        while(addNum--)
        {
            int id;
            char* name;
            int dSelect;

            cout << "请输入第" << n << "个新职工编号：" << endl;
            cin >> id;
            cout << "请输入第" << n++ << "个新职工姓名：" << endl;
            string s;
            cin >> s;
            name = new char[s.length()+1];
            strcpy(name, s.c_str());

            cout << "请选择该职工的岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.公司经理" << endl;
            cout << "3.公司老板" << endl;
            cin >> dSelect;
            WorkerFactory* w = nullptr;
            switch (dSelect)
            {
            case 1:
                w = new EmployeeFactory();
                w->produceWorker(id, name, dSelect);
                m_EmptyArray.push_back(w);
                break;
            case 2:
                w = new ManagerFactory();
                w->produceWorker(id, name, dSelect);
                m_EmptyArray.push_back(w);
                break;
            case 3:
                w = new BossFactory();
                w->produceWorker(id, name, dSelect);
                m_EmptyArray.push_back(w);
                break;
            default:
                break;
            }
        }
        save();
        cout << "添加成功" << endl;
        m_FileIsEmpty = false;
    }
    else
    {
        cout << "输入有误，请重新输入" << endl;
    }
    system("pause");
    system("cls");

}

void
WorkerManager::save() const
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 用输出方式打开文件

    for(auto p: m_EmptyArray)
    {
        ofs << p->getID() << " "
            << p->getName() << " "
            << p->getDeptID() << endl;
    }

    ofs.close();
}

inline int
WorkerManager::getEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string s;
    int did;
    int num=0;
    char* name = nullptr;
    WorkerFactory* w;
    while(ifs >> id && ifs >> s && ifs >> did)
    {
        num++;
        name = new char[s.length()+1];
        strcpy(name, s.c_str());
        w = new EmployeeFactory();
        w->produceWorker(id, name, did);
        m_EmptyArray.push_back(w);
    }
    m_FileIsEmpty = true;
    return num;
}

inline
WorkerManager::~WorkerManager()
{
    for(auto p: m_EmptyArray) delete p;
}