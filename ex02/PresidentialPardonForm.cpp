#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	Form("PresidentialPardonForm", 25, 5),
	mTarget(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy):
	Form(cpy),
	mTarget(cpy.mTarget) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	Form::operator=(rhs);

	mTarget = rhs.mTarget;

	return (*this);
}

void PresidentialPardonForm::executeImpl() const {
	std::cout << mTarget << " has received the Presidential Pardon from Zafod Beeblo... Zafod Beebox... Zafod Beeblebrox" << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
	return mTarget;
}
