

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#include "Tutor.h"
#include "Projecte.h"
#include "Taula_tutors.h"
#include "Taula_projectes.h"

using namespace std;

const string NO_TROBAT = "Codi inexistent";
const string TROBAT = "Codi existent";

ifstream obrir_fitxer_entrat() {
    // Pre: --
    // Post: demana nom del fitxer per teclat i retorna fitxer obert
    string nom_fitxer;
    cout << "NOM DEL FITXER:" << endl;
    cin >> nom_fitxer;
    ifstream f_in;
    f_in.open(nom_fitxer.c_str());
    return f_in;
}

Taula_tutors processar_fitxer(ifstream& f_in) {
    // Pre: f_in ha d'estar obert correctament
    // Post: retorna taula amb els tutors del fitxer f_in ordenats per codi
    Taula_tutors vec;
    Tutor t;
    t.llegir_tutor(f_in);
    while (!f_in.eof()) {
        vec.afegir(t);
        t.llegir_tutor(f_in);
    }
    return vec;
}

void mostrar_menu() {
    // Pre: --
    // Post: mostra per pantalla el menu
    cout << "OPCIONS:" << endl;
    cout << "A: ALTA PFG" << endl;
    cout << "B: BAIXA PFG" << endl;
    cout << "P: PUNTUAR PFG" << endl;
    cout << "C: COMPLETAR PFG" << endl;
    cout << "L: MOSTRAR PFGs EN CURS D'UNA ESPECIALITAT" << endl;
    cout << "T: MOSTRAR TUTORS" << endl;
    cout << "H: MOSTRAR EL MENU" << endl;
    cout << "S: FI DEL PROGRAMA" << endl;
}

char entrar_opcio() {
    // Pre: --
    // Post: retorna opcio entrada per teclat
    char opcio;
    cout << "-- OPCIO:" << endl;
    cin >> opcio;
    return opcio;
}

int main() {
    ifstream f_in = obrir_fitxer_entrat();
    if (f_in.is_open()) {
        Taula_tutors tutors;
        Taula_projectes projectes_no_completats, projectes_completats, projectes_defensats;

        tutors = processar_fitxer(f_in);
        mostrar_menu();
        char opcio = entrar_opcio();
        while (opcio != 'S') {
            if (opcio == 'A') projectes_no_completats.alta_PFG(tutors);
            else if (opcio == 'B') projectes_no_completats.baixa_PFG(tutors);
            else if (opcio == 'P') projectes_no_completats.puntuar_PFG(projectes_defensats, tutors);
            else if (opcio == 'C') projectes_defensats.completar_PFG(projectes_completats, tutors);
            else if (opcio == 'L') projectes_no_completats.mostrar_PFGs_especialitat();
            else if (opcio == 'T') tutors.mostrar_tutors();
            else if (opcio == 'H') mostrar_menu();
            cout << endl;
            opcio = entrar_opcio();
        }
    }
    else {
        cout << "FITXER NO TROBAT" << endl;
        f_in.clear();
    }
    return 0;
}