#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Joueur {
private:
    string nom;
    int score;

public:
    Joueur(string nn, int sc) : nom(nn), score(sc) {}

    string getNom() const { return nom; }
    int getScore() const { return score; }
    void setScore(int score) { this->score = score; }
};

class Terrain {
private:
    string nom;
    int capacite;
    int placesDisponibles;
    

public:
    Terrain(string nm, int cap) : nom(nm), capacite(cap), placesDisponibles(cap) {}

    string getNom() const { return nom; }
    int getCapacite() const { return capacite; }
     int getPlacesDisponibles() const { return placesDisponibles; }

     void reserverPlace() {
        if (placesDisponibles > 0) {
            placesDisponibles--;
        } else {
            cout << "Désolé, aucune place disponible sur le terrain " << nom << endl;
        }
    }
    

    
};

class Partie {
private:
    Joueur* joueur1;
    Joueur* joueur2;
    Terrain* terrain;
    string phase;
    int scoreJoueur1;
    int scoreJoueur2;

public:
    Partie(Joueur* joueur1, Joueur* joueur2, Terrain* terrain, const string& phase)
        : joueur1(joueur1), joueur2(joueur2), terrain(terrain), phase(phase), scoreJoueur1(0), scoreJoueur2(0) {}
    void jouer() {
        scoreJoueur1 = rand() % 7;
        scoreJoueur2 = rand() % 7;
        cout << "Partie entre " << joueur1->getNom() << " et " << joueur2->getNom()
             << " sur " << terrain->getNom() << " (Phase : " << phase << ")\n";
        cout << "Score : " << joueur1->getNom() << " " << scoreJoueur1 << " - " << joueur2->getNom() << " " << scoreJoueur2 << "\n";
    }
    Joueur* getJoueur1() const { return joueur1; }
    Joueur* getJoueur2() const { return joueur2; }
    int getScoreJoueur1() const { return scoreJoueur1; }
    int getScoreJoueur2() const { return scoreJoueur2; }
    Joueur* getGagnant() const {
        if (scoreJoueur1 > scoreJoueur2) {
            return joueur1;
        } else if (scoreJoueur2 > scoreJoueur1) {
            return joueur2;
        }
        return nullptr;
    }
};

class Championnat {
private:
    vector<Joueur> joueurs;
    vector<Terrain> terrains;
    vector<Partie> parties;

public:
    void ajouterJoueur(const Joueur& joueur) {
        joueurs.push_back(joueur);
        cout << "Joueur " << joueur.getNom() << " ajouté.\n";
    }

    void supprimerJoueur(const string& nom) {
        for (int i = 0; i < joueurs.size(); ++i) {
            if (joueurs[i].getNom() == nom) {
                joueurs.erase(joueurs.begin() + i);
                cout << "Joueur " << nom << " supprimer.\n";
            }
        }
    }

    Joueur rechercherJoueur(const string& nom) {
       for (int i = 0; i < joueurs.size(); ++i) {
            if (joueurs[i].getNom() == nom) {
                return joueurs[i];
            }
        }
        return Joueur("existe pas", -1);
    }

    void ajouterTerrain(const Terrain& terrain) {
        terrains.push_back(terrain);
        cout << "Terrain " << terrain.getNom() << " ajouté.\n";
    }

    void supprimerTerrain(const string& nom) {
        for (int i = 0; i < terrains.size(); ++i) {
            if (terrains[i].getNom() == nom) {
                terrains.erase(terrains.begin() + i);
                cout << "Terrain " << nom << " supprimer.\n";
            }
        }
    }

    Terrain rechercherTerrain(const string& nom) {
    for (int i = 0; i < terrains.size(); ++i) {
        if (terrains[i].getNom() == nom) {
            return terrains[i];
        }
    }
    // Si aucun terrain correspondant n'est trouvé, retourner un terrain fictif avec un nom indiquant qu'il n'existe pas
    return Terrain("Terrain inexistant", -1);
}


    void planifierParties(const string& phase) {
        if (joueurs.size() < 2 || terrains.empty()) {
            cout << "Pas assez de joueurs ou de terrains pour planifier des parties.\n";
            return;
        }
        random_shuffle(joueurs.begin(), joueurs.end());
        for (int i = 0; i < joueurs.size() - 1; i += 2) {
            Joueur* joueur1 = &joueurs[i];
            Joueur* joueur2 = &joueurs[i + 1];
            Terrain* terrain = &terrains[0];
            Partie partie(joueur1, joueur2, terrain, phase);
            partie.jouer();
            parties.push_back(partie);
        }
    }

    void selectionnerJoueursPhaseSuivante() {
    vector<Joueur> gagnants;
    for (int i = 0; i < parties.size(); ++i) {
        Joueur* gagnant = parties[i].getGagnant();
        if (gagnant) {
            gagnants.push_back(*gagnant);
        }
    }
    for (int i = 0; i < parties.size(); ++i) {
        if (parties[i].getGagnant() == nullptr) {
            gagnants.push_back(*parties[i].getJoueur1());
            gagnants.push_back(*parties[i].getJoueur2());
        }
    }
    joueurs = gagnants;
    parties.clear();
}


    void reserverTicket(const string& nomSupporter, const string& nomTerrain,const string& phase) {
    // Prix de base du ticket
    int prixBase = 50;

    // Coefficient de modification du prix en fonction de l'avancement dans la compétition
    double coefficientPrix = 1.0;

    // Calcul du coefficient en fonction de l'avancement dans la compétition
    if (phase == "Éliminatoires") {
        coefficientPrix = 0.8; // Exemple: réduction de 20%
    } else if (phase == "Huitièmes") {
        coefficientPrix = 0.85; // Exemple: réduction de 15%
    } else if (phase == "Quarts") {
        coefficientPrix = 0.9; // Exemple: réduction de 10%
    } else if (phase == "Demi-finales") {
        coefficientPrix = 0.95; // Exemple: réduction de 5%
    } else if (phase == "Finale") {
        coefficientPrix = 0.98; // Exemple: réduction de 2%
    }

    // Recherche du terrain par son nom
    for (int i = 0; i < terrains.size(); ++i) {
        if (terrains[i].getNom() == nomTerrain) {
            // Calcul du prix du ticket en fonction du coefficient
            int prixTicket = static_cast<int>(prixBase * coefficientPrix);

            // Réserver une place sur le terrain
            terrains[i].reserverPlace();

            // Affichage du message avec le nom du supporter et le prix du ticket
            cout << "Ticket réservé pour le supporter " << nomSupporter << " sur le terrain " << nomTerrain
                 << " pour un prix de " << prixTicket << " euros." << endl;
            return;
        }
    }
    cout << "Terrain non trouvé : " << nomTerrain << endl;
}




    void afficherResultats() {
    cout << "Résultats des parties :\n";
    for (int i = 0; i < parties.size(); ++i) {
        Joueur* gagnant = parties[i].getGagnant();
        if (gagnant) {
            cout << "Gagnant : " << gagnant->getNom() << "\n";
        } else {
            cout << "La partie s'est terminée par une égalité.\n";
        }
    }
}
    
    void organiserTournoi() {
    vector<string> phases = {"Éliminatoires", "Huitièmes", "Quarts", "Demi-finales", "Finale"};
    for (int i = 0; i < phases.size(); ++i) {
        string phase = phases[i];
        cout << "\nPhase : " << phase << "\n";
        cout << "Joueurs actuels avant la phase " << phase << " :\n";
        for (int j = 0; j < joueurs.size(); ++j) {
            cout << joueurs[j].getNom() << "\n";
        }
        planifierParties(phase);
        afficherResultats();
        if (phase != "Finale") {
            selectionnerJoueursPhaseSuivante();
        }
        cout << "Joueurs actuels après la phase " << phase << " :\n";
        for (int j = 0; j < joueurs.size(); ++j) {
            cout << joueurs[j].getNom() << "\n";
        }
    }
    if (joueurs.size() == 2) {
        cout << "\nFinale :\n";
        Partie finale(&joueurs[0], &joueurs[1], &terrains[0], "Finale");
        finale.jouer();
        Joueur* gagnantFinale = finale.getGagnant();
        cout << "Gagnant de la finale : " << (gagnantFinale ? gagnantFinale->getNom() : "Égalité") << "\n";
    } else if (joueurs.size() == 3) {
        cout << "\nMatch pour la troisième place :\n";
        Partie matchTroisiemePlace(&joueurs[1], &joueurs[2], &terrains[0], "Match pour la troisième place");
        matchTroisiemePlace.jouer();
        Joueur* gagnantTroisiemePlace = matchTroisiemePlace.getGagnant();
        cout << "Gagnant du match pour la troisième place : " << (gagnantTroisiemePlace ? gagnantTroisiemePlace->getNom() : "Égalité") << "\n";
        cout << "\nFinale :\n";
        Partie finale(&joueurs[0], &joueurs[2], &terrains[0], "Finale");
        finale.jouer();
        Joueur* gagnantFinale = finale.getGagnant();
        cout << "Gagnant de la finale : " << (gagnantFinale ? gagnantFinale->getNom() : "Égalité") << "\n";
    }
    if (joueurs.size() == 1) {
        cout << "\nLe vainqueur du tournoi est : " << joueurs[0].getNom() << "\n";
    }
}

};

int main() {
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    Championnat championnat;
    
    championnat.ajouterJoueur(Joueur("Novak Djokovic", 0));
    championnat.ajouterJoueur(Joueur("Jannik Sinner", 0));
    championnat.ajouterJoueur(Joueur("Carlos Alcaraz", 0));
    championnat.ajouterJoueur(Joueur("Daniil Medvedev",0));
    championnat.ajouterJoueur(Joueur("Alexander Zverev",0));
    championnat.ajouterJoueur(Joueur("Casper Ruud",0));
    championnat.ajouterJoueur(Joueur("Stefanos Tsitsipas",0));
    championnat.ajouterJoueur(Joueur("Andrey Rublev",0));
    championnat.ajouterJoueur(Joueur("Hubert Hurkacz",0));
    championnat.ajouterJoueur(Joueur("Grigor Dimitrov",0));
    championnat.ajouterJoueur(Joueur("Alex de Minaur",0));
    championnat.ajouterJoueur(Joueur("Holger Rune",0));
    championnat.ajouterJoueur(Joueur("Taylor Fritz",0));
    championnat.ajouterJoueur(Joueur("Ugo Humbert",0));
    championnat.ajouterJoueur(Joueur("Ben Shelton",0));
    championnat.ajouterJoueur(Joueur("Karen Khachanov",0));
    championnat.ajouterJoueur(Joueur("Alexander Bublik",0));
    championnat.ajouterJoueur(Joueur("Sebastian Baez",0));
    championnat.ajouterJoueur(Joueur("Adrian Mannarino",0));
    championnat.ajouterJoueur(Joueur("Frances Tiafoe",0));
    championnat.ajouterJoueur(Joueur("Francisco Cerundolo",0));
    championnat.ajouterJoueur(Joueur("Nicolas Jarry",0));
    championnat.ajouterJoueur(Joueur("Jan-Lennard Struff",0));
    championnat.ajouterJoueur(Joueur("Tallon Griekspoor",0));
    championnat.ajouterJoueur(Joueur("Sebastian Korda",0));
    championnat.ajouterJoueur(Joueur("Tomas Martin Etcheverry",0));
    championnat.ajouterJoueur(Joueur("Alejandro Davidovich Fokina",0));
    championnat.ajouterJoueur(Joueur("Lorenzo Musetti",0));
    championnat.ajouterJoueur(Joueur("Cameron Norrie",0));
    championnat.ajouterJoueur(Joueur("Jiri Lehecka",0));
    championnat.ajouterJoueur(Joueur("Arthur Fils",0));
    
    
    
    
    championnat.ajouterTerrain(Terrain("Arthur Ashe Stadium", 23771));
    championnat.ajouterTerrain(Terrain("Stade Roland Garros", 15225));
    
    //championnat.supprimerTerrain("Stade Roland Garros");
    
    championnat.reserverTicket("Anas Krir", "Arthur Ashe Stadium","Éliminatoires");
    championnat.reserverTicket("Adam El youri", "Stade Roland Garros","Finale");
    
    championnat.organiserTournoi();
    
    return 0;
}

