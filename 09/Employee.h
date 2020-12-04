#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#define INIT_NUM 10001
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <unistd.h>
using namespace std;
class Employee 
{
private:
   
    Employee(const Employee& that);
    Employee& operator=(const Employee& that);
    static int m_count;
    
protected:
    
    int m_id;
    string m_name;
    double m_salary;
    FILE *m_file;
    
    
    double m_attend;
    void printBasic(void)const;
    virtual void printExtra(void)const;
    double calBasic(void);
    virtual double calMerit(void);

public:
    enum LEVEL{L1=101,L2=201,L3=301,L4=401};
    LEVEL m_level;
    static const int& getCount(void);
    Employee(void);
    Employee(const string&);
    Employee(const string& m_name,double m_salary,LEVEL level=L1);
    virtual ~Employee(void);
    void printInfo(void)const;
    double calSalary(void);
    void setId(int id);
    void setName(const string& name);
    void setSalary(double salary);
    void saveInfo(void);
    friend ostream&  operator<<(ostream& os,const Employee& e);
    bool operator==(int id)const;
    bool operator!=(int id)const;
};


#endif