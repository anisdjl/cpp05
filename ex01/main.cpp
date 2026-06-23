#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    std::cout << "--- TEST 1 : ---" << std::endl;
    try 
    {
        Bureaucrat boss("Hermes", 1);
        Form       contrat("Contrat de Travail", 25, 50);

        std::cout << contrat << std::endl;
        boss.signForm(contrat);
        std::cout << contrat << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2 : ---" << std::endl;
    try 
    {
        Bureaucrat stagiaire("Arthur", 150);
        Form       secretDefens("Plan de l'Étoile de la Mort", 1, 1);

        std::cout << secretDefens << std::endl;
        stagiaire.signForm(secretDefens);
    }
    catch (const std::exception& e) 
    {
        std::cout << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3 :  ---" << std::endl;
    try 
    {
        Form triche("Formulaire Magique", 0, 50);
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception capturée (Succès) : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4 : ---" << std::endl;
    try 
    {
        Form poubelle("Formulaire Inutile", 50, 151);
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception capturée (Succès) : " << e.what() << std::endl;
    }

    return 0;
}