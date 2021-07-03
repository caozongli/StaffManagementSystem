#ifndef __WORKERMANAGER__
#define __WORKERMANAGER__
#include <iostream>
#include <fstream>
#include <vector>
#include "factory.cpp"
#define FILENAME "empFile.txt"


class WorkerManager
{
public:
    WorkerManager();
    void Show_Menu() const; // 菜单展示
    void exitSystem() const; // 退出系统
    void Add_Emp(); // 职工添加
    void save() const; // 保存文件
    int getEmpNum(); // 统计文件的人数
    ~WorkerManager();

private:
    bool m_FileIsEmpty;
    
    std::vector <WorkerFactory*> m_EmptyArray;

};


#endif