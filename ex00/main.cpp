#include "Bureaucrat.hpp"

#include <iostream>

void displayInformation(std::string varName, Bureaucrat &b) {
	std::cout << varName << " " << b << std::endl;
	std::cout << varName << " name:  " << b.getName() << std::endl;
	std::cout << varName << " grade: " << b.getGrade() << std::endl;
}

int main(void) {
	std::cout << "======================================================" << std::endl;
	{

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
	std::cout << "******************************************************" << std::endl << std::endl;

	std::cout << "======================================================" << std::endl;
	{

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
	std::cout << "******************************************************" << std::endl << std::endl;

	std::cout << "======================================================" << std::endl;
	try {

		Bureaucrat zeBestBureaucrate("Tqt frere je suis le best", 0);
		displayInformation("zeBestBureaucrate", zeBestBureaucrate);

		std::cerr << "Wait... What?" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Your grade is sus" << std::endl;
		std::cout << "(Caught an exception: " << e.what() << ")" << std::endl;
	}
	std::cout << "******************************************************" << std::endl << std::endl;

	std::cout << "======================================================" << std::endl;
	try {

		Bureaucrat zeWorstBureaucrate("Tqt frere je suis le best", 151);
		displayInformation("zeWorstBureaucrate", zeWorstBureaucrate);

		std::cerr << "Wait... What?" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Your grade is sus" << std::endl;
		std::cout << "(Caught an exception: " << e.what() << ")" << std::endl;
	}
	std::cout << "******************************************************" << std::endl << std::endl;

	return 0;
}
