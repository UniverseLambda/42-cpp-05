#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &cpy) {
}

Intern::~Intern() {
}


Intern &Intern::operator=(const Intern &rhs) {
	return (*this);
}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const {
	return NULL;
}
