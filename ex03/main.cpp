#include "Bureaucrat.hpp"

#include "Form.hpp"

#include "Intern.hpp"

#include <iostream>
#include <iomanip>

/**
 * Helper class that acts as a pointer but auto-free it when out-of-scope
 */
template <typename _PtrType>
class AutoPtr {
private:
	_PtrType *ptr;

public:
	template<typename _OtherPtrType>
	explicit AutoPtr(_OtherPtrType *ptr): ptr(ptr) {
	}

private:
	AutoPtr(const AutoPtr<_PtrType> &) {}

	AutoPtr &operator=(const AutoPtr<_PtrType> &) {
		return *this;
	}

public:
	_PtrType &operator*() const {
		return *ptr;
	}

	_PtrType &operator->() const {
		return *ptr;
	}

	~AutoPtr(){
		delete ptr;
	}
};

void displayInformation(std::string varName, Bureaucrat &b) {
	std::cout << varName << "                          " << b << std::endl;
	std::cout << varName << " name:                    " << b.getName() << std::endl;
	std::cout << varName << " grade:                   " << b.getGrade() << std::endl;
}

void displayInformation(std::string varName, Form &f) {
	std::cout << varName << "                          " << f << std::endl;
	std::cout << varName << " name:                    " << f.getName() << std::endl;
	std::cout << varName << " is signed:               " << f.isSigned() << std::endl;
	std::cout << varName << " minimum signing grade:   " << f.getSigningGrade() << std::endl;
	std::cout << varName << " minimum execution grade: " << f.getExecutionGrade() << std::endl;
}

void test() {
	Bureaucrat theGreatShrek("Shrek", 1);
	Bureaucrat anybody("(totally unfunny common-as-hell name)", 80);
	Bureaucrat beholdTheKaren("Karen", 150);

	std::cout << "=======================================================" << std::endl;
	{
		Intern someRandomIntern;

		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");


		theGreatShrek.executeForm(*rrf);
		anybody.executeForm(*rrf);
		beholdTheKaren.executeForm(*rrf);

		theGreatShrek.signForm(*rrf);
		anybody.signForm(*rrf);
		beholdTheKaren.signForm(*rrf);

		theGreatShrek.executeForm(*rrf);
		anybody.executeForm(*rrf);
		beholdTheKaren.executeForm(*rrf);

		delete rrf;
	}
	std::cout << "*******************************************************" << std::endl << std::endl;

	std::cout << "=======================================================" << std::endl;
	{
		Intern slave;

		Form* rrf;
		rrf = slave.makeForm("shrubbery creation", "Dr House");

		theGreatShrek.signForm(*rrf);
		anybody.signForm(*rrf);
		beholdTheKaren.signForm(*rrf);

		theGreatShrek.executeForm(*rrf);
		anybody.executeForm(*rrf);
		beholdTheKaren.executeForm(*rrf);

		delete rrf;
	}
	std::cout << "*******************************************************" << std::endl << std::endl;

	std::cout << "=======================================================" << std::endl;
	{
		Intern slave;

		Form* rrf;
		rrf = slave.makeForm("presidential pardon", "DJ Saaskel");

		theGreatShrek.signForm(*rrf);
		anybody.signForm(*rrf);
		beholdTheKaren.signForm(*rrf);

		theGreatShrek.executeForm(*rrf);
		anybody.executeForm(*rrf);
		beholdTheKaren.executeForm(*rrf);

		delete rrf;
	}
	std::cout << "*******************************************************" << std::endl << std::endl;

	std::cout << "=======================================================" << std::endl;
	{
		Intern slave;

		Form* rrf;
		rrf = slave.makeForm("get better", "DJ Saaskel");

		if (rrf == NULL) {
			std::cout << "makeForm returned NULL" << std::endl;
		} else {
			std::cout << "Wait... What?" << std::endl;
		}
	}
	std::cout << "*******************************************************" << std::endl << std::endl;
}

int main(void) {
	test();
	return 0;
}
