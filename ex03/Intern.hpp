#pragma once

#include "Form.hpp"
#include <string>

class Intern {
private:


public:
	Intern();
	Intern(const Intern &cpy);
	~Intern();

	Intern &operator=(const Intern &rhs);

	Form *makeForm(const std::string &formName, const std::string &target) const;
};
