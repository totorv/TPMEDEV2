//Seuillage et différence
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//différence image PGM
int dif(Vector<int> Mat1, Vector<int> Mat2) {
	int somme;
	int taille = size(Mat1);
	for (int i=0;i<taille; i++){
		for(int k=0;k<taille;k++){
				somme += abs(Mat1[i,k] - Mat2[i, k]);
			}
		}
	return somme;
}

void seuillage(int seuil, Vector<int> Mat) {
	int somme;
	int taille = size(Mat);
	for (int i = 0; i<taille; i++) {
		for (int k = 0; k<taille; k++) {
			if (Mat[i,k] < seuil) {
				Mat[i, k]= 0;
			}
			else {
				Mat[i, k] = 256;
			}
		}
	}
}
