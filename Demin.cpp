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
#include <ctime>


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

// Fonction pour générer des bombes de manière aléatoire
void placerBombes(std::vector<std::vector<char>>& grille, int nbrBombes) 
{
    srand(static_cast<unsigned>(time(0))); // Initialiser le générateur de nombres aléatoires
    int lignes = grille.size();
    int colonnes = grille[0].size();
    int bombesPlacees = 0;

    while (bombesPlacees < nbrBombes) 
    {
        int r = rand() % lignes;
        int c = rand() % colonnes;

        // Vérifie si la case est déjà occupée par une bombe
        if (grille[r][c] != '*') 
        {
            grille[r][c] = '*'; 
            bombesPlacees++;
        }
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
        // Initialise la grille
        std::vector<std::vector<char>> grille(lignes, std::vector<char>(colonnes, ' '));
        placerBombes(grille, nbrbombe); // Place les bombes
        afficherGrille(grille); // Affiche la grille avec les bombes




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

