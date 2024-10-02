#include <iostream>
using namespace std;

class EmployeeDao
{
    public:
    virtual void create(string client, EmployeeDao *) = 0;
    virtual void del(string, int employeeId) = 0;
    virtual EmployeeDao * get(string client, int employeeId) = 0;
};

class EmployeeDaoImp : public EmployeeDao
{
    public:
    EmployeeDaoImp()
    {

    }

    void create(string client, EmployeeDao * emp)
    {
        cout<<"Create new roe in employee table\n";
    }
    void del(string client, int employeeId)
    {
        cout<<"Deleted employee Id\n";
    }

    EmployeeDao * get(string client , int employeeId)
    {
        cout<<"fetch data from DB\n";
        //return new EmployeeDao();
    }
};

class EmployeeDaoProxy : public EmployeeDao
{
    EmployeeDao * employeeDoeImp;
    public:
    EmployeeDaoProxy(EmployeeDao * emp)
    {
        this->employeeDoeImp = emp;
    }
    void create(string client, EmployeeDao * emp)
    {
        if(client == "ADMIN")
        {
            emp->create("ADMIN", emp);
        }
    }

    void del(string client, int EmployeeId)
    {
        if(client == "ADMIN")
        {
            employeeDoeImp->del(client, EmployeeId);
        }
    }

    EmployeeDao * get(string client, int employeeId)
    {
        employeeDoeImp->get(client, employeeId);
        //return new EmployeeDao();
    }
};

int main()
{
    EmployeeDao * employeeDao = new EmployeeDaoImp();
    EmployeeDao * proxy = new EmployeeDaoProxy(employeeDao);

    proxy->create("ADMIN", employeeDao);
    proxy->del("ADMIN", 10);

    return 0;
}