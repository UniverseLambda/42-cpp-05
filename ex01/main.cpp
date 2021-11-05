#include "Bureaucrat.hpp"

#include "Form.hpp"

#include <iostream>
#include <iomanip>

/**
 * Helper class for stdout separator for exercise tests
 */
struct Ex {
	Ex(int exNum) {
		std::cout << "//////////////////////// EX 0" << exNum << " \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl << std::endl;
	}

	~Ex() {
		std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\|///////////////////////////" << std::endl << std::endl;
	}
};


/**
 * Helper class for stdout separator for tests of the same exercise
 */
struct Test {
	Test() {
		std::cout << "=======================================================" << std::endl;
	}

	~Test() {
		std::cout << "*******************************************************" << std::endl << std::endl;
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

// Just to demonstrate it's still working
void ex00() {
	Ex e(0);

	{
		Test t;

		Bureaucrat theRealBureaucrat("I'm a real Bureaucrat", 1);
		displayInformation("theRealBureaucrat", theRealBureaucrat);

		try {
			theRealBureaucrat.incrementGrade();
		} catch (std::exception &e) {
			std::cout << "Can't be better than perfection, sorry pal" << std::endl;
			std::cout << "(Caught an exception: " << e.what() << ")" << std::endl;
		}

		std::cout << theRealBureaucrat << std::endl;
		theRealBureaucrat.decrementGrade();
		std::cout << theRealBureaucrat << std::endl;
	}

	{
		Test t;

		Bureaucrat zeRilBureaucrate("Aïm eu ril Bureaucrate", 150);
		displayInformation("zeRilBureaucrate", zeRilBureaucrate);

		try {
			zeRilBureaucrate.decrementGrade();
		} catch (std::exception &e) {
			std::cout << "Can't be worse than Karen, sorry pal" << std::endl;
			std::cout << "(Caught an exception: " << e.what() << ")" << std::endl;
		}

		std::cout << zeRilBureaucrate << std::endl;
		zeRilBureaucrate.incrementGrade();
		std::cout << zeRilBureaucrate << std::endl;
	}

	{
		Test t;
		try {

			Bureaucrat zeBestBureaucrate("Tqt frere je suis le best", 0);
			displayInformation("zeBestBureaucrate", zeBestBureaucrate);

			std::cerr << "Wait... What?" << std::endl;
		} catch (std::exception &e) {
			std::cout << "Your grade is sus" << std::endl;
			std::cout << "(Caught an exception: " << e.what() << ")" << std::endl;
		}
	}

	{
		Test t;

		try {

			Bureaucrat zeWorstBureaucrate("Tqt frere je suis le best", 151);
			displayInformation("zeWorstBureaucrate", zeWorstBureaucrate);

			std::cerr << "Wait... What?" << std::endl;
		} catch (std::exception &e) {
			std::cout << "Your grade is sus" << std::endl;
			std::cout << "(Caught an exception: " << e.what() << ")" << std::endl;
		}
	}
}

void ex01() {
	Ex e(1);

	{
		Test t;

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

	{
		Test t;

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
}

int main(void) {
	ex00();
	ex01();

	return 0;
}
