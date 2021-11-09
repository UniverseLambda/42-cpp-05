#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Utils.hpp"

Form::Form(const std::string &name, int signingGrade, int executionGrade):
	mName(name),
	mSigningGrade(signingGrade),
	mExecutionGrade(executionGrade),
	mSigned(false) {
	checkGrade<GradeTooLowException, GradeTooHighException>(mSigningGrade);
	checkGrade<GradeTooLowException, GradeTooHighException>(mExecutionGrade);
}

Form::Form(const Form &cpy):
	mName(cpy.mName),
	mSigningGrade(cpy.mSigningGrade),
	mExecutionGrade(cpy.mExecutionGrade),
	mSigned(cpy.mSigned) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &rhs) {
	mName = rhs.mName;
	mSigningGrade = rhs.mSigningGrade;
	mExecutionGrade = rhs.mExecutionGrade;
	mSigned = rhs.mSigned;

	return *this;
}

void Form::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() > mSigningGrade) {
		throw GradeTooLowException();
	}
	mSigned = true;
}

void Form::execute(const Bureaucrat &executor) const {
	if (!mSigned) {
		throw FormNotSignedException();
	}

	if (executor.getGrade() > mExecutionGrade) {
		throw GradeTooLowException();
	}
	executeImpl();
}

const std::string &Form::getName() const {
	return mName;
}

bool Form::isSigned() const {
	return mSigned;
}

int Form::getSigningGrade() const {
	return mSigningGrade;
}

int Form::getExecutionGrade() const {
	return mExecutionGrade;
}


Form::GradeTooHighException::~GradeTooHighException() throw() {
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
}

Form::FormNotSignedException::~FormNotSignedException() throw() {
}

const char* Form::FormNotSignedException::what() const throw() {
	return "form not signed";
}

std::ostream &operator<<(std::ostream &lhs, const Form &rhs) {
	lhs	<< "Form " << rhs.getName() << ' '
				<< '(' << (rhs.isSigned() ? "signed" : "not signed") << ')'
				<< " requires a grade of " << rhs.getSigningGrade() << " to be signed, and a grade of " << rhs.getExecutionGrade() << " to be executed.";
	return lhs;
}
