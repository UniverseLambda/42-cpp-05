#pragma once

#include <exception>

struct GradeTooLowExceptionBase: public std::exception {
	virtual ~GradeTooLowExceptionBase() throw();

	virtual const char* what() const throw();
};
