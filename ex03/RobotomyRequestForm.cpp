#include "RobotomyRequestForm.hpp"

#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	Form("RobotomyRequestForm", 72, 45),
	mTarget(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy):
	Form(cpy),
	mTarget(cpy.mTarget) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}


RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	Form::operator=(rhs);

	mTarget = rhs.mTarget;

	return (*this);
}

void RobotomyRequestForm::executeImpl() const {
	// Using it to generate random numbers
	std::fstream in("/dev/urandom");
	char c;

	if (in.is_open()) {
		in.read(&c, 1);
	} else {
		std::cerr << "RobotomyRequestForm::executeImpl: IO Error. Reverting to something else" << std::endl;

		char *tmp = new char[1];

		c = tmp[0];

		delete[] tmp;
	}

	std::cout << "Zzzz zzzzzzzzzzz zz..." << std::endl;
	if ((c % 2) == 0) {
		std::cout << mTarget << " has been successfully robotomized." << std::endl;
	} else {
		std::cout << mTarget << "'s robotomy has been failed. Woops." << std::endl;
	}
}

const std::string &RobotomyRequestForm::getTarget() const {
	return mTarget;
}
