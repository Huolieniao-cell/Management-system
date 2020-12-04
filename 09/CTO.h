#ifndef _CTO_H_
#define _CTO_H_
#include "Manager.h"
#include "Technician.h"
class CTO:public Manager,public Technician
{
private:
public:
CTO(const string& filename);
CTO(const string& name,double salary,double bonus,double allow);
void printInfo(void)const;
double calSalary(void);

protected:
    double calMerit(void);
    void printExtra(void)const;
};
#endif 