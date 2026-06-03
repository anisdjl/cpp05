#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("Robotomy Request", 72, 45)
{
	_target = name;
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    (void)src;
    return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecGrade(executor);

	std::cout << "BRRRRRRRR, VSSSSSSSSS, BZZZZZZZZZZ\n";

	if (std::rand() % 2 == 0)
	{
		std::cout << _target << " has been robotomized successfully\n";
	}
	else
		std::cout << _target << "'s Robotomy failed\n";
}