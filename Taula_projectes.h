#ifndef TAULA_PROJECTES_H
#define TAULA_PROJECTES_H

#include "Projecte.h";
#include "Taula_tutors.h";

#include <iostream>

using namespace std;

class Taula_projectes
{
public:
	// CONSTRUCTORS
	Taula_projectes();
	// Pre: --
	// Post: taula de projectes inicialitzada
	
	// CONSULTORS
	void mostrar_projectes(const int& num) const;
	// Pre: cert
	// Post: mostrar vector projectes per ordre

	Projecte retorna_projecte(const int pos) const;
	// Pre: --
	// Post: retorna el projecte en la posició pos de la taula de projectes

	// MODIFICADORS
	void afegir(const Projecte& projecte, int pos);
	// Pre: projecte ha d'estar omplert correctament
	// Post: retorna a_vec amb tutor afegit en la posició pos

	void eliminar(const int pos);
	// Pre: 0<=pos<vec.n<=MAX
	// Post: retorna projectes sense el projecte de la posició pos mantenint l’ordre dels altres elements

	void alta_PFG(Taula_tutors& t);
	// Pre: cert
	// Post: dona d'alta un projecte entrat per teclat si no existeix ja, altrament s’indica que ja existeix

	void baixa_PFG(Taula_tutors& tutors);
	// Pre: cert
	// Post: si el PFG existeix es retorna el vector projectes amb un PFG eliminat i s'elimina un PFg en curs del seu tutor, si no existeix s'informa

	void puntuar_PFG(Taula_projectes& p_defensats, Taula_tutors& tutors);
	// Pre: cert
	// Post: entrar codi d'alumne per teclat, si existeix se li posa nota i s'actualitza el vector de tutors, altrament s'indica

	void completar_PFG(Taula_projectes& p_completats, Taula_tutors& t);
	// Pre: cert
	// Post: es passen tots els projectes de p_defensats a p_completats i es mostren per pantalla

	void mostrar_PFGs_especialitat();
	// Pre: cert
	// Post: es mostren per pantalla els projectes d'una especialitat en concret, entrada per pantalla, ordenats per títol

	void operator= (Taula_projectes& t);
	// Pre: t = T;
	// Pos: t = taula actual

private:
	const string NO_TROBAT = "Codi inexistent";
	const string TROBAT = "Codi existent";
	static const int MAX_P = 100;
	Projecte a_vec[MAX_P];
	int a_n;

	int existeix_PFG(const string& codi_alumne, bool& trobat);
	//Pre: 0<=vec.n<=MAX, vec.t[0..vec.n-1] ordenat creixentment
	//Post: retorna la posició on s'hauria d'incerir si codi_alumne no existeix en vec o -1 si ja existeix

	string demanar_codi();
	// Pre: cert
	// Post: retorna codi entrat per teclat

	void intercanvi(Projecte& a, Projecte& b);
	// Pre: a = A i b = B
	// Post: a = B i b = A

	int posicioMin(int i);
	// Pre: 0<=a_n<=MAX, 0<=i<a_n
	// Post: retorna posició del mínim de a_vec[i..a_n-1]

	
	void ordenar_per_titol();
	// Pre: 0<=a_n<=MAX
	// Post: a_vec[0..p.n-1] conté els elements inicials en ordre creixent

};
#endif // TAULA_PROJECTES_H
