#pragma once

template<typename _LowException, typename _HighException>
void checkGrade(int grade) {
	if (grade < 1)
		throw _HighException();
	else if (grade > 150)
		throw _LowException();
}
