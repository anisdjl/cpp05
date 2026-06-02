#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm {
    private:

    public:
        PresidentialPardonForm(std::string name);                             // Constructeur par défaut
        PresidentialPardonForm(const PresidentialPardonForm &src);            // Constructeur de copie
        ~PresidentialPardonForm();                            // Destructeur
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src); // Opérateur d'assignation
};

#endif
