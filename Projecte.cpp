#include <iostream>
#include <limits>
#include <string>

#include "Projecte.h"

using namespace std;

// CONSTRUCTORS
Projecte::Projecte() {
    // Pre: --
    // Post: projecte inicialitzat
    a_codi_alumne = "";
    a_cognom_i_nom = "";
    a_titol = "";
    a_especialitat = "";
    a_nota = 0;
}

// CONSULTORS
void Projecte::mostrar_projecte(const int& num) const {
    // Pre: cert
    // Post: mostrar per pantalla la informacó del projecte
    cout << a_titol << " (" << a_especialitat << "), " << a_cognom_i_nom << " (" << a_codi_alumne << "), codi tutor: " << a_tutor.codi_tutor();
    if (num == 1)
        cout << " nota:" << a_nota;
    cout << endl;
}

string Projecte::codi_alumne() const {
    // Pre: --
    // Post: retorna a_codi_alumne
    return a_codi_alumne;
}

Tutor Projecte::tutor() const {
    // Pre: --
    // Post: retorna a_tutor
    return a_tutor;
}

string Projecte::especialitat() const {
    // Pre: --
    // Post: retorna a_especialitat
    return a_especialitat;
}

bool Projecte::operator <(const Projecte& p) const {
    // Pre: --
    // Post: retorna cert si a_titol < p.a_titol, fals altrament
    return a_titol < p.a_titol;
}

// MODIFICADORS
void Projecte::llegir_projecte(const string& codi_alumne) {
    // Pre: codi_alumne vàlid
    // Post: retorna projecte actual amb dades llegides de teclat i assignades
    a_codi_alumne = codi_alumne;
    cout << "Cognoms, nom:" << endl;
    getline(cin, a_cognom_i_nom);

    cout << "Titol:" << endl;
    getline(cin, a_titol); 

    cout << "Especialitat:" << endl;
    getline(cin, a_especialitat); 
}

void Projecte::assignar_tutor(const Tutor& t) {
    // Pre: tutor valid
    // Post: assigna tutor t al projecte actual
    a_tutor = t;
}

void Projecte::entrar_nota() {
    // Pre: --
    // Post: a_nota és nota entrada per teclat
    cout << "Nota obtinguda a la defensa:" << endl;
    cin >> a_nota;
}