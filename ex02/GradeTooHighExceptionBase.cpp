#include "GradeTooHighExceptionBase.hpp"

GradeTooHighExceptionBase::~GradeTooHighExceptionBase() throw() {
}

const char* GradeTooHighExceptionBase::what() const throw() {
	return "grade is too high";
}
