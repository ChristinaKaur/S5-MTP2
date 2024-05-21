#ifndef PROJECTE_H
#define PROJECTE_H

#include <iostream>

#include "Tutor.h"

using namespace std;

class Projecte
{
public:
    // CONSTRUCTORS
    Projecte();
    // Pre: --
    // Post: projecte inicialitzat
    
    // CONSULTORS
    void mostrar_projecte(const int& num) const;
    // Pre: cert
    // Post: mostrar per pantalla la informacó del projecte
        
    string codi_alumne() const;
    // Pre: --
    // Post: retorna a_codi_alumne

    Tutor tutor() const;
    // Pre: --
    // Post: retorna a_tutor

    string especialitat() const;
    // Pre: --
    // Post: retorna a_especialitat

    bool operator <(const Projecte& p) const;
    // Pre: --
    // Post: retorna cert si a_titol < p.a_titol, fals altrament

    // MODIFICADORS
    void llegir_projecte(const string& codi_alumne);
    // Pre: codi_alumne vàlid
    // Post: retorna projecte actual amb dades llegides de teclat i assignades

    void assignar_tutor(const Tutor& t);
    // Pre: tutor valid
    // Post: assigna tutor t al projecte actual

    void entrar_nota();
    // Pre: --
    // Post: a_nota és nota entrada per teclat

private:
    string a_codi_alumne;
    string a_cognom_i_nom;
    string a_titol;
    string a_especialitat;
    Tutor a_tutor;
    int a_nota;
};
#endif // PROJECTE_H
