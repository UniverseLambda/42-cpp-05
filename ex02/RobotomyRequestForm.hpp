#pragma once

#include "Form.hpp"
#include <string>

class RobotomyRequestForm: public Form {
private:
	std::string mTarget;

public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &cpy);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

protected:
	virtual void executeImpl() const;

public:
	const std::string &getTarget() const;
};
