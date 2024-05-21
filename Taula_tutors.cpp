#include <iostream>

#include "Taula_tutors.h"

using namespace std;

// CONSTRUCTORS
Taula_tutors::Taula_tutors() {
    // Pre: --
    // Post: taula tutors inicialitzada
    a_n = 0;
}

// CONSULTORS 
void Taula_tutors::mostrar_tutors() const {
    // Pre: cert
    // Post: mostrar vector tutors per ordre
    for (int i = 0; i < a_n; i++)
        a_vec[i].mostrar_tutor();
}

int Taula_tutors::pos_tutor(const Tutor& t) const {
    //Pre: 0<=vec.n<=MAX, vec.t[0..vec.n-1] ordenat creixentment
    //Post: retorna la posició on s’ha trobat t a vec.t[0..vec.n-1]
    int mig, esq = 0, dreta = a_n - 1;
    bool trobat = false;
    while (!trobat and esq <= dreta) {
        mig = (esq + dreta) / 2;
        if (t.codi_tutor() < a_vec[mig].codi_tutor()) dreta = mig - 1;
        else if (a_vec[mig].codi_tutor() < t.codi_tutor()) esq = mig + 1;
        else trobat = true;
    }
    if (trobat) return mig;
    else return esq;
}

Tutor Taula_tutors::retorna_tutor(const int pos) const {
    // Pre: --
    // Post: retorna el tutor en la posició pos de la taula de tutors
    return a_vec[pos];
}

// MODIFICADORS
void Taula_tutors::afegir(const Tutor& tutor) {
    // Pre: tutor ha d'estar omplert correctament
    // Post: retorna vec amb tutor afegit ordenadament per codi
    int pos = pos_tutor(tutor);
    for (int i = a_n - 1; i >= pos; i--)
        a_vec[i + 1] = a_vec[i];
    a_vec[pos] = tutor;
    a_n++;
}

void Taula_tutors::actualitza_dades(Projecte& p, const int num1, const int num2) {
    // Pre: projecte creat correctament
    // Post: actualitza les dades de p.a_tutor depenent dels aparetres entrats
    int pos = pos_tutor(p.tutor());
    a_vec[pos].actualitza(num1, num2);
}

