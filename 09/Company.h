#ifndef _COMPANY_H_
#define _COMPANY_H_
#include "Manager.h"
#include "CTO.h"
#include <vector>


class Company
{
private:
    Company(void);
    ~Company(void);
    Company(Company&);
    static Company company;
    vector<Employee*> empVector;
public:
    void run(void);
    void printMenu(void);
    void addEmployee(void);
    void deleteEmployee(void);
    void updateEmployee(void);
    void queryEmployee(void);
    void queryAll(void);
    void queryOne(void);
    void paySalary(void);
    static Company& getCompany(void);
    int size(void) const;
    Employee* loadInfo(const string& name);
protected:
};

#endif
