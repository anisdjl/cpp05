#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;
		int					gradeCheck(int grade);
	public :
		Form(std::string name, int gradetosign, int gradetoexec);
		~Form();
		Form(const Form &form);
		Form	&operator=(const Form &form);
	
		std::string	getName(void) const;
		int			getExecgrade(void) const;
		int			getSigngrade(void) const;
		bool		formState(void) const;
		void		beSigned(const Bureaucrat &bureau);
		class GradeTooHighException : std::exception
		{
			private:
				std::string	_error;
			public:
				GradeTooHighException(int grade);
				~GradeTooHighException(void) throw();
				const char *what() const throw();
		};

		class GradeTooLowException : std::exception
		{
			private:
				std::string	_error;
			public:
				GradeTooLowException(int grade);
				~GradeTooLowException(void) throw();
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif