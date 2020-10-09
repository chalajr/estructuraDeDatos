/*
 * sorts.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef SORTS_H_
#define SORTS_H_

#include "exception.h"
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> bubbleSort(const std::vector<T>&);
	std::vector<T> selectionSort(const std::vector<T>&);
	std::vector<T> insertionSort(const std::vector<T>&);
	std::vector<T> shellSort(const std::vector<T>&);
	std::vector<T> mergeSort(const std::vector<T>&);

	std::vector<T> bucketSort(const std::vector<T>&);
	std::list<T>   mergeList(const std::list<T>&, const std::list<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::bubbleSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	int prueba = 0;
	if(prueba == 1){
		for (int i = v.size() - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
				}
			}
		}
	return v;
	}
	else{
		int i, j;
	bool s = false;
	for(i = 0; i < v.size() - 1; i ++){
		for(j = 0;j < - i - 1; i++){
			if(v[j] > v[j + 1]){
				swap(v, v[j], v[j +1]);
				s = true;				
			}
		}
	}
	if(s == false){
		return v;
	} 
	return bubbleSort(v);
	}
	
}

template <class T>
std::vector<T> Sorts<T>::selectionSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	int r;
	for (int i = v.size() - 1; i > 0; i--) {
		r = 0;
		for (int j = 1; j <= i; j++) {
			if (v[j] > v[r]) {
				r = j;
			}
		}
		if (r != i) {
			swap(v, i, r);
		}
	}
	return v;
}
template <class T>
std::vector<T> Sorts<T>::insertionSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	for(int i = 1; i < v.size(); i++){
		for(int j = i; j > 0; j--){
			if(v[j] < v[j - 1]){
				swap(v,j,j-1);
			}
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::shellSort(const std::vector<T> &source) {
	std::vector<T> v(source);

    for (int gap = v.size()/2; gap > 0; gap /= 2){    
        for (int i = gap; i < v.size(); i += 1) { 
            int temp = v[i]; 
            int j;             
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap){
				v[j] = v[j - gap];
			} 
            v[j] = temp; 
        } 
    }
	return v;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
}

template <class T>
std::vector<T> Sorts<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	return v;
}

template <class T>
std::vector<T> Sorts<T>::bucketSort(const std::vector<T> &source) {
	typename  std::list<T>::iterator itr;
	std::vector<T> v;

	return v;
}

template <class T>
std::list<T> Sorts<T>::mergeList(const std::list<T> &lst1, const std::list<T> &lst2) {
	typename std::list<T>::const_iterator itr1, itr2;
	std::list<T> result;

	return result;
}

#endif /* SORTS_H_ */
