#include <string>
#include <fstream>
#include <iostream>
#include "windows.h"
#include "Affichagetxt.h"

using namespace std;

void afficher(string im)
{
    string temp;
    ifstream rim(im.c_str());
    if(rim)
    {
        system("cls");
        while(getline(rim, temp))
        {
            if(temp == "next")
            {
                system("pause");
                system("cls");
            }
            if(temp == "---")
            {
                system("cls");
            }
            if(temp == "---250")
            {
                Sleep(250);
                system("cls");
            }
            if(temp == "---500")
            {
                Sleep(500);
                system("cls");
            }
            if(temp == "---1000")
            {
                Sleep(1000);
                system("cls");
            }
            if(temp == "---3000")
            {
                Sleep(3000);
                system("cls");
            }
            if(temp == "---100")
            {
                Sleep(100);
                system("cls");
            }
            if(temp != "---" and temp != "---250" and temp != "---1000" and temp != "---3000" and temp != "---100" and temp != "---500" and temp != "next")
            {
                cout << temp << endl;
            }
        }
    }
    else
    {
        cout << "ERROR:Impossible d'ouvrir le fichier: " << im << endl;
        system("pause");
    }


}
