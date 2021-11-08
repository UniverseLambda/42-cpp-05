#pragma once

#include <exception>

struct GradeTooHighExceptionBase: public std::exception {
	virtual ~GradeTooHighExceptionBase() throw();

	virtual const char* what() const throw();
};
