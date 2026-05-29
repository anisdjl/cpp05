#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Form
{
	private :
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_signed;
	public :
		Form(std::string name, int gradetosign, int gradetoexec);
		~Form();
		Form(const Form &form);
		Form	&operator=(const Form &form);
		std::string	getName(void);
		int			getExecgrade(void);
		int			getSigngrade(void);
		bool		formState(void);

		class GradeTooHighException : std::exception
		{

		};

		class GradeTooLowException : std::exception
		{

		};
};

#endif