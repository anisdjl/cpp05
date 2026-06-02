#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    std::cout << "--- TEST 1 : Le monde parfait (Tout fonctionne) ---" << std::endl;
    try 
    {
        Bureaucrat boss("Hermes", 1);
        Form       contrat("Contrat de Travail", 25, 50);

        std::cout << contrat << std::endl; // Test de l'opérateur << du Form
        boss.signForm(contrat);            // Doit afficher : Hermes signed Contrat de Travail
        std::cout << contrat << std::endl; // Doit afficher que le statut est "signed: true"
    }
    catch (const std::exception& e) 
    {
        std::cout << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2 : Le stagiaire sans pouvoir ---" << std::endl;
    try 
    {
        Bureaucrat stagiaire("Arthur", 150);
        Form       secretDefens("Plan de l'Étoile de la Mort", 1, 1);

        std::cout << secretDefens << std::endl;
        stagiaire.signForm(secretDefens); // Doit afficher : Arthur couldn't sign... because Grade too low
    }
    catch (const std::exception& e) 
    {
        std::cout << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3 : Tentative de création d'un Formulaire Illégal (Trop Haut) ---" << std::endl;
    try 
    {
        Form triche("Formulaire Magique", 0, 50); // Grade 0 n'existe pas !
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception capturée (Succès) : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4 : Tentative de création d'un Formulaire Illégal (Trop Bas) ---" << std::endl;
    try 
    {
        Form poubelle("Formulaire Inutile", 50, 151); // Grade 151 n'existe pas !
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception capturée (Succès) : " << e.what() << std::endl;
    }

    return 0;
}