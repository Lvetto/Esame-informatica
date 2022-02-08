#include "functions.h"

void custom_vec::append(type el) {
    len++;  // Traccia l'aumento di dimensioni dell'array
    type *arr2 = new type[len]; // Dichiarazione di un array temporaneo
    for (int i=0; i<len-1; i++)     // Popolazione array con gli elementi contenuti nel vettore precedente
        arr2[i] = arr[i];
    arr2[len-1] = el;   // Aggiunta ultimo elemento (argomento della funzione)
    delete [] arr;  // Libera la memoria dalla versione precedente dell'array. Può provocare problemi in alcuni casi???
    this->arr = arr2;   // Assegna il nuovo array al puntatore this.arr
}

void custom_vec::prepend(type el) {
    len++;  // Traccia l'aumento di dimensioni dell'array
    type *arr2 = new type[len]; // Dichiarazione di un array temporaneo
    arr2[0] = el;   // Aggiunta primo elemento (argomento della funzione)
    for (int i=1; i<len; i++)   // Popolazione array con gli elementi contenuti nel vettore precedente
        arr2[i] = arr[i-1];
    delete [] arr;  // Libera la memoria dalla versione precedente dell'array. Può provocare problemi in alcuni casi???
    this->arr = arr2;   // Assegna il nuovo array al puntatore this.arr
}

void custom_vec::remove(int index) {
    type *arr2 = new type[len-1];   // Dichiarazione di un array temporaneo
    int count = 0;  // Conta il numero di elementi effettivamente inseriti nell'array
    for (int i=0; i<len; i++) { // Popolazione array con gli elementi precedentemente presenti saltando l'elemento di indice i
        if (i != index) {
        arr2[count] = arr[i];
        count++;
        }
    }
    delete [] arr;  // Libera la memoria dalla versione precedente dell'array. Può provocare problemi in alcuni casi???
    len--;   // Traccia la diminuzione di dimensioni dell'array
    this->arr = arr2;   // Assegna il nuovo array al puntatore this.arr
}

void custom_vec::sort(double (*func)(type), bool inverted=false) {      // Prende come argomento un puntatore a una funzione che prende un singolo argomento di tipo type e resituisce un double
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
