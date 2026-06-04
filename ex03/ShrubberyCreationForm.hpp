#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
    private:
		std::string	_target;
    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		void	execute(Bureaucrat const & executor) const;
};

#endif
