#pragma once

#include <string>

#include <ostream>

#include "Forward.hpp"

#include "GradeTooHighExceptionBase.hpp"
#include "GradeTooLowExceptionBase.hpp"

class Form {
private:
	std::string mName;
	int mSigningGrade;
	int mExecutionGrade;
	bool mSigned;

public:
	Form(const std::string &name, int signingGrade, int executionGrade);
	Form(const Form &cpy);
	virtual ~Form();

	Form &operator=(const Form &rhs);

	void beSigned(const Bureaucrat &signer);

	void execute(const Bureaucrat &executor) const;

protected:
	virtual void executeImpl() const = 0;

public:
	const std::string &getName() const;
	bool isSigned() const;
	int getSigningGrade() const;
	int getExecutionGrade() const;


	struct GradeTooHighException: public GradeTooHighExceptionBase {
		virtual ~GradeTooHighException() throw();
	};

	struct GradeTooLowException: public GradeTooLowExceptionBase {
		virtual ~GradeTooLowException() throw();
	};

	struct FormNotSignedException: public std::exception {
		virtual ~FormNotSignedException() throw();

		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &lhs, const Form &rhs);
