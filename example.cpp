/*
Questo file è fornito come esempio per l'utilizzo della classe vettore e delle sue funzioni.
*/

#include "functions.h"
#include <fstream>

int main() {
    fstream file;
    file.open("punti.dat", ios::in);
    if (!file.good()) throw runtime_error("Impossibile aprire il file");

    custom_vec<point> punti; 
    while (true) {
        if (file.eof()) break;
        point t;
        file >> t.x >> t.y >> t.w >> t.m;
        punti.append(t);
    }

    cout << "Numero di punti: " << punti.len << endl;
    for (int i=0; i<punti.len; i++)
        cout << "Punto " << i+1 << ": " << punti.arr[i].x << " " << punti.arr[i].y << " " << punti.arr[i].w << " " << punti.arr[i].m << endl;

    punti.sort(&Fc, false);
    cout << "\n\n";
    for (int i=0; i<punti.len; i++)
        cout << "Punto " << i+1 << ": " << " " << punti.arr[i].w << " " << punti.arr[i].m << " " << Fc(punti.arr[i]) << endl;

    double Fm = 0;
    for (int i=0; i<punti.len; i++)
        Fm += (1./punti.len) * Fc(punti.arr[i]);
    cout << "\n\nLa forza media è: " << Fm << endl;

    custom_vec<point> punti_g;
    custom_vec<point> punti_b;
    for (int i=0; i<punti.len; i++) {
        if (Fc(punti.arr[i]) < Fm*1.2)
            punti_g.append(punti.arr[i]);
        else
            punti_b.append(punti.arr[i]);
    }
    cout << "\n\n" << "Numero di punti esclusi: " << punti_b.len << endl;
    for (int i=0; i<punti_b.len; i++)
        cout << "Punto " << i+1 << ": " << " " << punti_b.arr[i].w << " " << punti_b.arr[i].m << " " << Fc(punti_b.arr[i]) << endl;

    return 0;
}

