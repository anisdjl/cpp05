#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class Intern {
    private:

    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);
};

#endif
