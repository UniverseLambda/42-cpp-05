#include "GradeTooLowExceptionBase.hpp"

GradeTooLowExceptionBase::~GradeTooLowExceptionBase() throw() {
}

const char* GradeTooLowExceptionBase::what() const throw() {
	return "grade is too low";
}
