// Démin.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.



#include <iostream>
#include <string>
#include <vector>


// Fonction pour afficher la grille
void afficherGrille(const std::vector < std::vector <char>>& grille)
{

    for (char colonne = 'A'; colonne < 'A' + static_cast<char>(grille[0].size()); ++colonne)
    {
        std::cout << "   "<< colonne << ""; // Affiche les colonnes

    }
    std::cout << std::endl;

    for (size_t i = 0; i < grille.size(); ++i) // Affichage des lignes
    {
        std::cout << (i + 1); 

        for (size_t j = 0; j < grille[i].size(); ++j)
        {
            std::cout << grille[i][j] << "[-]" ; //afiche les cases
        }
        std::cout << std::endl;
    }

  
}
          
void naviguer (std::vector<std::vector<char>>& grille)
{
    int x, y;
    while (true)
    {
        std::cout << "Entrez les coordonnées (ligne colonne) ou 'stop' pour arrêter : ";
         std::cin >> x;
         if (std::cin.fail()) 
        { // Vérifier si l'entrée est valide
            std::string stop;
            std::cin.clear(); // Réinitialiser le flux d'entrée
            std::cin >> stop;
            if (stop == "stop") {
                break; // Sortir de la boucle si l'utilisateur veut arrêter
            }

            if (x < 1 || x > grille.size() || y < 1 || y > grille[0].size()) 
            {
                std::cout << "Coordonnées invalides, veuillez réessayer.\n";
                continue; 
            }

        int ligne = x - 1;
        int colonne = y - 1;

        // Révéler la case
        if (grille[ligne][colonne] == '#') 
        { 
            grille[ligne][colonne] = '#'; // Remplace par un '#'
        }

        }
        afficherGrille(grille);
    }
}


int main()
{
    std::cout << "Et si on faisez un demineur ? (oui ou non)\n";
    std::string reponse;
    std::cin >> reponse;
    std::string grille;
    std::string diff;


    // Lancement du démineur 
    if (reponse == "oui")
    { 
        std::cout << " C'est partit, bon jeux!! \n"; 
        std::cout << std::endl;
        std::cout << grille;

        //Générer la grille 
        int lignes, colonnes;

        //Demander à l'utilisateur la taille de la grille
        std::cout << "Quelle est la taille des lignes ? : ";
        std::cin >> lignes;
        std::cout << "Quelle est la taille des colonnes ? : ";
        std::cin >> colonnes;

        //Générer la difficulté
        std::cout << " Quel est la difficulte ? | facile | moyen | difficile | : ";
        
        std::cin >> diff;
        int nbrbombe = 0;

        
           if (diff == "facile")
            {
                nbrbombe = static_cast <int> ((colonnes * lignes) * 0.1);
            }
            else if (diff == "moyen")
            {
                nbrbombe = (static_cast <int> (colonnes * lignes)) * 0.2;
            }
            else if (diff == "difficile")
            {
                nbrbombe = static_cast <int> ((colonnes * lignes) * 0.3);
            }
            else
            {
                std::cout << "Difficulté inconnue, veuillez choisir entre 'facile', 'moyen' ou 'difficile'.\n";
                return 1;
            }
           std::cout << " Il y aura : " << nbrbombe << " bombes dans le demineur, good luck!!\n";
           
    
    // Initialise la grille
        std::vector<std::vector<char>> grille(lignes, std::vector<char>(colonnes, '#'));

        afficherGrille(grille); // Affiche la grille initiale

    // Lancer la navigation
        naviguer(grille);



    }
    
    else if (reponse == "non")
    { 
        std::cout << " A plus tard ;) !! \n";
    }
    else
    {
        std::cout << "erreur\n";
    }
    return 0;

  
}



// erreur pour une taille de colonne superieur à 26 et une ligne supérieur à 10

