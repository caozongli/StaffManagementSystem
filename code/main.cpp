#include <iostream>
#include "workerManager.cpp"
using namespace std;

int main()
{
    WorkerManager wm;
    int choice = 0;
    // Worker* worker = NULL;
    // worker = new Boss(1, "张三", 2);
    // worker->showInfo();

    while(true)
    {
        wm.Show_Menu();
        cout << "请输入你所要执行的功能:" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0: // 推出系统
                wm.exitSystem();
                break;
            case 1: // 添加职工
                wm.Add_Emp();
                break;
            case 2: // 显示职工
                break;
            case 3: // 删除职工
                break;
            case 4: // 修改职工
                break;
            case 5: // 查找职工
                break;
            case 6: // 排序职工
                break;
            case 7: // 清空文件
                break;
            default:
                system("cls");
                break;
        }   
    }
    
    system("pause");
    return 0;
}