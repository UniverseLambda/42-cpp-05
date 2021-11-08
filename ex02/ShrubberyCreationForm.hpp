#pragma once

#include "Form.hpp"
#include <string>

class ShrubberyCreationForm: public Form {
private:
	std::string mTarget;

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

protected:
	virtual void executeImpl() const;

public:
	const std::string &getTarget() const;
};
