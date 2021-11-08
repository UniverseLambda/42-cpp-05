#include "Bureaucrat.hpp"

#include "Form.hpp"

#include <iostream>
#include <iomanip>


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
	std::cout << "=======================================================" << std::endl;
	{

		Form ezForm("The good ol' form", 100, 140);
		Bureaucrat bossman("BG of all BG", 20);

		displayInformation("ezForm", ezForm);
		displayInformation("bossman", bossman);

		std::cout << "* signing *" << std::endl;
		bossman.signForm(ezForm);
		std::cout << "* signed *" << std::endl;

		displayInformation("ezForm", ezForm);
		displayInformation("bossman", bossman);

	}
	std::cout << "*******************************************************" << std::endl << std::endl;


	std::cout << "=======================================================" << std::endl;
	{

		Form ezForm("The good ol' form", 100, 140);
		Bureaucrat noobie("LoL player", 140);

		displayInformation("ezForm", ezForm);
		displayInformation("noobie", noobie);

		std::cout << "* signing *" << std::endl;
		noobie.signForm(ezForm);
		std::cout << "* signed *" << std::endl;

		displayInformation("ezForm", ezForm);
		displayInformation("noobie", noobie);

	}
	std::cout << "*******************************************************" << std::endl << std::endl;


	std::cout << "=======================================================" << std::endl;
	{

		try {
			Form impossible("Impossible form", 0, 140);

			displayInformation("impossible", impossible);
		} catch (std::exception &e) {
			std::cout << "Nobody can be that perfect. Sorry." << std::endl;
			std::cout << "(Caught an exception: " << e.what() << ")" << std::endl;
		}

	}
	std::cout << "*******************************************************" << std::endl << std::endl;


	std::cout << "=======================================================" << std::endl;
	{

		try {
			Form impossible("Impossible form", 1, 160);

			displayInformation("impossible", impossible);
		} catch (std::exception &e) {
			std::cout << "Nobody can be that bad. Sorry." << std::endl;
			std::cout << "(Caught an exception: " << e.what() << ")" << std::endl;
		}

	}
	std::cout << "*******************************************************" << std::endl << std::endl;
}

int main(void) {
	test();

	return 0;
}
