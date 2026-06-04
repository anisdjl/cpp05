#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src) {
    std::cout << "Intern assignment operator called" << std::endl;
    if (this != &src) {
       
    }
    return *this;
}
