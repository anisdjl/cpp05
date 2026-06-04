#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("Presidential Pardon", 25, 5)
{
	_target = name;
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    (void)src; // on ne peut rien faire car les attributs sont const
    return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkExecGrade(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}
