/*
https://github.com/Lvetto/Esame-informatica
*/

#include <iostream>
using namespace std;
#define type point  // Permette di modificare il tipo degli elementi del vettore in un solo passaggio. Sostituire "point" con il nome della struttura da utilizzare (ad es: float)

// Struct creato a scopo di esempio
struct point {
    float coords[3];
};

// Implementazione di una classe wrapper per un array di tipo "type" con supporto per numero di elementi variabile e alcune funzioni utili per domande di esame frequenti
class custom_vec {
    public:
        int len=0;  // Tiene traccia della lunghezza dell'array, inizialmente nulla
        type *arr = new type[0];    // Puntatore all'array dinamico contenente gli elementi del vettore, inizialmente vuoto

        void append(type el);   // Aggiunge un elemento alla fine dell'array dopo averne aumentato la lunghezza di 1
        void prepend(type el);  // Aggiunge un elemento all'inizio dell'array dopo averne aumentato la lunghezza di 1
        void remove(int index); // Rimuove dall'array l'elemento di indice index e diminuisce la lunghezza di 1
        void sort(double (*func)(type), bool inverted); // Riordina in-place gli elementi dell'array secondo i valori double restituiti dalla funzione passata come parametro. Mettere inverted=true per ordine decrescente
};
