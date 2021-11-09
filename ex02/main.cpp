#include "Bureaucrat.hpp"

#include "Form.hpp"

#include <iostream>
#include <iomanip>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		AutoPtr<Form> form0(new ShrubberyCreationForm("Dr House"));
		AutoPtr<Form> form1(new ShrubberyCreationForm("I LIKE ARBRE"));

		theGreatShrek.executeForm(*form0);
		anybody.executeForm(*form1);
		beholdTheKaren.executeForm(*form0);
		beholdTheKaren.executeForm(*form1);

		theGreatShrek.signForm(*form0);
		anybody.signForm(*form1);

		theGreatShrek.executeForm(*form0);
		anybody.executeForm(*form1);
		beholdTheKaren.executeForm(*form0);
		beholdTheKaren.executeForm(*form1);
	}

	std::cout << "=======================================================" << std::endl;
	{
		AutoPtr<Form> form0(new RobotomyRequestForm("FirePape")); // Rip mdr
		AutoPtr<Form> form1(new RobotomyRequestForm("DJ Saaskel"));

		theGreatShrek.signForm(*form0);
		anybody.signForm(*form1);

		theGreatShrek.executeForm(*form0);
		anybody.executeForm(*form1);
		beholdTheKaren.executeForm(*form0);
		beholdTheKaren.executeForm(*form1);
	}
	std::cout << "*******************************************************" << std::endl << std::endl;

	std::cout << "=======================================================" << std::endl;
	{
		AutoPtr<Form> form0(new PresidentialPardonForm("DJ Saaskel"));
		AutoPtr<Form> form1(new PresidentialPardonForm("FirePape"));


		theGreatShrek.signForm(*form0);
		anybody.signForm(*form1);

		theGreatShrek.executeForm(*form0);
		anybody.executeForm(*form1);
		beholdTheKaren.executeForm(*form0);
		beholdTheKaren.executeForm(*form1);
	}
	std::cout << "*******************************************************" << std::endl << std::endl;
}

int main(void) {
	test();
	return 0;
}
