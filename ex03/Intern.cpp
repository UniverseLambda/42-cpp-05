#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

Intern::Intern() {
	mFCDs[0].formName = "shrubbery creation";
	mFCDs[0].maker = ::makeForm<ShrubberyCreationForm>;

	mFCDs[1].formName = "robotomy request";
	mFCDs[1].maker = ::makeForm<RobotomyRequestForm>;

	mFCDs[2].formName = "presidential pardon";
	mFCDs[2].maker = ::makeForm<PresidentialPardonForm>;
}

Intern::Intern(const Intern &cpy) {
	(void)cpy;
}

Intern::~Intern() {
}


Intern &Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return (*this);
}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const {
	for (std::size_t i = 0; i < kFCDCount; ++i) {
		if (mFCDs[i].formName == formName) {
			std::cout << "Intern created " << formName << " form." << std::endl;
			return mFCDs[i].maker(target);
		}
	}
	std::cerr << "(Understandably angry intern) I'm not paid enough for this \"" << formName << "\" shit." << std::endl;
	return NULL;
}
