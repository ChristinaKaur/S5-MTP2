#ifndef TAULA_TUTORS_H
#define TAULA_TUTORS_H

#include "Tutor.h"
#include "Projecte.h"

#include <iostream>

using namespace std;

class Taula_tutors
{
public:
	// CONSTRUCTORS
	Taula_tutors();
	// Pre: --
	// Post: taula tutors inicialitzada

	// CONSULTORS
	void mostrar_tutors() const;
	// Pre: cert
	// Post: mostrar vector tutors per ordre

	int pos_tutor(const Tutor& t) const;
	//Pre: 0<=vec.n<=MAX, vec.t[0..vec.n-1] ordenat creixentment
	//Post: retorna la posició on s’ha trobat t a vec.t[0..vec.n-1]
	
	Tutor retorna_tutor(const int pos) const;
	// Pre: --
	// Post: retorna el tutor en la posició pos de la taula de tutors

	// MODIFICADORS
	void afegir(const Tutor& tutor);
	// Pre: tutor ha d'estar omplert correctament
	// Post: retorna vec amb tutor afegit ordenadament per codi

	void actualitza_dades(Projecte& p, const int num1, const int num2);
	// Pre: projecte creat correctament
	// Post: actualitza les dades de p.a_tutor depenent dels aparetres entrats

private:
	static const int NO_TROBAT = -1;
	static const int MAX_T = 1000;
	Tutor a_vec[MAX_T];
	int a_n;
};

#endif // TAULA_TUTORS_H



