#include <iostream>
#include <string>
#include <fstream>

#include "Tutor.h"

using namespace std;

// CONSTRUCTORS
Tutor::Tutor() {
    // Pre: --
    // Post: tutor inicialitzat
    a_codi_tutor  = "";
    a_cognom_i_nom = "";
    a_especialitat = "";
    a_n_projectes_per_curs = 0;
    a_n_projectes_defensats = 0;
}

// CONSULTORS
void Tutor::mostrar_tutor() const {
    // Pre: cert
    // Post: mostrar informació del turot
    cout << a_cognom_i_nom << " (" << a_codi_tutor << "), " << a_especialitat << " [" << a_n_projectes_per_curs << ":" << a_n_projectes_defensats << "]" << endl;
}

bool Tutor::tutor_indicat(const Tutor& t, const Tutor& tutor_a_assignar, const string& especialitat) const {
    // Pre: cert
    // Post: retorna cert si el tutor te la mateixa especialitat que el projecte amb menys projectes assignats (en cas d'empat, el de menor codi – sempre hi haurà tutors disponibles)
    return ((a_especialitat == especialitat) and ((a_n_projectes_per_curs < tutor_a_assignar.a_n_projectes_per_curs) or ((a_n_projectes_per_curs == tutor_a_assignar.a_n_projectes_per_curs) and (a_codi_tutor < tutor_a_assignar.a_codi_tutor))));
}

string Tutor::codi_tutor() const {
    // Pre: --
    // Post: retornar el codi_tutor del tutor actual
    return a_codi_tutor;
}

string Tutor::cognom_i_nom() const {
    // Pre: --
    // Post: retornar el cognom_i_nom del tutor actual
    return a_cognom_i_nom;
}

// MODIFICADORS
void Tutor::llegir_tutor(ifstream& f_in) {
    // Pre: f_in ha d'estar obert correctament
    // Post: retorna tutor llegit de f_in
    string codi_tutor,caqueta;
    getline(f_in, codi_tutor);
    //f_in.ignore(100, '/n');
    if (!f_in.eof()) { 
        getline(f_in, a_cognom_i_nom);
        //f_in.ignore(100, '/n');
        getline(f_in, a_especialitat);
        //f_in.ignore(100, '/n');
        a_codi_tutor = codi_tutor;
    }
}

void Tutor::llegir_codi() {
    // Pre: --
    // Post: retorna codi tutor entrat per teclat
    cout << "Codi tutor:" << endl;
    cin >> a_codi_tutor;
}

void Tutor::actualitza(const int num1,const int num2) {
    // Pre: --
    // Post: si objecte és "PFG_per_curs" modifica a_n_projectes_per_curs depenent de num, si objecte és "PFG_defensats" modifica a_n_projectes_defensats depenent de num
    if (num1 == 0) {
        if (num2 == 0) a_n_projectes_per_curs++;
        else if (num2 == 1) a_n_projectes_per_curs--;
    }
    else if (num1 == 1) {
        if (num2 == 0) a_n_projectes_defensats++;
        else if (num2 == 1) a_n_projectes_defensats--;
    }
}