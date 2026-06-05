#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;
class Intern {
    private:
		AForm *_makeRobotomy(std::string target);
		AForm *_makeShrubbery(std::string target);
		AForm *_makePresidential(std::string target);

    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);
		AForm *makeForm(std::string name, std::string target);
};

#endif
