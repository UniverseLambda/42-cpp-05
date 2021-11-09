#pragma once

#include "Form.hpp"
#include <string>

typedef Form *(*formMaker)(std::string target);

/**
 * Aggregate struct containing basic data to create forms from name
 */
struct FormCreationData {
	std::string formName;
	formMaker maker;
};

class Intern {
private:
	static const std::size_t kFCDCount = 3;
	FormCreationData mFCDs[kFCDCount];

public:
	Intern();
	Intern(const Intern &cpy);
	~Intern();

	Intern &operator=(const Intern &rhs);

	Form *makeForm(const std::string &formName, const std::string &target) const;
};
