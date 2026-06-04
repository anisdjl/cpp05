#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private:
		std::string _target;

    public:
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		void	execute(Bureaucrat const & executor) const;
};

#endif
