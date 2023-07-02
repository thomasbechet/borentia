#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Affichagetxt.h"
#include "windows.h"
#include <cstdlib>
#include <ctime>

using namespace std;
//TYPE//
enum position{Plaine,Jungle,Desert,Volcan};

struct arme
{
    string nom;
    int degats;
    double prix;
};
struct casque
{
    string nom;
    int defense;
    double prix;
};
struct plastron
{
    string nom;
    int defense;
    double prix;
};
struct potion
{
    string nom;
    int soin;
    double prix;
};
struct personnage
{
    string nom;
    int vie;
    int niveau;
    int xp;
    int killMonstre;
    position lieu;
    double argent;
};

struct monstre
{
    string nom;
    int vie;
    int degats;
    int chance;
};


void jeu(string &nom_joueur, position &lieu_joueur, int &xp_joueur, int &killMonstre_joueur, int &vie_joueur, double &argent_joueur, int &niveau_joueur, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3);
void nouveaujeu();
void effacerSave();
void chargementSave();
void sauvegarderSave(string nom, position lieu, int xp, int killMonstre, int vie, double argent, int niveau, arme Arme1, arme ArmeUse, casque CasqueUse, plastron PlastronUse, potion potion1, potion potion2, potion potion3);
void GUI(position lieu,string nom,int niveau,int xp,int nombreKill,double argent, int vie);
void echangeArme(arme &ArmeUse,arme &Arme1);
void Inventaire(double &argent,int &vie, arme &ArmeUse, arme &Arme1, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3);
void actualiserVie(int &vie);
void actualiserXp(int &xp, int &niveau);
void acheterArme(double &argent,arme &Arme,arme &ArmeUse,arme &Arme1);
void acheterPlastron(double &argent, plastron &Plastron, plastron &PlastronUse);
void acheterCasque(double &argent, casque &Casque, casque &CasqueUse);
void acheterPotion(double &argent, potion &Potion, potion &Potion1, potion &Potion2, potion &Potion3);
void vendre(double &argent,arme &ArmeUse, arme &Arme1, casque &CasqueUse, plastron &PlastronUse, potion &potion1,potion &potion2, potion &potion3);
void vendrePotion(potion &Potion);
void vendreCasque(casque &Casque);
void vendrePlastron(plastron &Plastron);
void vendreArme(arme &Arme);
void combattre(double &argent,int &vie,int &killMonstre,int &xp, int &niveau,position &lieu,arme &Arme1,arme &ArmeUse,casque &CasqueUse,plastron &PlastronUse,potion &potion1,potion &potion2,potion &potion3);
void generation(position &lieu, monstre &Monstre);
void boss(double &argent,int &vie,int &killMonstre,int &xp, int &niveau,position &lieu,arme &Arme1,arme &ArmeUse,casque &CasqueUse,plastron &PlastronUse,potion &potion1,potion &potion2,potion &potion3);
void combattreBoss(monstre Monstre,int &vie,position &lieu,arme &Arme1,arme &ArmeUse,casque &CasqueUse,plastron &PlastronUse,potion &potion1,potion &potion2,potion &potion3);

void boutiquePlaine(double &argent, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3);
void boutiqueJungle(double &argent, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3);
void boutiqueDesert(double &argent, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3);
void boutiqueVolcan(double &argent, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3);

arme arme_vide ={"vide",0,0};
casque casque_vide ={"vide",0,0};
plastron plastron_vide ={"vide",0,0};
potion potion_vide ={"vide",0,0};

//ARMES//

arme Epee_en_bois ={"EpeeEnBois",20,10};
arme Epee_en_fer ={"EpeeEnFer",30,200};
arme Espadon_acier ={"EspadonD'acier",40,350};
arme Hache_de_guerre ={"HacheDeGuerre",50,470};

arme Arc_de_chasseur ={"ArcDeChasseur",65,530};
arme Lance ={"Lance",70,560};
arme Fleau_a_pointe ={"FleauApointe",80,610};

arme Katana ={"Katana",90,700};
arme Arbalete ={"Arbalete",100,800};
arme Dague_elfe ={"DagueD'Elfe",110,910};

arme Masse_du_jugement ={"MasseDuJugement",120,1010};
arme Trident_du_kraken ={"TridentDuKraken",160,1650};
arme Lame_divine ={"LameDivine",210,2300};

//ARMURES//

casque Casque_cuir ={"CasqueEnCuir",5,300};

plastron Plastron_cuir ={"PlastronEnCuir",7,330};
plastron Plastron_fer ={"PlastronEnFer",15,700};
casque Casque_fer ={"CasqueEnFer",10,420};

plastron Plastron_plate ={"PlastronEnPlate",25,900};
casque Casque_plate ={"CasqueEnPlate",20,800};

casque Casque_divin ={"CasqueDivin",30,1000};
plastron Plastron_divin ={"PlastronDivin",35,1500};

//POTIONS//

potion Potion_vie ={"PotionVie",30,60};
potion Potion_degat ={"PotionDegat",-30,80};
potion Potion_super_vie ={"PotionSuperVie",60,120};
potion Potion_super_degat ={"PotionSuperDegat",-60,160};

arme Epee_cheat ={"Epee_cheat",1000,0};


int main()
{
    typedef string const adresse;
    system("color 0f");
    int demande;
    adresse mainmenu("main/mainmenu.txt");
    adresse leavegame("main/leavegame.txt");
    adresse introgame("main/introgame.txt");
    adresse optionmenu("main/option/optionmenu.txt");
    adresse coloroptionmenu("main/option/coloroptionmenu.txt");

    afficher(introgame);

     while(demande != 4)
     {
         afficher(mainmenu);
         cin >> demande;
         if(demande == 1)      //Nouvelle Partie
         {
             nouveaujeu();

         }
         if(demande == 2)      //Chargement jeu
         {
             chargementSave();
         }
         if(demande == 3)     //Options
         {
             int demande1(0);
             while(demande1 != 2)
             {
                 afficher(optionmenu);
                 cin >> demande1;

                 if(demande1 == 1)
                 {
                     int demande2(0);
                     while(demande2 != 11)
                     {
                         afficher(coloroptionmenu);
                         cin >> demande2;

                         if(demande2 == 1) system("color 0f");
                         if(demande2 == 2) system("color 02");
                         if(demande2 == 3) system("color 04");
                         if(demande2 == 4) system("color 03");
                         if(demande2 == 5) system("color 09");
                         if(demande2 == 6) system("color 40");
                         if(demande2 == 7) system("color 90");
                         if(demande2 == 8) system("color 20");
                         if(demande2 == 9) system("color 70");
                         if(demande2 == 10) system("color f0");
                     }
                 }
             }
         }
         if(demande == 4) afficher(leavegame); // Quitter le jeu
     }
    return 0;
}

void effacerSave()
{
    string const save1("save/save1.txt");

    ofstream save(save1.c_str());
    if(save)
    {
        save << "";
    }
}

void chargementSave()
{
    string const save1("save/save1.txt");
    personnage joueur;
    arme Arme1;
    arme ArmeUse;
    plastron PlastronUse;
    casque CasqueUse;
    potion potion1;
    potion potion2;
    potion potion3;
    ifstream save(save1.c_str());
    if(save)
    {
        int temp;
        save >> joueur.nom >> temp >> joueur.niveau >> joueur.xp >> joueur.vie >> joueur.argent >> joueur.killMonstre;
        save >> potion1.soin >> potion1.prix >> potion1.nom >> potion2.soin >> potion2.prix >> potion2.nom >> potion3.soin >> potion3.prix >> potion3.nom;
        save >> Arme1.nom >> Arme1.degats >> Arme1.prix >> ArmeUse.nom >> ArmeUse.degats >> ArmeUse.prix;
        save >> CasqueUse.nom >> CasqueUse.defense >> CasqueUse.prix >> PlastronUse.nom >> PlastronUse.defense >> PlastronUse.prix;
        if(temp == 0) joueur.lieu = Plaine;
        if(temp == 1) joueur.lieu = Jungle;
        if(temp == 2) joueur.lieu = Desert;
        if(temp == 3) joueur.lieu = Volcan;
         jeu(joueur.nom, joueur.lieu, joueur.xp, joueur.killMonstre, joueur.vie, joueur.argent, joueur.niveau, Arme1, ArmeUse, CasqueUse, PlastronUse,potion1,potion2,potion3);

    }

}

void sauvegarderSave(string nom,position lieu,int xp,int killMonstre,int vie,double argent,int niveau,arme Arme1,arme ArmeUse,casque CasqueUse,plastron PlastronUse,potion potion1,potion potion2,potion potion3)
{string const save1("save/save1.txt");
    ofstream save(save1.c_str());
    if(save)
    {
        save << nom << endl << lieu << endl << niveau << endl << xp << endl << vie << endl << argent << endl << killMonstre << endl;
        save << potion1.soin << endl << potion1.prix << endl << potion1.nom << endl << potion2.soin << endl << potion2.prix << endl << potion2.nom << endl << potion3.soin << endl << potion3.prix << endl << potion3.nom << endl;
        save << Arme1.nom << endl << Arme1.degats << endl << Arme1.prix << endl << ArmeUse.nom << endl << ArmeUse.degats << endl << ArmeUse.prix << endl;
        save << CasqueUse.nom << endl << CasqueUse.defense << endl << CasqueUse.prix << endl << PlastronUse.nom << endl << PlastronUse.defense << endl << PlastronUse.prix << endl;
        system("cls");
        cout << endl << endl << endl << endl << endl << "                            Sauvegarde Reussie !" << endl;
        Sleep(2000);

    }
}


void nouveaujeu()
{
    typedef string const adresse;
    adresse newgame("main/newgame.txt");
    adresse hist1("text/hist1.txt");
    adresse hist2("text/hist2.txt");
    int demande;
    afficher(newgame);
    while(demande != 2)
    {

        cin >> demande;
        if(demande == 1)
        {
            effacerSave();
            system("cls");
            personnage joueur;
            arme Arme1;
            arme ArmeUse;
            plastron PlastronUse;
            casque CasqueUse;
            potion potion1;
            potion potion2;
            potion potion3;
            Arme1 = arme_vide;
            ArmeUse = Epee_en_bois;
            PlastronUse = plastron_vide;
            CasqueUse = casque_vide;
            potion1 = potion_vide;
            potion2 = potion_vide;
            potion3 = potion_vide;
            cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "                        Nom du joueur: ";
            cin >> joueur.nom;
            cout << joueur.nom;
            joueur.lieu = Plaine;
            joueur.xp = 0;
            joueur.niveau = 1;
            joueur.killMonstre = 0;
            joueur.vie = 100;
            joueur.argent = 10;
            sauvegarderSave(joueur.nom, joueur.lieu, joueur.xp, joueur.killMonstre, joueur.vie,joueur.argent,joueur.niveau,Arme1,ArmeUse,CasqueUse,PlastronUse,potion1,potion2,potion3);

            system("cls");
            afficher(hist1);

            jeu(joueur.nom, joueur.lieu, joueur.xp, joueur.killMonstre, joueur.vie, joueur.argent, joueur.niveau, Arme1, ArmeUse, CasqueUse, PlastronUse,potion1,potion2,potion3);
            demande = 2;
        }
    }
}

void jeu(string &nom_joueur, position &lieu_joueur, int &xp_joueur, int &killMonstre_joueur, int &vie_joueur, double &argent_joueur, int &niveau_joueur, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3)
{
    typedef string const adresse;
    adresse returnmain("main/returnmain.txt");
    int demande(0);
    while(demande != 6)
    {
        GUI(lieu_joueur, nom_joueur, niveau_joueur, xp_joueur, killMonstre_joueur, argent_joueur, vie_joueur);
        cin >> demande;
        if(demande == 1)combattre(argent_joueur,vie_joueur,killMonstre_joueur,xp_joueur,niveau_joueur,lieu_joueur,Arme1,ArmeUse,CasqueUse,PlastronUse,potion1,potion2,potion3);

        if(demande == 2)boss(argent_joueur,vie_joueur,killMonstre_joueur,xp_joueur,niveau_joueur,lieu_joueur,Arme1,ArmeUse,CasqueUse,PlastronUse,potion1,potion2,potion3);

        if(demande == 3)
        {
            Inventaire(argent_joueur,vie_joueur,ArmeUse,Arme1,CasqueUse,PlastronUse,potion1,potion2,potion3);
        }
        if(demande == 4)
        {
            if(lieu_joueur == Plaine) boutiquePlaine(argent_joueur, Arme1, ArmeUse, CasqueUse, PlastronUse, potion1, potion2, potion3);
            if(lieu_joueur == Jungle) boutiqueJungle(argent_joueur, Arme1, ArmeUse, CasqueUse, PlastronUse, potion1, potion2, potion3);
            if(lieu_joueur == Desert) boutiqueDesert(argent_joueur, Arme1, ArmeUse, CasqueUse, PlastronUse, potion1, potion2, potion3);
            if(lieu_joueur == Volcan) boutiqueVolcan(argent_joueur, Arme1, ArmeUse, CasqueUse, PlastronUse, potion1, potion2, potion3);
        }
        if(demande == 5) sauvegarderSave(nom_joueur, lieu_joueur, xp_joueur, killMonstre_joueur, vie_joueur,argent_joueur,niveau_joueur,Arme1,ArmeUse,CasqueUse,PlastronUse,potion1,potion2,potion3);
        if(demande == 6)
        {
            int demande2(0);
            afficher(returnmain);
            cin >> demande2;
            if(demande2 == 2) demande = 0;
        }
    }
}

void boutiquePlaine(double &argent, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3)
{
    string const boutique0("main/game/boutique0.txt");
    int demande(0);
    while(demande != 8)
    {
        afficher(boutique0);
        cout << "                                                              Argent: " << argent << "$" << endl;
        cin >> demande;
        if(demande == 1) acheterArme(argent,Epee_en_bois,ArmeUse,Arme1);
        if(demande == 2) acheterArme(argent,Epee_en_fer,ArmeUse,Arme1);
        if(demande == 3) acheterArme(argent,Espadon_acier,ArmeUse,Arme1);
        if(demande == 4) acheterArme(argent,Hache_de_guerre,ArmeUse,Arme1);

        if(demande == 5) acheterCasque(argent,Casque_cuir,CasqueUse);

        if(demande == 6) acheterPotion(argent,Potion_vie,potion1, potion2, potion3);

        if(demande == 7) vendre(argent,ArmeUse,Arme1,CasqueUse,PlastronUse,potion1,potion2,potion3);

    }

}
void boutiqueJungle(double &argent, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3)
{
    string const boutique1("main/game/boutique1.txt");
    int demande(0);
    while(demande != 10)
    {
        afficher(boutique1);
        cout << "                                                              Argent: " << argent << "$" << endl;
        cin >> demande;
        if(demande == 1) acheterArme(argent,Arc_de_chasseur,ArmeUse,Arme1);
        if(demande == 2) acheterArme(argent,Lance,ArmeUse,Arme1);
        if(demande == 3) acheterArme(argent,Fleau_a_pointe,ArmeUse,Arme1);

        if(demande == 4) acheterPlastron(argent,Plastron_cuir,PlastronUse);
        if(demande == 5) acheterPlastron(argent,Plastron_fer,PlastronUse);
        if(demande == 6) acheterCasque(argent,Casque_fer,CasqueUse);

        if(demande == 7) acheterPotion(argent,Potion_vie,potion1,potion2,potion3);
        if(demande == 8) acheterPotion(argent,Potion_degat,potion1,potion2,potion3);
        if(demande == 9) vendre(argent,ArmeUse,Arme1,CasqueUse,PlastronUse,potion1,potion2,potion3);
    }

}
void boutiqueDesert(double &argent, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3)
{
    string const boutique2("main/game/boutique2.txt");
    int demande(0);
    while(demande != 10)
    {
        afficher(boutique2);
        cout << "                                                              Argent: " << argent << "$" << endl;
        cin >> demande;
        if(demande == 1) acheterArme(argent,Katana,ArmeUse,Arme1);
        if(demande == 2) acheterArme(argent,Arbalete,ArmeUse,Arme1);
        if(demande == 3) acheterArme(argent,Dague_elfe,ArmeUse,Arme1);

        if(demande == 4) acheterPlastron(argent,Plastron_plate,PlastronUse);
        if(demande == 5) acheterCasque(argent,Casque_plate,CasqueUse);

        if(demande == 6) acheterPotion(argent,Potion_vie,potion1,potion2,potion3);
        if(demande == 7) acheterPotion(argent,Potion_super_vie,potion1,potion2,potion3);
        if(demande == 8) acheterPotion(argent,Potion_degat,potion1,potion2,potion3);
        if(demande == 9) vendre(argent,ArmeUse,Arme1,CasqueUse,PlastronUse,potion1,potion2,potion3);
    }

}
void boutiqueVolcan(double &argent, arme &Arme1, arme &ArmeUse, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3)
{
    string const boutique3("main/game/boutique3.txt");
    int demande(0);
    while(demande != 11)
    {
        afficher(boutique3);
        cout << "                                                              Argent: " << argent << "$" << endl;
        cin >> demande;
        if(demande == 1) acheterArme(argent,Masse_du_jugement,ArmeUse,Arme1);
        if(demande == 2) acheterArme(argent,Trident_du_kraken,ArmeUse,Arme1);
        if(demande == 3) acheterArme(argent,Lame_divine,ArmeUse,Arme1);

        if(demande == 4) acheterCasque(argent,Casque_divin,CasqueUse);
        if(demande == 5) acheterPlastron(argent,Plastron_divin,PlastronUse);

        if(demande == 6) acheterPotion(argent,Potion_vie,potion1,potion2,potion3);
        if(demande == 7) acheterPotion(argent,Potion_super_vie,potion1,potion2,potion3);
        if(demande == 8) acheterPotion(argent,Potion_degat,potion1,potion2,potion3);
        if(demande == 9) acheterPotion(argent,Potion_super_degat,potion1,potion2,potion3);
        if(demande == 10) vendre(argent,ArmeUse,Arme1,CasqueUse,PlastronUse,potion1,potion2,potion3);
    }

}

void GUI(position lieu,string nom,int niveau,int xp,int nombreKill,double argent, int vie)
{
    string position;
    if(lieu == 0)position = "Plaine";
    if(lieu == 1)position = "Jungle";
    if(lieu == 2)position = "Desert";
    if(lieu == 3)position = "Volcan";
    system("cls");
    cout << "    ========================================================================" << endl << endl;
    cout << "                                 Lieu: " << position << endl << endl;
    cout << endl;
    cout << "     MENU:                                              STATISTIQUES:" << endl << endl << endl;
    cout << "      (1)Combattre                                         Nom: " << nom << endl << endl;
    cout << "      (2)Combattre Boss                                    Niveau: " << niveau << endl << endl;
    cout << "      (3)Inventaire                                        XP: " << xp << "/1000" << endl << endl;
    cout << "      (4)Boutique                                          Nombre Kill: " << nombreKill << endl << endl;
    cout << "      (5)Sauvegarder                                       Argent: " << argent << " $" << endl << endl;
    cout << "      (6)Quitter                                           Vie: " << vie << "/100" << endl << endl << endl << endl << endl;
    cout << "    ========================================================================" << endl;
}
void Inventaire(double &argent,int &vie, arme &ArmeUse, arme &Arme1, casque &CasqueUse, plastron &PlastronUse, potion &potion1, potion &potion2, potion &potion3 )
{
    int demande2(0);
    while(demande2 != 9)
    {
    system("cls");
    cout << "    ========================================================================" << endl << endl;
    cout << "                                   |INVENTAIRE|" << endl << endl;
    cout << "               Vie: " << vie << "/100                              Argent: " << argent << "$" << endl << endl << endl;
    cout << "                    (1)ARME PRINCIPALE: " << ArmeUse.nom << "(Dgt: " << ArmeUse.degats << " Prix: " << ArmeUse.prix << "$)" << endl;
    cout << "                    (2)ARME SECONDAIRE: " << Arme1.nom << "(Dgt: " << Arme1.degats << " Prix: " << Arme1.prix << "$)" << endl << endl;
    cout << "                    (3)CASQUE:          " << CasqueUse.nom << "(Def: " << CasqueUse.defense << " Prix: " << CasqueUse.prix << "$)" << endl;
    cout << "                    (4)PLASTRON:        " << PlastronUse.nom << "(Def: " << PlastronUse.defense << " Prix: " << PlastronUse.prix << "$)" << endl << endl;
    cout << "                    (5)Potion n1:       " << potion1.nom << "(Val: " << potion1.soin << " Prix: " << potion1.prix << "$)" << endl;
    cout << "                    (6)Potion n2:       " << potion2.nom << "(Val: " << potion2.soin << " Prix: " << potion2.prix << "$)" << endl;
    cout << "                    (7)Potion n3:       " << potion3.nom << "(Val: " << potion3.soin << " Prix: " << potion3.prix << "$)" << endl << endl << endl;
    cout << "                    (8)Echanger Armes" << endl << endl;
    cout << "                    (9)Retour" << endl << endl << endl;
    cout << "    ========================================================================" << endl;
    cin >> demande2;
    if(demande2 == 8) echangeArme(ArmeUse, Arme1);
    if(demande2 == 1)
    {
        int demande3(0);
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                    Voulez-vous jeter cet objet ?: " << ArmeUse.nom << endl << endl << endl;
        cout << "                    (1)Oui                       (2)Non" << endl;
        cin >> demande3;
        if(demande3 == 1) ArmeUse = arme_vide;
    }
    if(demande2 == 2)
    {
        int demande3(0);
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                    Voulez-vous jeter cet objet ?: " << Arme1.nom << endl << endl << endl;
        cout << "                    (1)Oui                       (2)Non" << endl;
        cin >> demande3;
        if(demande3 == 1) Arme1 = arme_vide;
    }
    if(demande2 == 3)
    {
        int demande3(0);
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                    Voulez-vous jeter cet objet ?: " << CasqueUse.nom << endl << endl << endl;
        cout << "                    (1)Oui                       (2)Non" << endl;
        cin >> demande3;
        if(demande3 == 1) CasqueUse = casque_vide;
    }
    if(demande2 == 4)
    {
        int demande3(0);
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << "                    Voulez-vous jeter cet objet ?: " << PlastronUse.nom << endl << endl << endl;
        cout << "                    (1)Oui                       (2)Non" << endl;
        cin >> demande3;
        if(demande3 == 1) PlastronUse = plastron_vide;
    }
    if(demande2 == 5)
    {
        int demande4(0);
        system("cls");
        while(demande4 != 3)
        {
            cout << endl << endl << endl << endl << endl << endl << endl << endl << "                 Que voulez-vous faire avec cet objet ?: " << potion1.nom << endl << endl;
            cout << "                 (1)Jeter" << endl << endl;
            cout << "                 (2)Utiliser" << endl << endl << endl;
            cout << "                 (3)Retour" << endl;
            cin >> demande4;
            if(demande4 == 1)
            {
                potion1 = potion_vide;
                demande4 = 3;
            }
            if(demande4 == 2)
            {
                vie = vie + potion1.soin;
                potion1 = potion_vide;
                actualiserVie(vie);
                demande4 = 3;
            }
        }
    }
    if(demande2 == 6)
    {
        int demande4(0);
        system("cls");
        while(demande4 != 3)
        {
            cout << endl << endl << endl << endl << endl << endl << endl << endl << "                 Que voulez-vous faire avec cet objet ?: " << potion2.nom << endl << endl;
            cout << "                 (1)Jeter" << endl << endl;
            cout << "                 (2)Utiliser" << endl << endl << endl;
            cout << "                 (3)Retour" << endl;
            cin >> demande4;
            if(demande4 == 1)
            {
                potion2 = potion_vide;
                demande4 = 3;
            }
            if(demande4 == 2)
            {
                vie = vie + potion2.soin;
                potion2 = potion_vide;
                actualiserVie(vie);
                demande4 = 3;
            }
        }

    }
    if(demande2 == 7)
    {
        int demande4(0);
        system("cls");
        while(demande4 != 3)
        {
            cout << endl << endl << endl << endl << endl << endl << endl << endl << "                 Que voulez-vous faire avec cet objet ?: " << potion3.nom << endl << endl;
            cout << "                 (1)Jeter" << endl << endl;
            cout << "                 (2)Utiliser" << endl << endl << endl;
            cout << "                 (3)Retour" << endl;
            cin >> demande4;
            if(demande4 == 1)
            {
                potion3 = potion_vide;
                demande4 = 3;
            }
            if(demande4 == 2)
            {
                vie = vie + potion3.soin;
                potion3 = potion_vide;
                actualiserVie(vie);
                demande4 = 3;
            }
        }

    }
    }
}

void echangeArme(arme &ArmeUse,arme &Arme1)
{
    arme temp;
    temp = ArmeUse;
    ArmeUse = Arme1;
    Arme1 = temp;
}

void actualiserVie(int &vie)
{
    string const mort("anim/mort.txt");
    if(vie > 100) vie = 100;
    if(vie <= 0)
    {
        afficher(mort);
        exit(0);
    }
}

void actualiserXp(int &xp, int &niveau)
{
    if(xp >= 1000)
    {
        int temp;
        niveau++;
        temp = xp - 1000;
        xp = 0;
        xp += temp;
    }
}

void acheterArme(double &argent,arme &Arme,arme &ArmeUse,arme &Arme1)
{
    string const pasargent("main/game/pasargent.txt");
    if(argent >= Arme.prix)
            {
                int demande(0);
                system("cls");
                cout << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << "                    Voulez-vous acheter " << Arme.nom << " en jetant: " << endl << endl;
                cout << "                               (1)-" << ArmeUse.nom << " ?" << endl;
                cout << "                               (2)-" << Arme1.nom << " ?" << endl << endl;
                cout << "                               (3)Retour " << endl;
                while(demande != 3)
                {
                    cin >> demande;
                    if(demande == 1)
                    {
                        argent -= Arme.prix;
                        ArmeUse = Arme;
                        demande = 3;
                    }
                    if(demande == 2)
                    {
                        argent -= Arme.prix;
                        Arme1 = Arme;
                        demande = 3;
                    }
                }
            }
    else if(argent < Arme.prix)
        {
                afficher(pasargent);
                Sleep(1500);
        }
}

void acheterPlastron(double &argent, plastron &Plastron, plastron &PlastronUse)
{
    string const pasargent("main/game/pasargent.txt");
    if(argent >= Plastron.prix)
    {
        int demande(0);
         system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "             Voulez-vous acheter " << Plastron.nom << " en jetant " << PlastronUse.nom << " ?" << endl << endl << endl;
        cout << "                  (1)Oui                            (2)Non" << endl;
        while(demande != 2)
        {
            cin >> demande;
            if(demande == 1)
            {
                argent -= Plastron.prix;
                PlastronUse = Plastron;
                demande = 2;
            }
        }
    }
    else if(argent < Plastron.prix)
    {
        afficher(pasargent);
        Sleep(1500);
    }

}

void acheterCasque(double &argent, casque &Casque, casque &CasqueUse)
{
    string const pasargent("main/game/pasargent.txt");
    if(argent >= Casque.prix)
    {
        int demande(0);
         system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "              Voulez-vous acheter " << Casque.nom << " en jetant " << CasqueUse.nom << " ?" << endl << endl << endl;
        cout << "                  (1)Oui                            (2)Non" << endl;
        while(demande != 2)
        {
            cin >> demande;
            if(demande == 1)
            {
                argent -= Casque.prix;
                CasqueUse = Casque;
                demande = 2;
            }
        }
    }
    else if(argent < Casque.prix)
    {
        afficher(pasargent);
        Sleep(1500);
    }

}

void acheterPotion(double &argent, potion &Potion, potion &Potion1, potion &Potion2, potion &Potion3)
{
    string const pasargent("main/game/pasargent.txt");
    if(argent >= Potion.prix)
    {
        int demande(0);
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                    Voulez-vous acheter " << Potion.nom << " en jetant: " << endl << endl;
        cout << "                               (1)-" << Potion1.nom << " ?" << endl;
        cout << "                               (2)-" << Potion2.nom << " ?" << endl;
        cout << "                               (3)-" << Potion3.nom << " ?" << endl << endl;
        cout << "                               (4)Retour " << endl;
        while(demande != 4)
        {
            cin >> demande;
            if(demande == 1)
            {
                argent -= Potion.prix;
                Potion1 = Potion;
                demande = 4;
            }
            if(demande == 2)
            {
                argent -= Potion.prix;
                Potion2 = Potion;
                demande = 4;
            }
            if(demande == 3)
            {
                argent -=Potion.prix;
                Potion3 = Potion;
                demande = 4;
            }
        }
    }
    else if(argent < Potion.prix)
    {
        afficher(pasargent);
                Sleep(1500);
    }

}

void vendre(double &argent,arme &ArmeUse, arme &Arme1, casque &CasqueUse, plastron &PlastronUse, potion &potion1,potion &potion2, potion &potion3)
{
    int demande(0);
    while(demande != 8)
    {
        system("cls");
        cout << "          ===========================VENDRE===========================" << endl << endl << endl;
        cout << "                     Argent: " << argent << "$" << endl << endl << endl;
        cout << "                          (1)" << ArmeUse.nom << endl;
        cout << "                          (2)" << Arme1.nom << endl << endl << endl;
        cout << "                          (3)" << CasqueUse.nom << endl;
        cout << "                          (4)" << PlastronUse.nom << endl << endl << endl;
        cout << "                          (5)" << potion1.nom << endl;
        cout << "                          (6)" << potion2.nom << endl;
        cout << "                          (7)" << potion3.nom << endl << endl << endl;
        cout << "                          (8)Retour" << endl << endl << endl;
        cout << "          ============================================================" << endl;
        cin >> demande;
        if(demande == 1)
        {
            vendreArme(ArmeUse);
            int demande2(0);
            cin >> demande2;
            if(demande2 == 1)
            {
                argent += ArmeUse.prix*0.75;
                ArmeUse = arme_vide;
            }
        }
        if(demande == 2)
        {
            vendreArme(Arme1);
            int demande2(0);
            cin >> demande2;
            if(demande2 == 1)
            {
                argent += Arme1.prix*0.75;
                Arme1 = arme_vide;
            }
        }
        if(demande == 3)
        {
            vendreCasque(CasqueUse);
            int demande2(0);
            cin >> demande2;
            if(demande2 == 1)
            {
                argent += CasqueUse.prix*0.75;
                CasqueUse = casque_vide;
            }
        }
        if(demande == 4)
        {
            vendrePlastron(PlastronUse);
            int demande2(0);
            cin >> demande2;
            if(demande == 1)
            {
                argent += PlastronUse.prix*0.75;
                PlastronUse = plastron_vide;
            }
        }
        if(demande == 5)
        {
            vendrePotion(potion1);
            int demande2(0);
            cin >> demande2;
            if(demande2 == 1)
            {
                argent += potion1.prix;
                potion1 = potion_vide;
            }
        }
        if(demande == 6)
        {
            vendrePotion(potion2);
            int demande2(0);
            cin >> demande2;
            if(demande2 == 1)
            {
                argent += potion2.prix;
                potion2 = potion_vide;
            }
        }
        if(demande == 7)
        {
            vendrePotion(potion3);
            int demande2(0);
            cin >> demande2;
            if(demande2 == 1)
            {
                argent += potion3.prix;
                potion3 = potion_vide;
            }
        }
    }
}

void vendreArme(arme &Arme)
{
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                    Voulez-vous vendre " << Arme.nom << " pour " << Arme.prix*0.75 << "$ ?" << endl << endl;
    cout << "                        (1)Oui                   (2)Non" << endl;
}

void vendrePlastron(plastron &Plastron)
{
    system("cls");
    cout << endl << endl << endl << endl << endl <<endl << endl << endl;
    cout << "                    Voulez-vous vendre " << Plastron.nom << " pour " << Plastron.prix*0.75 << "$ ?" << endl << endl;
    cout << "                        (1)Oui                   (2)Non" << endl;

}

void vendreCasque(casque &Casque)
{
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                    Voulez-vous vendre " << Casque.nom << " pour " << Casque.prix*0.75 << "$ ?" << endl << endl;
    cout << "                        (1)Oui                   (2)Non" << endl;
}

void vendrePotion(potion &Potion)
{
    system("cls");
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "                    Voulez-vous vendre " << Potion.nom << " pour " << Potion.prix*0.75 << "$ ?" << endl << endl;
    cout << "                        (1)Oui                   (2)Non" << endl;

}

void combattre(double &argent,int &vie,int &killMonstre,int &xp, int &niveau,position &lieu,arme &Arme1,arme &ArmeUse,casque &CasqueUse,plastron &PlastronUse,potion &potion1,potion &potion2,potion &potion3)
{
    srand(time(0));
    typedef string const adresse;
    adresse lancerpotion("anim/combat/lancerpotion.txt");
    adresse utiliserpotion("anim/combat/utiliserpotion.txt");

    adresse Araigne("main/mob/Araigné.txt");
    adresse Cerbere("main/mob/Cerbère.txt");
    adresse Dragon("main/mob/Dragon.txt");
    adresse Golem("main/mob/Golem.txt");
    adresse Gorille("main/mob/Gorille.txt");
    adresse Lezard("main/mob/Lézard.txt");
    adresse loup("main/mob/loup.txt");
    adresse Mookiepoco("main/mob/Mookie poco.txt");
    adresse Moustique("main/mob/Moustique.txt");
    adresse Panthere("main/mob/Panthère.txt");
    adresse Vautour("main/mob/Vautour.txt");
    adresse Vipere("main/mob/Vipère.txt");
    monstre Monstre;
    generation(lieu,Monstre);
    int viefix(Monstre.vie);

    if(Monstre.nom == "Loup") afficher(loup);
    if(Monstre.nom == "Araigne") afficher(Araigne);
    if(Monstre.nom == "Vipere") afficher(Vipere);
    if(Monstre.nom == "Moustique") afficher(Moustique);
    if(Monstre.nom == "Gorille") afficher(Gorille);
    if(Monstre.nom == "Panthere") afficher(Panthere);
    if(Monstre.nom == "Mookie Poco") afficher(Mookiepoco);
    if(Monstre.nom == "Lezard") afficher(Lezard);
    if(Monstre.nom == "Vautour") afficher(Vautour);
    if(Monstre.nom == "Golem de feu") afficher(Golem);
    if(Monstre.nom == "Dragon") afficher(Dragon);
    if(Monstre.nom == "Cerbere") afficher(Cerbere);

    int demande(0);
    while(Monstre.vie > 0)
    {
        demande = 0;
        while(demande != 1 && demande != 2)
        {
        system("cls");
        cout << endl;
        cout << "    ================================COMBAT=================================" << endl << endl;
        cout << "                      JOUEUR:" << endl << endl;
        cout << "                  Vie: " << vie << "/100" << endl;
        cout << "                  Degat: " << ArmeUse.degats << endl;
        cout << "                  Defense: " << (CasqueUse.defense+PlastronUse.defense) << endl << endl;
        cout << "                                                 (1)Attaquer" << endl << endl;
        cout << "                                                 (2)Utiliser Potion" << endl << endl;
        cout << "                      MONSTRE : " << endl << endl;
        cout << "                  Type: " << Monstre.nom << endl;
        cout << "                  Vie: " << Monstre.vie << "/" << viefix << endl << endl;
        cout << "    -----------------------------------------------------------------------" << endl;
        cout << "     Choisissez une action:";
        cin >> demande;

        if(demande == 1)
        {
            int demande2(0);
            while(demande2 != 4)
            {
                        system("cls");
                cout << endl;
                cout << "    ================================COMBAT=================================" << endl << endl;
                cout << "                      JOUEUR:" << endl << endl;
                cout << "                  (1) Attaque Faible (75%)" << endl;
                cout << "                  (2) Attaque Moyenne (100%)" << endl;
                cout << "                  (3) Attaque Forte (125%)" << endl;
                cout << "                  (4) Retour" << endl;
                cout << "                                                 (/)Attaquer" << endl << endl;
                cout << "                                                 (/)Utiliser Potion" << endl << endl;
                cout << "                      MONSTRE : " << endl << endl;
                cout << "                  Type: " << Monstre.nom << endl;
                cout << "                  Vie: " << Monstre.vie << "/" << viefix << endl << endl;
                cout << "    -----------------------------------------------------------------------" << endl;
                cout << "     Choisissez une action:";
                cin >> demande2;

                if(demande2 == 4) demande = 0;
                if(demande2 == 1)
                {
                    int alea;
                    alea = rand()%100;
                    if(alea > 94)
                    {
                        cout << "     Echec de l'attaque !" << endl;
                        Sleep(2000);
                        demande2 = 4;
                    }
                    if(alea <= 94)
                    {
                        cout << "     Vous infligez " << (ArmeUse.degats*75/100) << " !" << endl;
                        Monstre.vie -= (ArmeUse.degats*75/100);
                        Sleep(2000);
                        demande2 = 4;
                    }
                }

                if(demande2 == 2)
                {
                    int alea;
                    alea = rand()%100;
                    if(alea > 59)
                    {
                        cout << "     Echec de l'attaque !" << endl;
                        Sleep(2000);
                        demande2 = 4;
                    }
                    if(alea <= 59)
                    {
                        cout << "     Vous infligez " << ArmeUse.degats << " !" << endl;
                        Monstre.vie -= ArmeUse.degats;
                        Sleep(2000);
                        demande2 = 4;
                    }

                }

                if(demande2 == 3)
                {
                    int alea;
                    alea = rand()%100;
                    if(alea > 39)
                    {
                        cout << "     Echec de l'attaque !" << endl;
                        Sleep(2000);
                        demande2 = 4;
                    }
                    if(alea <= 39)
                    {
                        cout << "     Vous infligez " << (ArmeUse.degats*125/100) << " !" << endl;
                        Monstre.vie -= (ArmeUse.degats*125/100);
                        Sleep(2000);
                        demande2 = 4;
                    }
                }



            }

        }
        if(demande == 2)
        {
            int demande2(0);
            while(demande2 != 4)
            {
                        system("cls");
                cout << endl;
                cout << "    ================================COMBAT=================================" << endl << endl;
                cout << "                      JOUEUR:" << endl << endl;
                cout << "                  (1) " << potion1.nom << " (val: " << potion1.soin << ")" << endl;
                cout << "                  (2) " << potion2.nom << " (val: " << potion2.soin << ")" << endl;
                cout << "                  (3) " << potion3.nom << " (val: " << potion3.soin << ")" << endl;
                cout << "                  (4) Retour" << endl;
                cout << "                                                 (/)Attaquer" << endl << endl;
                cout << "                                                 (/)Utiliser Potion" << endl << endl;
                cout << "                      MONSTRE : " << endl << endl;
                cout << "                  Type: " << Monstre.nom << endl;
                cout << "                  Vie: " << Monstre.vie << "/" << viefix << endl << endl;
                cout << "    -----------------------------------------------------------------------" << endl;
                cout << "     Choisissez une action:";
                cin >> demande2;

                if(demande2 == 4) demande = 0;
                if(demande2 == 1)
                {
                    if(potion1.soin < 0)
                    {
                        cout << "     Vous utilisez une potion et vous infligez " << -potion1.soin << " degats !" << endl;
                        Monstre.vie += potion1.soin;
                        potion1 = potion_vide;
                        Sleep(2000);
                        afficher(lancerpotion);
                        demande2 = 4;
                    }
                    if(potion1.soin > 0)
                    {
                        cout << "     Vous utilisez une potion et obtenez " << potion1.soin << " pv!" << endl;
                        vie += potion1.soin;
                        potion1 = potion_vide;
                        Sleep(2000);
                        afficher(utiliserpotion);
                        actualiserVie(vie);
                        demande2 = 4;
                    }
                }
                if(demande2 == 2)
                {
                    if(potion2.soin < 0)
                    {
                        cout << "     Vous utilisez une potion et vous infligez " << -potion2.soin << " degats !" << endl;
                        Monstre.vie += potion2.soin;
                        potion2 = potion_vide;
                        Sleep(2000);
                        afficher(lancerpotion);
                        demande2 = 4;
                    }
                    if(potion2.soin > 0)
                    {
                        cout << "     Vous utilisez une potion et obtenez " << potion2.soin << " pv!" << endl;
                        vie += potion2.soin;
                        potion2 = potion_vide;
                        Sleep(2000);
                        afficher(utiliserpotion);
                        actualiserVie(vie);
                        demande2 = 4;
                    }

                }
                if(demande2 == 3)
                {
                    if(potion3.soin < 0)
                    {
                        cout << "     Vous utilisez une potion et vous infligez " << -potion2.soin << " degats !" << endl;
                        Monstre.vie += potion3.soin;
                        potion3 = potion_vide;
                        Sleep(2000);
                        afficher(lancerpotion);
                        demande2 = 4;

                    }
                    if(potion3.soin > 0)
                    {
                        cout << "     Vous utilisez une potion et obtenez " << potion3.soin << " pv!" << endl;
                        vie += potion3.soin;
                        potion3 = potion_vide;
                        Sleep(2000);
                        afficher(utiliserpotion);
                        actualiserVie(vie);
                        demande2 = 4;
                    }
                }

            }


        }

        }
        if(Monstre.vie > 0)
        {
        system("cls");
        cout << endl;
        cout << "    ================================COMBAT=================================" << endl << endl;
        cout << "                      JOUEUR:" << endl << endl;
        cout << "                  Vie: " << vie << "/100" << endl;
        cout << "                  Degat: " << ArmeUse.degats << endl;
        cout << "                  Defense: " << (CasqueUse.defense+PlastronUse.defense) << endl << endl;
        cout << "                                                 (1)Attaquer" << endl << endl;
        cout << "                                                 (2)Utiliser Potion" << endl << endl;
        cout << "                      MONSTRE : " << endl << endl;
        cout << "                  Type: " << Monstre.nom << endl;
        cout << "                  Vie: " << Monstre.vie << "/" << viefix << endl << endl;
        cout << "    -----------------------------------------------------------------------" << endl;
        cout << "     Tour de l'ennemi:" << endl;
        Sleep(2000);
        int alea;
        alea = rand()%100;
        if(alea > Monstre.chance)
        {
            cout << "     [ENNEMI] Echec de l'attaque !" << endl;
            Sleep(1500);
        }
        if(alea <= Monstre.chance)
        {
            int alea2;
            alea2 = rand()%5;
            int att;
            att = (Monstre.degats)-(CasqueUse.defense+PlastronUse.defense);
            if(att < 0) att = 0;
            if(alea2 == 0)
            {
                att = (att*110/100);
            }

            cout << "     [ENNEMI] Vous inflige " << att << " degats !" << endl;
            Sleep(1500);
            vie -= att;
            actualiserVie(vie);
        }
        cout << "     -Fin du tour-" << endl;
        Sleep(1500);
        }

    }

    if(lieu == 0)
    {
        if(niveau < 3)
        {
            argent += 150;
        xp += 200;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                          Bravo! Vous avez gagne:" << endl << endl;
        Sleep(1500);
        cout << "                                   -200xp" << endl << endl;
        Sleep(1500);
        cout << "                                   -150$" << endl;
        Sleep(2500);
        }
        else if(niveau >= 3)
        {
            argent += 180;
        xp += 10;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                          Bravo! Vous avez gagne:" << endl << endl;
        Sleep(1500);
        cout << "                                   -10xp" << endl << endl;
        Sleep(1500);
        cout << "                                   -180$" << endl;
        Sleep(2500);

        }


    }
    if(lieu == 1)
    {
        if(niveau < 5)
        {
            argent += 200;
        xp += 150;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                          Bravo! Vous avez gagne:" << endl << endl;
        Sleep(1500);
        cout << "                                   -150xp" << endl << endl;
        Sleep(1500);
        cout << "                                   -200$" << endl;
        Sleep(2500);
        }
        else if(niveau >= 5)
        {
            argent += 240;
        xp += 8;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                          Bravo! Vous avez gagne:" << endl << endl;
        Sleep(1500);
        cout << "                                   -8xp" << endl << endl;
        Sleep(1500);
        cout << "                                   -240$" << endl;
        Sleep(2500);
        }

    }
    if(lieu == 2)
    {
        if(niveau < 7)
        {
            argent += 250;
        xp += 100;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                          Bravo! Vous avez gagne:" << endl << endl;
        Sleep(1500);
        cout << "                                   -100xp" << endl << endl;
        Sleep(1500);
        cout << "                                   -250$" << endl;
        Sleep(2500);
        }
        else if(niveau >= 7)
        {
            argent += 280;
        xp += 5;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                          Bravo! Vous avez gagne:" << endl << endl;
        Sleep(1500);
        cout << "                                   -5xp" << endl << endl;
        Sleep(1500);
        cout << "                                   -280$" << endl;
        Sleep(2500);

        }

    }
    if(lieu == 3)
    {
        if(niveau < 8)
        {
            argent += 300;
        xp += 50;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                          Bravo! Vous avez gagne:" << endl << endl;
        Sleep(1500);
        cout << "                                   -50xp" << endl << endl;
        Sleep(1500);
        cout << "                                   -300$" << endl;
        Sleep(2500);
        }
        else if(niveau >= 8)
        {
            argent += 320;
        xp += 0;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                          Bravo! Vous avez gagne:" << endl << endl;
        Sleep(1500);
        cout << "                                   -0xp" << endl << endl;
        Sleep(1500);
        cout << "                                   -320$" << endl;
        Sleep(2500);
        }

    }
}

void generation(position &lieu, monstre &Monstre)
{
    srand(time(0));
    if(lieu == Plaine)
    {
        Monstre.vie = rand()%(100-50) +50;
        Monstre.chance = 80;
        int temp(rand()%3);
        if(temp == 0) Monstre.nom = "Loup";
        if(temp == 1) Monstre.nom = "Araigne";
        if(temp == 2) Monstre.nom = "Vipere";
        Monstre.degats = rand()%(20-15) +15;

    }
    if(lieu == Jungle)
    {
        Monstre.vie = rand()%(150-100) +100;
        Monstre.chance = 80;
        int temp(rand()%3);
        if(temp == 0) Monstre.nom = "Moustique";
        if(temp == 1) Monstre.nom = "Gorille";
        if(temp == 2) Monstre.nom = "Panthere";
        Monstre.degats = rand()%(25-20) +20;

    }
    if(lieu == Desert)
    {
        Monstre.vie = rand()%(200-150) +150;
        Monstre.chance = 80;
        int temp(rand()%3);
        if(temp == 0) Monstre.nom = "Mookie Poco";
        if(temp == 1) Monstre.nom = "Lezard";
        if(temp == 2) Monstre.nom = "Vautour";
        Monstre.degats = rand()%(35-25) +25;

    }
    if(lieu == Volcan)
    {
        Monstre.vie = rand()%(300-200) +200;
        Monstre.chance = 80;
        int temp(rand()%3);
        if(temp == 0) Monstre.nom = "Golem de feu";
        if(temp == 1) Monstre.nom = "Dragon";
        if(temp == 2) Monstre.nom = "Cerbere";
        Monstre.degats = rand()%(45-35) +35;
    }
}

void boss(double &argent,int &vie,int &killMonstre,int &xp, int &niveau,position &lieu,arme &Arme1,arme &ArmeUse,casque &CasqueUse,plastron &PlastronUse,potion &potion1,potion &potion2,potion &potion3)
{
    typedef string const adresse;

    adresse Cerf("main/boss/Cerf.txt");
    adresse Cobra("main/boss/Cobra.txt");
    adresse Scorpion("main/boss/Scorpion.txt");
    adresse Solinus("main/boss/Solinus.txt");

    adresse boss1("text/boss1.txt");
    adresse boss2("text/boss2.txt");
    adresse boss3("text/boss3.txt");
    adresse Ami("text/Ami.txt");
    adresse End("text/End.txt");
    adresse Fin("text/Fin.txt");

    monstre Monstre;

    if(lieu == 0)
    {
        if(niveau >= 3)
        {
        Monstre.nom = "Cerf Volant";
        Monstre.degats = 25;
        Monstre.vie = 150;
        Monstre.chance = 80;
        afficher(Cerf);

        combattreBoss(Monstre,vie,lieu,Arme1,ArmeUse,CasqueUse,PlastronUse,potion1,potion2,potion3);

        argent += 300;
        xp += 400;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                    Bravo! Vous avez aneanti le Cerf Volant !" << endl << endl;
        Sleep(1500);
        cout << "                                     -400xp" << endl << endl;
        Sleep(1500);
        cout << "                                     -300$" << endl;
        Sleep(2500);
        lieu = Jungle;
        afficher(boss1);
        }
        else if(niveau < 8)
        {
            system("cls");
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << "                              Niveau insuffisant !" << endl;
            cout << "                               Niveau requis: 3" << endl;
            Sleep(3000);
        }

    }
    else if(lieu == 1)
    {
        if(niveau >= 5)
        {
            Monstre.nom = "Cobra de la Jungle";
        Monstre.degats = 30;
        Monstre.vie = 200;
        Monstre.chance = 85;
        afficher(Cobra);

        combattreBoss(Monstre,vie,lieu,Arme1,ArmeUse,CasqueUse,PlastronUse,potion1,potion2,potion3);

        if(vie < 70) vie = 70;
        argent += 400;
        xp += 300;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                  Bravo! Vous avez aneanti le Cobra de la Jungle !" << endl << endl;
        Sleep(1500);
        cout << "                                       -300xp" << endl << endl;
        Sleep(1500);
        cout << "                                       -400$" << endl;
        Sleep(2500);
        lieu = Desert;
        afficher(boss2);
        }
        else if(niveau < 14)
        {
            system("cls");
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << "                              Niveau insuffisant !" << endl;
            cout << "                               Niveau requis: 5" << endl;
            Sleep(3000);
        }

    }
    else if(lieu == 2)
    {
        if(niveau >= 7)
        {
        Monstre.nom = "Scorpion Noir";
        Monstre.degats = 40;
        Monstre.vie = 250;
        Monstre.chance = 90;
        afficher(Scorpion);

        combattreBoss(Monstre,vie,lieu,Arme1,ArmeUse,CasqueUse,PlastronUse,potion1,potion2,potion3);

        if(vie < 70) vie = 70;
        argent += 500;
        xp += 200;
        actualiserXp(xp,niveau);
        killMonstre += 1;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "                   Bravo! Vous avez aneanti le Scorpion Noir !" << endl << endl;
        Sleep(1500);
        cout << "                                    -200xp" << endl << endl;
        Sleep(1500);
        cout << "                                    -500$" << endl;
        Sleep(2500);
        }
        lieu = Volcan;
        afficher(boss3);
        if(niveau < 18)
        {
            system("cls");
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << "                              Niveau insuffisant !" << endl;
            cout << "                               Niveau requis: 7" << endl;
            Sleep(3000);
        }

    }
    else if(lieu == 3)
    {
        if(niveau >= 8)
        {
        Monstre.nom = "Solinus";
        Monstre.degats = 50;
        Monstre.vie = 350;
        Monstre.chance = 95;
        afficher(Solinus);

        combattreBoss(Monstre,vie,lieu,Arme1,ArmeUse,CasqueUse,PlastronUse,potion1,potion2,potion3);

        afficher(Fin);
        Sleep(2500);

        afficher(Ami);
        Sleep(4000);
        afficher(End);
        Sleep(3000);
        exit(0);
        }
        else if(niveau < 20)
        {
            system("cls");
            cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
            cout << "                              Niveau insuffisant !" << endl;
            cout << "                               Niveau requis: 8" << endl;
            Sleep(3000);
        }

    }


}

void combattreBoss(monstre Monstre,int &vie,position &lieu,arme &Arme1,arme &ArmeUse,casque &CasqueUse,plastron &PlastronUse,potion &potion1,potion &potion2,potion &potion3)
{
    typedef string const adresse;
    adresse lancerpotion("anim/combat/lancerpotion.txt");
    adresse utiliserpotion("anim/combat/utiliserpotion.txt");

    int viefix(Monstre.vie);
    int demande(0);
    while(Monstre.vie > 0)
    {
        demande = 0;
        while(demande != 1 && demande != 2)
        {
        system("cls");
        cout << endl;
        cout << "    ================================COMBAT=================================" << endl << endl;
        cout << "                      JOUEUR:" << endl << endl;
        cout << "                  Vie: " << vie << "/100" << endl;
        cout << "                  Degat: " << ArmeUse.degats << endl;
        cout << "                  Defense: " << (CasqueUse.defense+PlastronUse.defense) << endl << endl;
        cout << "                                                 (1)Attaquer" << endl << endl;
        cout << "                                                 (2)Utiliser Potion" << endl << endl;
        cout << "                      MONSTRE : " << endl << endl;
        cout << "                  Type: " << Monstre.nom << endl;
        cout << "                  Vie: " << Monstre.vie << "/" << viefix << endl << endl;
        cout << "    -----------------------------------------------------------------------" << endl;
        cout << "     Choisissez une action:";
        cin >> demande;

        if(demande == 1)
        {
            int demande2(0);
            while(demande2 != 4)
            {
                        system("cls");
                cout << endl;
                cout << "    ================================COMBAT=================================" << endl << endl;
                cout << "                      JOUEUR:" << endl << endl;
                cout << "                  (1) Attaque Faible (75%)" << endl;
                cout << "                  (2) Attaque Moyenne (100%)" << endl;
                cout << "                  (3) Attaque Forte (125%)" << endl;
                cout << "                  (4) Retour" << endl;
                cout << "                                                 (/)Attaquer" << endl << endl;
                cout << "                                                 (/)Utiliser Potion" << endl << endl;
                cout << "                      MONSTRE : " << endl << endl;
                cout << "                  Type: " << Monstre.nom << endl;
                cout << "                  Vie: " << Monstre.vie << "/" << viefix << endl << endl;
                cout << "    -----------------------------------------------------------------------" << endl;
                cout << "     Choisissez une action:";
                cin >> demande2;

                if(demande2 == 4) demande = 0;
                if(demande2 == 1)
                {
                    int alea;
                    alea = rand()%100;
                    if(alea > 94)
                    {
                        cout << "     Echec de l'attaque !" << endl;
                        Sleep(2000);
                        demande2 = 4;
                    }
                    if(alea <= 94)
                    {
                        cout << "     Vous infligez " << (ArmeUse.degats*75/100) << " !" << endl;
                        Monstre.vie -= (ArmeUse.degats*75/100);
                        Sleep(2000);
                        demande2 = 4;
                    }
                }

                if(demande2 == 2)
                {
                    int alea;
                    alea = rand()%100;
                    if(alea > 59)
                    {
                        cout << "     Echec de l'attaque !" << endl;
                        Sleep(2000);
                        demande2 = 4;
                    }
                    if(alea <= 59)
                    {
                        cout << "     Vous infligez " << ArmeUse.degats << " !" << endl;
                        Monstre.vie -= ArmeUse.degats;
                        Sleep(2000);
                        demande2 = 4;
                    }

                }

                if(demande2 == 3)
                {
                    int alea;
                    alea = rand()%100;
                    if(alea > 39)
                    {
                        cout << "     Echec de l'attaque !" << endl;
                        Sleep(2000);
                        demande2 = 4;
                    }
                    if(alea <= 39)
                    {
                        cout << "     Vous infligez " << (ArmeUse.degats*125/100) << " !" << endl;
                        Monstre.vie -= (ArmeUse.degats*125/100);
                        Sleep(2000);
                        demande2 = 4;
                    }
                }



            }

        }
        if(demande == 2)
        {
            int demande2(0);
            while(demande2 != 4)
            {
                        system("cls");
                cout << endl;
                cout << "    ================================COMBAT=================================" << endl << endl;
                cout << "                      JOUEUR:" << endl << endl;
                cout << "                  (1) " << potion1.nom << " (val: " << potion1.soin << ")" << endl;
                cout << "                  (2) " << potion2.nom << " (val: " << potion2.soin << ")" << endl;
                cout << "                  (3) " << potion3.nom << " (val: " << potion3.soin << ")" << endl;
                cout << "                  (4) Retour" << endl;
                cout << "                                                 (/)Attaquer" << endl << endl;
                cout << "                                                 (/)Utiliser Potion" << endl << endl;
                cout << "                      MONSTRE : " << endl << endl;
                cout << "                  Type: " << Monstre.nom << endl;
                cout << "                  Vie: " << Monstre.vie << "/" << viefix << endl << endl;
                cout << "    -----------------------------------------------------------------------" << endl;
                cout << "     Choisissez une action:";
                cin >> demande2;

                if(demande2 == 4) demande = 0;
                if(demande2 == 1)
                {
                    if(potion1.soin < 0)
                    {
                        cout << "     Vous utilisez une potion et vous infligez " << -potion1.soin << " degats !" << endl;
                        Monstre.vie += potion1.soin;
                        potion1 = potion_vide;
                        Sleep(2000);
                        afficher(lancerpotion);
                        demande2 = 4;
                    }
                    if(potion1.soin > 0)
                    {
                        cout << "     Vous utilisez une potion et obtenez " << potion1.soin << " pv!" << endl;
                        vie += potion1.soin;
                        potion1 = potion_vide;
                        Sleep(2000);
                        afficher(utiliserpotion);
                        actualiserVie(vie);
                        demande2 = 4;
                    }
                }
                if(demande2 == 2)
                {
                    if(potion2.soin < 0)
                    {
                        cout << "     Vous utilisez une potion et vous infligez " << -potion2.soin << " degats !" << endl;
                        Monstre.vie += potion2.soin;
                        potion2 = potion_vide;
                        Sleep(2000);
                        afficher(lancerpotion);
                        demande2 = 4;
                    }
                    if(potion2.soin > 0)
                    {
                        cout << "     Vous utilisez une potion et obtenez " << potion2.soin << " pv!" << endl;
                        vie += potion2.soin;
                        potion2 = potion_vide;
                        Sleep(2000);
                        afficher(utiliserpotion);
                        actualiserVie(vie);
                        demande2 = 4;
                    }

                }
                if(demande2 == 3)
                {
                    if(potion3.soin < 0)
                    {
                        cout << "     Vous utilisez une potion et vous infligez " << -potion2.soin << " degats !" << endl;
                        Monstre.vie += potion3.soin;
                        potion3 = potion_vide;
                        Sleep(2000);
                        afficher(lancerpotion);
                        demande2 = 4;

                    }
                    if(potion3.soin > 0)
                    {
                        cout << "     Vous utilisez une potion et obtenez " << potion3.soin << " pv!" << endl;
                        vie += potion3.soin;
                        potion3 = potion_vide;
                        Sleep(2000);
                        afficher(utiliserpotion);
                        actualiserVie(vie);
                        demande2 = 4;
                    }
                }

            }


        }

        }
        if(Monstre.vie > 0)
        {
        system("cls");
        cout << endl;
        cout << "    ================================COMBAT=================================" << endl << endl;
        cout << "                      JOUEUR:" << endl << endl;
        cout << "                  Vie: " << vie << "/100" << endl;
        cout << "                  Degat: " << ArmeUse.degats << endl;
        cout << "                  Defense: " << (CasqueUse.defense+PlastronUse.defense) << endl << endl;
        cout << "                                                 (1)Attaquer" << endl << endl;
        cout << "                                                 (2)Utiliser Potion" << endl << endl;
        cout << "                      MONSTRE : " << endl << endl;
        cout << "                  Type: " << Monstre.nom << endl;
        cout << "                  Vie: " << Monstre.vie << "/" << viefix << endl << endl;
        cout << "    -----------------------------------------------------------------------" << endl;
        cout << "     Tour de l'ennemi:" << endl;
        Sleep(2000);
        int alea;
        alea = rand()%100;
        if(alea > Monstre.chance)
        {
            cout << "     [ENNEMI] Echec de l'attaque !" << endl;
            Sleep(1500);
        }
        if(alea <= Monstre.chance)
        {
            int alea2;
            alea2 = rand()%5;
            int att;
            att = (Monstre.degats)-(CasqueUse.defense+PlastronUse.defense);
            if(att < 0) att = 0;
            if(alea2 == 0)
            {
                att = (att*110/100);
            }
            cout << "     [ENNEMI] Vous inflige " << att << " degats !" << endl;
            Sleep(1500);
            vie -= att;
            actualiserVie(vie);
        }
        cout << "     -Fin du tour-" << endl;
        Sleep(1500);
        }

    }

}


