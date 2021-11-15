#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): mName(name), mGrade(grade) {
	if (mGrade < 1)
		throw GradeTooHighException();
	else if (mGrade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy): mName(cpy.mName), mGrade(cpy.mGrade) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	// Nope. It's const. Can't modify one
	// mName = rhs.mName;
	mGrade = rhs.mGrade;
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return mName;
}

int Bureaucrat::getGrade() const {
	return mGrade;
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

Bureaucrat::GradeTooHighException::GradeTooHighException() throw() {
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Invalid grade: too high (< 1)";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() throw() {
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Invalid grade: too low (> 150)";
}

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs) {
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << '.';
	return lhs;
}
