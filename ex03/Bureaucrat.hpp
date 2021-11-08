#pragma once

#include <string>

#include <ostream>

#include "Forward.hpp"

#include "GradeTooHighExceptionBase.hpp"
#include "GradeTooLowExceptionBase.hpp"

class Bureaucrat {
private:
	std::string mName;
	int mGrade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &cpy);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	bool signForm(Form &form) const;
	bool executeForm (const Form &form) const;

	void incrementGrade();
	void decrementGrade();

	const std::string &getName() const;
	int getGrade() const;

	struct GradeTooHighException: public GradeTooHighExceptionBase {
		virtual ~GradeTooHighException() throw();
	};

	struct GradeTooLowException: public GradeTooLowExceptionBase {
		virtual ~GradeTooLowException() throw();
	};
};

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs);
