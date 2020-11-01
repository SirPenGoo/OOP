// Skat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

enum class Farbe {
    Schellen,
    Herz,
    Laub,
    Eicheln
};

enum class Zahl {
    Sieben,
    Acht,
    Neun,
    Unter,
    Ober,
    König,
    Zehn,
    Sau
};

struct KARTE {
    Farbe farbe;
    Zahl zahl;
};

array<shared_ptr<KARTE>, 32> fillDeck(){
    int index = 0;
    array<shared_ptr<KARTE>, 32> arr;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 7; j++) {
            auto card = make_shared<KARTE>();
            card->farbe = (Farbe)i;
            card->zahl = (Zahl)j;
            arr[index] = card;
            index++;
        }
    }
    return arr;
}

void coutZahl(shared_ptr<KARTE> k) {
    switch (k->zahl) {
    case Zahl::Sieben:
        cout << "Zahl: Sieben" << endl;
        break;
    case Zahl::Acht:
        cout << "Zahl: Acht" << endl;
        break;
    case Zahl::Neun:
        cout << "Zahl: Neun" << endl;
        break;
    case Zahl::Unter:
        cout << "Zahl: Unter" << endl;
        break;
    case Zahl::Ober:
        cout << "Zahl: Ober" << endl;
        break;
    case Zahl::König:
        cout << "Zahl: König" << endl;
        break;
    case Zahl::Zehn:
        cout << "Zahl: Zehn" << endl;
        break;
    case Zahl::Sau:
        cout << "Zahl: Sau" << endl;
        break;
    }
}

void coutFarbe(shared_ptr<KARTE> k) {
    switch (k->farbe) {
    case Farbe::Schellen:
        cout << "Farbe: Schellen ";
        coutZahl(k);
        break;
    case Farbe::Herz:
        cout << "Farbe: Herz ";
        coutZahl(k);
        break;
    case Farbe::Laub:
        cout << "Farbe: Laub ";
        coutZahl(k);
        break;
    case Farbe::Eicheln:
        cout << "Farbe: Eicheln ";
        coutZahl(k);
        break;
    }
}

int main()
{
    array<shared_ptr<KARTE>, 32> arr = fillDeck();
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    
    cout << "Sortiert:" << endl;
    for (int i = 0; i < 32; i++) {
        coutFarbe(arr[i]);
    }

    shuffle(arr.begin(), arr.end(), default_random_engine(seed));
    
    cout << "Gemischt:" << endl;
    for (int i = 0; i < 32; i++) {
        coutFarbe(arr[i]);
    }
}