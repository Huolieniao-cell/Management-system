a.out:Employee.o main.o Manager.o Technician.o CTO.o Company.o
	g++ *.o -g -o a.out
Employee.o:Employee.cpp
	g++ -c -g Employee.cpp
main.o:main.cpp
	g++ -c -g main.cpp
Manager.o:Manage.cpp
	g++ -c -g Manage.cpp
Technician.o:Technician.cpp
	g++ -c -g Technician.cpp
CTO.o:CTO.cpp
	g++ -c -g CTO.cpp
Company.o:Company.cpp
	g++ -c -g Company.cpp
clean:
	rm *.o *.out *.txt
distclean:
	rm *.o *.out *.txt 1000*