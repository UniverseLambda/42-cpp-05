#include "ShrubberyCreationForm.hpp"

#include <iostream>

#include <string>
#include <fstream>

static const std::size_t cTreeCount = 3;
static const std::string cTrees[cTreeCount] =
{
	"                                                         .\n"
	"                                              .         ;\n"
	"                 .              .              ;%     ;;\n"
	"                   ,           ,                :;%  %;\n"
	"                    :         ;                   :;%;'     .,\n"
	"           ,.        %;     %;            ;        %;'    ,;\n"
	"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
	"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
	"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
	"                `%;.     ;%;     %;'         `;%%;.%;'\n"
	"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
	"                    `:%;.  :;bd%;          %;@%;'\n"
	"                      `@%:.  :;%.         ;@@%;'\n"
	"                        `@%.  `;@%.      ;@@%;\n"
	"                          `@%%. `@%%    ;@@%;\n"
	"                            ;@%. :@%%  %@@%;\n"
	"                              %@bd%%%bd%%:;\n"
	"                                #@%%%%%:;;\n"
	"                                %@@%%%::;\n"
	"                                %@@@%(o);  . '\n"
	"                                %@@@o%;:(.,'\n"
	"                            `.. %@@@o%::;\n"
	"                               `)@@@o%::;\n"
	"                                %@@(o)::;\n"
	"                               .%@@@@%::;\n"
	"                               ;%@@@@%::;.\n"
	"                              ;%@@@@%%:;;;.\n"
	"                          ...;%@@@@@%%:;;;;,..\n",
	"          &&& &&  & &&\n"
	"      && &\\/&\\|& ()|/ @, &&\n"
	"      &\\/(/&/&||/& /_/)_&/_&\n"
	"   &() &\\/&|()|/&\\/ '%\" & ()\n"
	"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
	"&&   && & &| &| /& & % ()& /&&\n"
	" ()&_---()&\\&\\|&&-&&--%---()~\n"
	"     &&     \\|||\n"
	"             |||\n"
	"             |||\n"
	"             |||\n"
	"       , -=-~  .-^- _\n",
	"  oxoxoo    ooxoo\n"
	" ooxoxo oo  oxoxooo\n"
	"oooo xxoxoo ooo ooox\n"
	"oxo o oxoxo  xoxxoxo\n"
	" oxo xooxoooo o ooo\n"
	"  ooo\\oo\\  /o/o\n"
	"       \\  \\/ /\n"
	"       |   /\n"
	"       |  |\n"
	"       | D|\n"
	"       |  |\n"
	"       |  |\n"
	"______/____\\____\n"
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	Form("ShrubberyCreationForm", 145, 137),
	mTarget(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy):
	Form(cpy),
	mTarget(cpy.mTarget) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	Form::operator=(rhs);

	mTarget = rhs.mTarget;

	return (*this);
}

void ShrubberyCreationForm::executeImpl() const {
	#ifdef __linux__
		std::fstream out(("./" + mTarget + "_shrubbery").data(), std::ios_base::out);
	#else
		std::fstream out("./" + mTarget + "_shrubbery", std::ios_base::out);
	#endif

	if (!out.is_open()) {
		std::cerr << "ShrubberyCreationForm::executeImpl: IO Error" << std::endl;
		return ;
	}

	for (std::size_t i = 0; i < cTreeCount; ++i) {
		out.write(cTrees[i].data(), cTrees[i].size());
	}
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return mTarget;
}
