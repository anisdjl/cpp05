#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(NULL));


	try
	{
		Bureaucrat	Loulou("Loulou", 150);
		ShrubberyCreationForm form_1("Anis");
		PresidentialPardonForm form_2("Marwen");
		RobotomyRequestForm Form_3("Manel");
		
		Loulou.signForm(form_1);
		Loulou.executeForm(form_1);
		Loulou.executeForm(form_2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}

// // Initialisation du seed pour le 50% de chance de la robotomie
//     std::srand(std::time(NULL));

//     std::cout << "==========================================" << std::endl;
//     std::cout << "    TESTS DU MODULE 05 - EXERCICE 02      " << std::endl;
//     std::cout << "==========================================" << std::endl;

//     // 1. Création des bureaucrates
//     Bureaucrat boss("Hermes (Le Boss)", 1);
//     Bureaucrat assistant("Bob (L'Assistant)", 45);
//     Bureaucrat stagiaire("Arthur (Le Stagiaire)", 150);

//     std::cout << "\n--- Bureaucrates créés : ---" << std::endl;
//     std::cout << boss << std::endl;
//     std::cout << assistant << std::endl;
//     std::cout << stagiaire << std::endl;

//     // 2. Création des formulaires via des pointeurs de la classe mère (Polymorphisme)
//     std::cout << "\n--- Création des formulaires (via AForm*) : ---" << std::endl;
//     AForm* shrub = new ShrubberyCreationForm("jardin");
//     AForm* robot = new RobotomyRequestForm("Bender");
//     AForm* pardon = new PresidentialPardonForm("Marlos");

//     std::cout << *shrub << std::endl;
//     std::cout << *robot << std::endl;
//     std::cout << *pardon << std::endl;

//     // ==========================================
//     // TEST 1 : Exécution sans signature (Doit échouer)
//     // ==========================================
//     std::cout << "\n==========================================" << std::endl;
//     std::cout << "TEST 1 : Tentative d'exécution sans signature" << std::endl;
//     std::cout << "==========================================" << std::endl;
    
//     // Même le boss doit échouer car le formulaire n'est pas signé
//     boss.executeForm(*shrub); 

//     // ==========================================
//     // TEST 2 : Signature des formulaires
//     // ==========================================
//     std::cout << "\n==========================================" << std::endl;
//     std::cout << "TEST 2 : Phase de signature" << std::endl;
//     std::cout << "==========================================" << std::endl;
    
//     // Le stagiaire essaie de signer le Shrubbery (requis: 145, lui: 150) -> Échec
//     stagiaire.signForm(*shrub);
    
//     // L'assistant signe le Shrubbery (requis: 145) et le Robotomy (requis: 72) -> Succès
//     assistant.signForm(*shrub);
//     assistant.signForm(*robot);
    
//     // L'assistant essaie de signer le Presidential (requis: 25) -> Échec
//     assistant.signForm(*pardon);
    
//     // Le boss signe le Presidential -> Succès
//     boss.signForm(*pardon);

//     // ==========================================
//     // TEST 3 : Exécution avec grades insuffisants
//     // ==========================================
//     std::cout << "\n==========================================" << std::endl;
//     std::cout << "TEST 3 : Exécution avec grades insuffisants" << std::endl;
//     std::cout << "==========================================" << std::endl;
    
//     // Le stagiaire essaie d'exécuter le Shrubbery (requis: 137, lui: 150) -> Échec
//     stagiaire.executeForm(*shrub);
    
//     // L'assistant essaie d'exécuter le Robotomy (requis: 45, lui: 45) -> Succès pour le grade !
//     // L'assistant essaie d'exécuter le Presidential (requis: 5, lui: 45) -> Échec
//     assistant.executeForm(*pardon);

//     // ==========================================
//     // TEST 4 : Exécutions réussies (Le Boss nettoie tout)
//     // ==========================================
//     std::cout << "\n==========================================" << std::endl;
//     std::cout << "TEST 4 : Le Boss exécute tout" << std::endl;
//     std::cout << "==========================================" << std::endl;
    
//     std::cout << "\n[Execution Shrubbery] -> Devrait créer le fichier 'jardin_shrubbery'" << std::endl;
//     boss.executeForm(*shrub);

//     std::cout << "\n[Execution Robotomy] -> 50% de chance, bruits de perceuse requis :" << std::endl;
//     boss.executeForm(*robot);
//     // On le relance une deuxième fois pour voir l'alternance aléatoire du 50%
//     boss.executeForm(*robot);

//     std::cout << "\n[Execution Presidential] -> Devrait gracier Marlos :" << std::endl;
//     boss.executeForm(*pardon);

//     // ==========================================
//     // NETTOYAGE
//     // ==========================================
//     std::cout << "\n==========================================" << std::endl;
//     std::cout << "NETTOYAGE DES ALLOCATIONS" << std::endl;
//     std::cout << "==========================================" << std::endl;
    
//     // Si ton destructeur virtuel dans AForm est bon, aucun leak ici
//     delete shrub;
//     delete robot;
//     delete pardon;

//     return (0);