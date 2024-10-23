
    // Démin.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
    //

#include <iostream>
#include <string>
#include <vector>
#include <ctime>


// Fonction pour afficher la grille
void afficherGrille(const std::vector < std::vector <char>>&grille, const std::vector<std::vector<bool>>&decouverte, const std::vector<std::vector<bool>>& drapeaux, bool gameOver = false)
{
    for (char colonne = 'A'; colonne < 'A' + static_cast<char>(grille[0].size()); ++colonne)
    {
        std::cout << "   " << colonne;
    }
    std::cout << std::endl; 

    for (size_t i = 0; i < grille.size(); ++i)
    {
        std::cout << (i + 1);
        for (size_t j = 0; j < grille[i].size(); ++j)
        {
            if (decouverte[i][j] || gameOver)
            {
                std::cout << " [" << (grille[i][j] == '#' ? '#' : grille[i][j]) << "]"; 
            }
            else if (drapeaux[i][j])
            {
                std::cout << " [!]";
            }
            else
            {
                std::cout << " [-]"; // Cacher les cases
            }
        }
        std::cout << std::endl;
    }
}

// Fonction pour effacer l'écran
void effacerEcran()
{
    system("clear");//sous UNIX
    system("cls"); //sous windows
}

// Fonction pour les drapeaux
void placerDrapeau(std::vector<std::vector<bool>>& drapeaux, int ligne, int colonne)
{
    if (ligne >= 0 && ligne < drapeaux.size() && colonne >= 0 && colonne < drapeaux[0].size())
    {
        drapeaux[ligne][colonne] = !drapeaux[ligne][colonne]; // Bascule le drapeau
    }
}

// Fonction pour gérer la victoire du jeux
bool verifierVictoire(const std::vector<std::vector<char>>&grille, const std::vector<std::vector<bool>>&decouverte)
{
    for (size_t i = 0; i < grille.size(); ++i)
    {
        for (size_t j = 0; j < grille[i].size(); ++j)
        {
            // Si une case non-bombe n'est pas découverte, le jeu continue
            if (grille[i][j] != '#' && !decouverte[i][j])
            {
                return false;
            }
        }
    }
    return true; // Toutes les cases non-bombes ont été découvertes
}


// Fonction pour découvrir une case
void decouvrirCase(std::vector<std::vector<bool>>&decouverte, std::vector<std::vector<bool>>& drapeaux, int ligne, int colonne)
{
    if (!drapeaux[ligne][colonne]) 
    {

    if (ligne >= 0 && ligne < decouverte.size() && colonne >= 0 && colonne < decouverte[0].size())
    {
        decouverte[ligne][colonne] = true;
    }
    }
}

// Fonction pour générer des bombes de manière aléatoire
void placerBombes(std::vector<std::vector<char>>&grille, int nbrBombes)
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
        if (grille[r][c] != '#')
        {
            grille[r][c] = '#';
            bombesPlacees++;
            for (int i = -1; i <= 1; ++i)
            {
                for (int j = -1; j <= 1; ++j)
                {
                    if (r + i >= 0 && r + i < lignes && c + j >= 0 && c + j < colonnes)
                    {
                        if (grille[r + i][c + j] != '#') 
                        {
                            if (grille[r + i][c + j] == ' ')
                                grille[r + i][c + j] = '1';
                            else if (grille[r + i][c + j] >= '1' && grille[r + i][c + j] <= '8')
                                grille[r + i][c + j]++;
                        }
                    }
                }
            }
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
        int lignes, colonnes;

        //Demander à l'utilisateur la taille de la grille
        std::cout << "Quelle est la taille des lignes ? : ";
        std::cin >> lignes;
        std::cout << "Quelle est la taille des colonnes ? : ";
        std::cin >> colonnes;
        std::vector<std::vector<bool>> drapeaux(lignes, std::vector<bool>(colonnes, false));

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
            nbrbombe = static_cast <int> ((colonnes * lignes) * 0.2);
        }
        else if (diff == "difficile")
        {
            nbrbombe = static_cast <int> ((colonnes * lignes) * 0.3);
        }
        else
        {
            std::cout << "Difficulte inconnue, veuillez choisir entre 'facile', 'moyen' ou 'difficile'.\n";
            return 1;
        }

        // afficher une bombe même pour les niveaux de difficultés bas et petite grille
        if (nbrbombe < 1)
        {
            nbrbombe = 1;
        }

        std::cout << " Il y aura : " << nbrbombe << " bombes dans le demineur, good luck!!\n";
        std::cout << std::endl;


        // Initialise toutes les grilles, découverte et drapeaux
        std::vector<std::vector<char>> grille(lignes, std::vector<char>(colonnes, ' '));
        std::vector<std::vector<bool>> decouverte(lignes, std::vector<bool>(colonnes, false));
       
        placerBombes(grille, nbrbombe);
        

        while (true)
        {
            effacerEcran(); // Efface l'écran
            std::cout << "Il y a " << nbrbombe << " bombes\n";
            afficherGrille(grille, decouverte, drapeaux); // Affiche la grille
            std::cout << std::endl;
            std::cout << " 'quitter'\n" << "'dig'\n" << "'flag'\n" << "'restart' \n";
            std::string Choix;
            std::cout << "Entrez votre choix : ";
            std::cin >> Choix;
            if (Choix == "quitter")
            {
                effacerEcran();
                std::cout << "Vous avez quitte le jeu. A bientot!\n";
                break;
            }
            else if (Choix == "restart")
            {
                effacerEcran();
                break;

            }
            else if (Choix == "dig" || Choix == "flag")
            {
                char col;
                int ligne;
                std::cout << "Entrez la ligne et la colonne a decouvrir (ex: A1) : ";
                std::cin >> col >> ligne;
                int colonne = col - 'A';
                effacerEcran();
            

            if (colonne < 0 || colonne >= colonnes || ligne <= 0 || ligne > lignes) //vérifications coordonnés
            {
                std::cout << "Coordonnees invalides. Veuillez reessayer.\n";
                continue;
            }
        
                if (Choix == "dig")
                {
                    if (!drapeaux[ligne - 1][colonne])
                    {
                        decouvrirCase(decouverte, drapeaux, ligne - 1, colonne);
                        if (grille[ligne - 1][colonne] == '#')
                        {
                            effacerEcran(); 
                            std::cout << "BOOM!!!!------------------------------GAME OVER------------------------------\n";
                            std::cout << std::endl;
                            afficherGrille(grille, decouverte, drapeaux, true);
                            std::cout << std::endl;
                            break;
                        }
                    }
                }
                if (Choix == "flag")
                {
                    placerDrapeau(drapeaux, ligne - 1, colonne);
                }
            }
            
            
                // Victoire
                if (verifierVictoire(grille, decouverte))
                {
                    effacerEcran();
                    std::cout << "Felicitation!!!!------------------------------VICTOIRE------------------------------\n";
                    afficherGrille(grille, decouverte, drapeaux, true);
                    std::cout << std::endl;
                    break;
                }

        }

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


//erreur flag si click sur bombe
// restart
// erreur pour une taille de colonne superieur à 26 (créer une boucle incréménte ) et une ligne supérieur à 10 (créer une boucle ou < 9 rajouter deux espaces lignes et  un espace colonne)
// erreur coordoné invalide non affiche en ca de coordonées dépassant le tableau