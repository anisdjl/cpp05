#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string.h>

class Bureaucrat : public std::exception
{
	private:
		std::string	_name;
		int			_grade;
	public:
		int	getGrade(void);
		std::string	getName(void);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		void GradeTooHighException(void);
		void GradeTooLowException(void);
		void incrementGrade(void); // je sais pas si il faut que je fasse un overload de l'operateur +
		void decrementGrade(void); // pareil je ne sais pas si il faut faire un overload
		const char *what() const noexcept override;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau);

#endif