#include "functions.h"
#include <cmath>

/*
Programma esempio scritto con la classe custom_vec
*/

// Distanza dall'origine, la funzione deve prendere un solo argomento di tipo type
double distance(point p) {
    return sqrt(pow(p.coords[0], 2) + pow(p.coords[0], 2) + pow(p.coords[0], 2));
}

int main() {
    // Dichiarazione istanza di custom_vec
    custom_vec a;

    // Inizializzazione vettore con valori pseudo-casuali
    float b = 1.18;
    for (int i=0; i<100; i++) {
        point c;
        c.coords[0] = b*3*i+7;
        c.coords[1] = b*7*i+19;
        c.coords[2] = b*4*i+12;
        a.append(c);
    }

    // Verifica che custom_vec.append() funzioni
    for (int i=0; i<a.len; i++) cout << a.arr[i].coords[0] << " ";
    cout << "\n";

    // Verifica che custom_vec.remove() funzioni
    for (int i=0; i<a.len; i+=2) a.remove(i);
    cout << "\n";
    for (int i=0; i<a.len; i++) cout << a.arr[i].coords[0] << " ";
    cout << "\n";

    // Verfica che custom_vec.sort() funzioni
    a.sort(&distance, false);   // &distance è il puntatore alla funzione distance
    cout << "\n";
    for (int i=0; i<a.len; i++) cout << distance(a.arr[i]) << " ";
    cout << "\n";

    return 0;
}
