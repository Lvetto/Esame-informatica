/*
https://github.com/Lvetto/Esame-informatica
*/
#include <cmath>
#include <iostream>
using namespace std;

struct point {
    float x,y,w,m;
};

// Implementazione di una classe wrapper per un array di tipo "type" con supporto per numero di elementi variabile e alcune funzioni utili per domande di esame frequenti
template <class type>   // Permette di creare istanze della classe per tipi diversi
class custom_vec {
    public:
        int len=0;  // Tiene traccia della lunghezza dell'array, inizialmente nulla
        type *arr = new type[0];    // Puntatore all'array dinamico contenente gli elementi del vettore, inizialmente vuoto

        custom_vec();   // Costruttore
        ~custom_vec(); // Distruttore
        void append(type el);   // Aggiunge un elemento alla fine dell'array dopo averne aumentato la lunghezza di 1
        void prepend(type el);  // Aggiunge un elemento all'inizio dell'array dopo averne aumentato la lunghezza di 1
        void remove(int index); // Rimuove dall'array l'elemento di indice index e diminuisce la lunghezza di 1
        void sort(double (*func)(type), bool inverted); // Riordina in-place gli elementi dell'array secondo i valori double restituiti dalla funzione passata come parametro. Mettere inverted=true per ordine decrescente
        custom_vec<type> filter(bool (*cond)(type));    // Restituisce un istanza di custom_vec<type> contenente gli elementi che verificano una condizione definita dalla funzione filter
};

double Fc(point p); // Per "esempio.cpp"
