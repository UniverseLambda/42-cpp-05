#include "Bureaucrat.hpp"

#include "Form.hpp"
#include "Utils.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade): mName(name), mGrade(grade) {
	checkGrade<GradeTooLowException, GradeTooHighException>(mGrade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): mName(cpy.mName), mGrade(cpy.mGrade) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	mName = rhs.mName;
	mGrade = rhs.mGrade;
	return *this;
}

bool Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << mName << " signs " << form.getName() << std::endl;
		return true;
	} catch (std::exception &e) {
		std::cout << mName << " cannot sign because " << e.what() << std::endl;
	}
	return false;
}

void Bureaucrat::incrementGrade() {
	if (mGrade == 1)
		throw GradeTooHighException();
	--mGrade;
}

void Bureaucrat::decrementGrade() {
	if (mGrade == 150)
		throw GradeTooLowException();
	++mGrade;
}

const std::string &Bureaucrat::getName() const {
	return mName;
}

int Bureaucrat::getGrade() const {
	return mGrade;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
}

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs) {
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '.';
	return lhs;
}
