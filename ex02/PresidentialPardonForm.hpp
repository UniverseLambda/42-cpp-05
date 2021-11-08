#pragma once

#include "Form.hpp"
#include <string>

class PresidentialPardonForm: public Form {
private:
	std::string mTarget;

public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &cpy);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

protected:
	virtual void executeImpl() const;

public:
	const std::string &getTarget() const;
};
