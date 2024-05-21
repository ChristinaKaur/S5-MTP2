#include <iostream>
#include <limits>
#include <string>

#include "Taula_projectes.h"
#include "Tutor.h"

using namespace std;

// CONSTRUCTORS
Taula_projectes::Taula_projectes() {
    // Pre: --
    // Post: taula de projectes inicialitzada
    a_n = 0;
}

// CONSULTORS
void Taula_projectes::mostrar_projectes(const int& num) const {
    // Pre: cert
    // Post: mostrar vector projectes per ordre
    for (int i = 0; i < a_n; i++)
        a_vec[i].mostrar_projecte(num);
}

Projecte Taula_projectes::retorna_projecte(const int pos) const {
    // Pre: --
    // Post: retorna el projecte en la posició pos de la taula de projectes
    return a_vec[pos];
}

// MODIFICADORS
void Taula_projectes::afegir(const Projecte& projecte, int pos) {
    // Pre: projecte ha d'estar omplert correctament
    // Post: retorna a_vec amb tutor afegit en la posició pos
    for (int i = a_n - 1; i >= pos; i--)
        a_vec[i + 1] = a_vec[i];
    a_vec[pos] = projecte;
    a_n++;
}

void Taula_projectes::eliminar(const int pos) {
    // Pre: 0<=pos<vec.n<=MAX
    // Post: retorna projectes sense el projecte de la posició pos mantenint l’ordre dels altres elements
    for (int i = pos; i < a_n - 1; i++)
        a_vec[i] = a_vec[i + 1];
    a_n--;
}

void Taula_projectes::alta_PFG(Taula_tutors& t) {
    // Pre: cert
    // Post: dona d'alta un projecte entrat per teclat si no existeix ja, altrament s’indica que ja existeix
    string codi_alumne = demanar_codi();
    bool trobat = false;
    int pos = existeix_PFG(codi_alumne, trobat);
    if (!trobat) {
        Projecte p;
        p.llegir_projecte(codi_alumne);
        
        char opcio;
        cout << "Te tutor (s/n):" << endl;
        cin >> opcio;
        if (opcio == 's') {
            Tutor a_tutor;
            a_tutor.llegir_codi();
            int pos1 = t.pos_tutor(a_tutor);
            p.assignar_tutor(t.retorna_tutor(pos1));
        }
        
        afegir(p, pos);
        cout << "Nou PFG: ";
        a_vec[pos].mostrar_projecte(0);

        t.actualitza_dades(a_vec[pos], 0, 0);
    }
    else
        cout << TROBAT << endl;
}

void Taula_projectes::baixa_PFG(Taula_tutors& tutors) {
    // Pre: cert
    // Post: si el PFG existeix es retorna el vector projectes amb un PFG eliminat i s'elimina un PFg en curs del seu tutor, si no existeix s'informa
    string codi_alumne = demanar_codi();
    bool trobat = false;
    int pos_PFG = existeix_PFG(codi_alumne, trobat);
    if (trobat) {
        tutors.actualitza_dades(a_vec[pos_PFG], 0, 1);
        eliminar(pos_PFG);
        cout << "PFG eliminat" << endl;
    }
    else
        cout << NO_TROBAT << endl;
}

void Taula_projectes::puntuar_PFG(Taula_projectes& p_defensats, Taula_tutors& tutors) {
    // Pre: cert
    // Post: entrar codi d'alumne per teclat, si existeix se li posa nota i s'actualitza el vector de tutors, altrament s'indica
    string codi_alumne = demanar_codi();
    bool trobat = false;
    int pos1 = existeix_PFG(codi_alumne, trobat);
    if (trobat) {
        a_vec[pos1].entrar_nota();
        
        int pos2 = p_defensats.existeix_PFG(codi_alumne, trobat);
        p_defensats.afegir(a_vec[pos1], pos2);
        eliminar(pos1);

        tutors.actualitza_dades(p_defensats.a_vec[pos2], 1, 0);
        tutors.actualitza_dades(p_defensats.a_vec[pos2], 0, 1);
    }
    else
        cout << NO_TROBAT << endl;
}

void Taula_projectes::completar_PFG(Taula_projectes& p_completats, Taula_tutors& t) {
    // Pre: cert
    // Post: es passen tots els projectes de p_defensats a p_completats i es mostren per pantalla
    for (int i = 0; i < p_completats.a_n; i++) t.actualitza_dades(p_completats.a_vec[i], 1, 1);

    p_completats = (*this);
    p_completats.a_n = a_n;
    a_n = 0;

    cout << "S'han completat els projectes defensats" << endl;
    p_completats.mostrar_projectes(1);
}

void Taula_projectes::mostrar_PFGs_especialitat() {
    // Pre: cert
    // Post: es mostren per pantalla els projectes d'una especialitat en concret, entrada per pantalla, ordenats per títol
    string especialitat;
    cout << "ESPECIALITAT:" << endl;
    cin.ignore(100, '\n');
    getline(cin, especialitat);

    ordenar_per_titol();
    for (int i = 0; i < a_n; i++)
        if (a_vec[i].especialitat() == especialitat)
            a_vec[i].mostrar_projecte(0);
}

void Taula_projectes::operator= (Taula_projectes& t) {
    // Pre: t = T;
    // Pos: t = taula actual
    for (int i = 0; i < a_n; i++) {
        t.a_vec[i] = a_vec[i];
    }
    t.a_n = a_n;
}

// PRIVATE
int Taula_projectes::existeix_PFG(const string& codi_alumne, bool& trobat) {
    //Pre: 0<=vec.n<=MAX, vec.t[0..vec.n-1] ordenat creixentment
    //Post: retorna la posició on s'hauria d'incerir si codi_alumne no existeix en vec o -1 si ja existeix
    int mig, esq = 0, dreta = a_n - 1;
    trobat = false;
    while (!trobat and esq <= dreta) {
        mig = (esq + dreta) / 2;
        if (codi_alumne < a_vec[mig].codi_alumne()) dreta = mig - 1;
        else if (codi_alumne > a_vec[mig].codi_alumne()) esq = mig + 1;
        else trobat = true;
    }
    if (trobat) return mig;
    else return esq;
}

string Taula_projectes::demanar_codi() {
    // Pre: cert
    // Post: retorna codi entrat per teclat
    string codi_alumne;
    cout << "Codi de l'alumne:" << endl;
    cin.ignore(100, '\n');
    getline(cin, codi_alumne);
    return codi_alumne;
}

int Taula_projectes::posicioMin(int i) {
    // Pre: 0<=a_n<=MAX, 0<=i<a_n
    // Post: retorna posició del mínim de a_vec[i..a_n-1]
    int pm = i;
    for (int j = i + 1; j < a_n; j++) {
        if (a_vec[j] < a_vec[pm]) pm = j;
    }
    return pm;
}

void Taula_projectes::intercanvi(Projecte& a, Projecte& b) {
    // Pre: a = A i b = B
    // Post: a = B i b = A
    Projecte aux = a;
    a = b;
    b = aux;
}

void Taula_projectes::ordenar_per_titol() {
    // Pre: 0<=a_n<=MAX
    // Post: a_vec[0..p.n-1] conté els elements inicials en ordre creixent
    for (int i = 0; i < a_n - 1; i++) {
        int pm = posicioMin(i);
            intercanvi(a_vec[i], a_vec[pm]);
    }
}