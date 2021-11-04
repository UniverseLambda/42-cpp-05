#pragma once

#include <string>
#include <exception>

#include <ostream>

class Bureaucrat {
private:
	std::string mName;
	int mGrade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &cpy);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();


	struct GradeTooHighException: public std::exception {
		GradeTooHighException() throw();
		virtual ~GradeTooHighException() throw();

		virtual const char* what() const throw();
	};

	struct GradeTooLowException: public std::exception {
		GradeTooLowException() throw();
		virtual ~GradeTooLowException() throw();

		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs);
