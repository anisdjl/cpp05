#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class	AForm;
class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		int			getGrade(void) const;
		std::string	getName(void) const;
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &bureau);
		Bureaucrat &operator=(const Bureaucrat &bureau);
		void 		incrementGrade(void);
		void 		decrementGrade(void);
		void		executeForm(AForm const & form) const;

		class GradeTooHighException : std::exception
		{
			private:
				std::string	_error;
			public:
				GradeTooHighException(const std::string &name, int grade);
				~GradeTooHighException() throw();
				const char *what() const throw();
		};

		class GradeTooLowException
		{
			private:
				std::string _error;
			public:
				GradeTooLowException(const std::string &name, int garde);
				~GradeTooLowException() throw();
				const char *what() const throw();
		};
		
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau);

#endif