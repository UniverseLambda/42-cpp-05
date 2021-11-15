#pragma once

#include "Form.hpp"
#include <string>

typedef Form *(*formMaker)(std::string target);

/**
 * Should have been an aggregate class. Buuuuut... "If any non-interface class is not in orthodox canonical form, do not grade this exercise."
 * So f off.
 */
struct FormCreationData {
	std::string formName;
	formMaker maker;

	FormCreationData();
	FormCreationData(const FormCreationData &cpy);
	~FormCreationData();

	FormCreationData &operator=(const FormCreationData &rhs);
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
