/*
progream:employee system
name:xie jigui
time:2020.10.01
vison:1.0
email:847958870@qq.com
 */
#include "Employee.h"
// #include "Manager.h"
#include "Manager.h"
#include "Technician.h"
#include "CTO.h"
#include "Company.h"

void init(void)
{
    if(access("id.txt",F_OK)==-1)
    {
        FILE *fp=fopen("id.txt","w");
        fprintf(fp,"%d",INIT_NUM);
        fclose(fp);
    }
    if(access("count.txt",F_OK)==-1)
    {
        FILE *fp2=fopen("count.txt","w");
        fprintf(fp2,"%d",0);
        fclose(fp2);
    }
}
int main(void)
{
    // init();
    // cout << "count:" << Employee::getCount() << endl;
    // Employee b("xie",1111.1,Employee::L1);
    // b.calSalary();
    // b.printInfo();
    // Manager emp("xie",2222.2,1000);
    // emp.calSalary();
    // emp.printInfo();
    // Technician tmp("xie",3333.3,1000);
    // tmp.printInfo();
    // tmp.calSalary();
    // CTO cto("xie",4444.4,1000,1000);
    // cto.printInfo();
    // cto.calSalary();
    // cout << "count:" << Employee::getCount() << endl;
    Company& company=Company::getCompany();
    company.run();
    
    return 0;
}
