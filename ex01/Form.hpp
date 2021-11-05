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
	// Form(std::string name, int signingGrade, int executionGrade);
	Form(const std::string &name, int signingGrade, int executionGrade);
	Form(const Form &cpy);
	~Form();

	Form &operator=(const Form &rhs);

	void beSigned(const Bureaucrat &signer);

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
};

std::ostream &operator<<(std::ostream &lhs, const Form &rhs);
