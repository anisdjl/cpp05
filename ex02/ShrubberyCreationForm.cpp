#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("Shrubbery Creation", 145, 137)
{
	_target = name;
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    (void)src;
    return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->checkExecGrade(executor);
	std::string file_name = this->_target + "_shrubbery";
	std::ofstream outfile(file_name.c_str());

	outfile << 
	"    *\n"
	"   ***\n"
	"  *****\n"
	" *******\n"
	"*********\n"
	"   |||\n"
	"   |||\n";

	outfile.close();
}