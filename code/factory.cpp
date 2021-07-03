#ifndef __FACTORY__
#define __FACTORY__
#include "employee.cpp"
#include "manager.cpp"
#include "boss.cpp"

class WorkerFactory
{
public:
    WorkerFactory()
    {
        _worker = nullptr;
    }

    virtual ~WorkerFactory()
    {
        if(_worker)
        {
            delete _worker;
            _worker = nullptr;
        }
    }

    void produceWorker(const int& id, const char* name, const int& desp_id)
    {
        if(_worker==nullptr)
        {
            _worker = NewWorker(id, name, desp_id);
        }
    }

    void showInfo() const
    {
        if(_worker!=nullptr)
        {
            _worker->showInfo();
        }
    }

    int getID() const
    {
        return _worker->getID();
    }

    int getDeptID() const
    {
        return _worker->getDeptID();
    }

    char* getName() const
    {
        return _worker->getName();
    }

protected:
    virtual Worker* NewWorker(const int&, const char*, const int&) = 0;

private:
    Worker* _worker;
};

class EmployeeFactory: public WorkerFactory
{
public:
    Worker* NewWorker(const int& id, const char* name, const int& desp_id)
    {
        return new Employee(id, name, desp_id);
    }
};

class ManagerFactory: public WorkerFactory
{
public:
    Worker* NewWorker(const int& id, const char* name, const int& desp_id)
    {
        return new Manager(id, name, desp_id);
    }
};

class BossFactory: public WorkerFactory
{
public:
    Worker* NewWorker(const int& id, const char* name, const int& desp_id)
    {
        return new Boss(id, name, desp_id);
    }
};

#endif