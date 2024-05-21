#ifndef TUTOR_H
#define TUTOR_H

#include <iostream>

using namespace std;

class Tutor
{
public:
    // CONSTRUCTORS
    Tutor();
    // Pre: --
    // Post: tutor inicialitzat

    // CONSULTORS
    void mostrar_tutor() const;
    // Pre: cert
    // Post: mostrar informació del tutor
    
    bool tutor_indicat(const Tutor& t, const Tutor& tutor_a_assignar, const string& especialitat) const;
    // Pre: cert
    // Post: retorna cert si el tutor te la mateixa especialitat que el projecte amb menys projectes assignats (en cas d'empat, el de menor codi – sempre hi haurà tutors disponibles)

    string codi_tutor() const;
    // Pre: --
    // Post: retornar el codi_tutor del tutor actual

    string cognom_i_nom() const;
    // Pre: --
    // Post: retornar el cognom_i_nom del tutor actual
    
    // MODIFICADORS
    void llegir_tutor(ifstream& f_in);
    // Pre: f_in ha d'estar obert correctament
    // Post: retorna tutor llegit de f_in
    
    void llegir_codi();
    // Pre: --
    // Post: retorna codi tutor entrat per teclat

    void actualitza(const int num1, const int num2);
    // Pre: --
    // Post: 

private:
    string a_codi_tutor;
    string a_cognom_i_nom;
    string a_especialitat;
    int a_n_projectes_per_curs;
    int a_n_projectes_defensats;
};
#endif // TUTOR_H
