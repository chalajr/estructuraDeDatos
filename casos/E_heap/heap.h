/*
 * heap.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	unsigned int size;
	unsigned int count;
	
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);
	
public:
	Heap(unsigned int) throw (OutOfMemory);
	~Heap();
	bool empty() const;
	bool full() const;
	void add(T) throw (Overflow);
	T remove() throw (NoSuchElement);
	void clear();
	std::string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int sze) throw (OutOfMemory) {
	size = sze;
	count = 0;
	data = new T[size];
	if(data == 0){
		throw OutOfMemory();
	}
}

template <class T>
Heap<T>::~Heap() {
	delete []data;
	data = NULL;
	size = 0;
}

template <class T>
bool Heap<T>::empty() const {
	if(count == 0){
		return true;
	}
	else {
		return false;
	}
}

template <class T>
bool Heap<T>::full() const {
	if (count == size){
		return true;
	}
	return false;
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1)/2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {

	return (pos - 2)/2;
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return 0;
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	int prueba = 0;
	unsigned int posAux;
	if (prueba == 1){
		if(data[pos] > data[left(pos)] && left(pos) <= count){
			swap(pos, left(pos));
			posAux = left(pos);
			heapify(posAux);
		}

		if(data[pos] > data[right(pos)] && right(pos) <= count){
			swap(pos, right(pos));
			posAux = right(pos);
			heapify(posAux);
		}
	}
	else{
		unsigned int posicion_min = pos;
		if(data[pos] > data[left(pos)] && left(pos) <= count){
			posicion_min = left(pos);
		}

		if(data[pos] > data[right(pos)] && right(pos) <= count){
			posicion_min = right(pos);
		}

		if (posicion_min != pos){
			swap(pos, posicion_min);
			heapify(posicion_min);
		}
	}
	
}

template <class T>
void Heap<T>::add(T val) throw (Overflow) {
	// Verificar que no este lleno el heap 
	if(full()){
		throw Overflow();
	}
	//Obtener la siguiente posicion disponible
	int posicion = count;
	// Agregar el elemento 
	data[posicion] = val;
	// Aumentar el count
	count++;
	//reheap up 
	while (posicion > 0 && data[parent(posicion)] > val){
		swap(posicion, parent(posicion));
		posicion = parent(posicion);
	}
}

template <class T>
T Heap<T>::remove() throw (NoSuchElement) {
	// verificar que no este vacio el elemento que quiero eliminar
	if(empty()){
		throw NoSuchElement();
	}

	T aux = data[0];
	// pasar el ultimo elemento de la raiz 
	data[0] = data[count - 1];
	// reheap down
	heapify(0);
	// eliminar el ultimo elemento
	// actualizar el count
	return aux;
}

template <class T>
void Heap<T>::clear() {
	count = 0;
}
	

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	
	aux << "[";
	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
		aux << data[i];
	}
	aux << "]";
	return aux.str();
}
#endif /* HASH_H_ */
	
