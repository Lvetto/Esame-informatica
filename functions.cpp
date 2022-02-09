#include "functions.h"
#include <cmath>
#include <iostream>
using namespace std;

template <class type>
void custom_vec<type>::append(type el) {
    len++;  // Traccia l'aumento di dimensioni dell'array
    type *arr2 = new type[len]; // Dichiarazione di un array temporaneo
    for (int i=0; i<len-1; i++)     // Popolazione array con gli elementi contenuti nel vettore precedente
        arr2[i] = arr[i];
    arr2[len-1] = el;   // Aggiunta ultimo elemento (argomento della funzione)
    delete [] arr;  // Libera la memoria dalla versione precedente dell'array. Può provocare problemi in alcuni casi???
    this->arr = arr2;   // Assegna il nuovo array al puntatore this.arr
}

template <class type>
void custom_vec<type>::prepend(type el) {
    len++;  // Traccia l'aumento di dimensioni dell'array
    type *arr2 = new type[len]; // Dichiarazione di un array temporaneo
    arr2[0] = el;   // Aggiunta primo elemento (argomento della funzione)
    for (int i=1; i<len; i++)   // Popolazione array con gli elementi contenuti nel vettore precedente
        arr2[i] = arr[i-1];
    delete [] arr;  // Libera la memoria dalla versione precedente dell'array. Può provocare problemi in alcuni casi???
    this->arr = arr2;   // Assegna il nuovo array al puntatore this.arr
}

template <class type>
void custom_vec<type>::remove(int index) {
    type *arr2 = new type[len-1];   // Dichiarazione di un array temporaneo
    int count = 0;  // Conta il numero di elementi effettivamente inseriti nell'array
    for (int i=0; i<len; i++) { // Popolazione array con gli elementi precedentemente presenti saltando l'elemento di indice index
        if (i != index) {
        arr2[count] = arr[i];
        count++;
        }
    }
    delete [] arr;  // Libera la memoria dalla versione precedente dell'array. Può provocare problemi in alcuni casi???
    len--;   // Traccia la diminuzione di dimensioni dell'array
    this->arr = arr2;   // Assegna il nuovo array al puntatore this.arr
}

template <class type>
void custom_vec<type>::sort(double (*func)(type), bool inverted) {      // Prende come argomento un puntatore a una funzione che prende un singolo argomento di tipo type e resituisce un double
    // Implementazione di simple-sort secondo i valori restiuiti da func
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            if ((func(arr[i]) > func(arr[j]) and !inverted) or (func(arr[i]) < func(arr[j]) and inverted)) {    // Se inverted=false la seconda condizione è sempre falsa e l'ordine è crescente e viceversa
                type t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
             }
        }
    }
 }
 
template <class type>
custom_vec<type> custom_vec<type>::filter(bool (*cond)(type)) { // Prende come argomento una funzione di tipo bool e restituisce un custom_vec<type> contenente tutti gli elementi per cui cond restiuisce vero
    custom_vec<type> out;   // Inizializza elemento da restituire
    for (int i=0; i<this->len; i++) {
        if (cond(this->arr[i])) // Aggiunge solo gli elementi che verificano la funzione cond
            out.append(this->arr[i]);
    }
    return out;
}

double Fc(point p) {
    return pow(p.w, 2) * sqrt(pow(p.x, 2)+pow(p.y, 2));
}

template class custom_vec<point>;   // Instanzializzazione classe template per il tipo point. Necessario per compilare correttamente la classe da un file separato dal main e dal .h
