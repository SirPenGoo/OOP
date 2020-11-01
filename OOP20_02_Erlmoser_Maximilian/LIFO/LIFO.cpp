/*==========================================================
|	Assignment:		OOP_HUE02
|	File:			LIFO.cpp
|	Author:			Maximilian Erlmoser
|	University:		FH Salzburg
|	Semester:		ITS-B WS20/21
|	Date:			01.11.2020
|-----------------------------------------
|	Description:	Realisierung eines Lagers
|					Ein Lager hat mehrere Fächer, die wie
|                   die wie ein Stack funktionieren und
|					beliebig viele Materialien halten
*=========================================================*/

#include <iostream>
#include <string>
#include <stack>
#include <array>
#include <vector>

using namespace std;

struct Material {
    int ID;
    int Artikelnummer;
    string Bezeichnung;
};

auto Einlagern(vector<shared_ptr<Material>> fach, int id, int artNo, string bez) {
    auto mat = make_shared<Material>();
    mat->ID = id;
    mat->Artikelnummer = artNo;
    mat->Bezeichnung = bez;

    fach.push_back(mat);
    return fach;
}

auto Auslagern(vector<shared_ptr<Material>> fach) {
    fach.pop_back();
    return fach;
}

void coutLager(array<vector<shared_ptr<Material>>, 3> lager) {
    for (int i = 0; i < lager.size(); i++) {
        cout << endl << "Lager No. " << i << endl;
        for (int j = 0; j < lager[i].size(); j++) {
            cout << "Artikel No. " << lager[i][j]->Artikelnummer << endl;
        }
    }
}

int main()
{
    array<vector<shared_ptr<Material>>, 3> lager;
    int id = 0;
    int mat = 0;
    string bez = "a";

    for (int i = 0; i < 3; i++) {
        lager[i] = Einlagern(lager[i], id, mat, bez);
        id++;
        mat++;
        bez = bez.append(bez);
        lager[i] = Einlagern(lager[i], id, mat, bez);
        id++;
        mat++;
        bez = bez.append(bez);
        lager[i] = Einlagern(lager[i], id, mat, bez);
        id++;
        mat++;
        bez = "a";
    }

    coutLager(lager);

}