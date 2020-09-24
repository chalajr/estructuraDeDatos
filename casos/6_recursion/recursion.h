/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */

#ifndef RECURSION_H_
#define RECURSION_H_

#include "exception.h"
#include <iostream>

long sum_seq(int n) {
	long resultado = 0;
	int contador = 0;
	while (contador <= n){
		resultado = resultado + contador;
		contador++;
	}
	return resultado;
}

long sum_rec(int n) {
	if (n == 1){
		return 1;
	}
	return n + sum_rec(n - 1);
}

long fact_seq(int n) {
	long resultado = 1;
	long contador = 1;
	while(contador <= n){
		resultado = resultado * contador;
		contador++;
	}
	return resultado;
}

long fact_rec(int n) {
	if(n == 0){
		return 1;
	}
	return n * fact_rec(n - 1);
}

long fib_seq(int n) {
	long x, y, r;
	int i;
	if (n == 1 || n == 2){
		return 1;
	}
	x = 1;
	y = 1;
	i = 3;
	
	while(i <= n){
		r = x + y;
		y = x;
		x = r;
		i++;
	}
	return x;
}

long fib_rec(int n) {
	if(n == 1 || n == 2){
		return 1;
	}
	else{
		return fib_rec(n-1) + fib_rec(n-2);
	}
	
}

long gcd_seq(long a, long b) {
	long res;

	while (b != 0) {
		res = b;
		b = a % b;
		a = res;
	}
	return a;
}

long gcd_rec(long a, long b) {
	if(a == 0){
		return b;
	}
	else{
		return gcd_rec(b % a , a);
	}
}

bool find_seq(int arr[], int size, int val) {
	for(int i = 0; i < size; i++){
		if(arr[i] == val){
			return true;
		}	
	}
	return false;
}

bool find_rec(int arr[], int low, int high, int val) {
	int mid;
	bool aux;

	if ( ((high - low) + 1) == 1) {
		return (val == arr[low]);
	} else {
		aux = false;
		mid = (high + low) / 2;
		aux = find_rec(arr, low, mid, val);
		if (!aux) {
			aux = find_rec(arr, mid + 1, high, val);
		}
		return aux;
	}
}

int max_seq(int arr[], int size) {
	int prueba = 0;
	if(prueba = 1){
		int com = arr[0];
		for(int i = 1; i < size; i ++){
			if(com < arr[i]){
			com = arr[i];
			}
		}	
	return com;
	}
	if(prueba = 0){
		int res;
		for(int i = 0; i < size; i++){
			for(int j = 1; j < size; j++){
				if(arr[i]<arr[j]){
					res = arr[j];
				}
			}
		}
		return res;
	}
}

int max_rec(int arr[], int low, int high) {
	int m, n;
	return 0;
}

int unimodal_seq(int arr[], int size) {
	return 0;
}

int unimodal_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_rec(int arr[], int size) {
	return 0;
}

int bs_seq(int arr[], int size, int val) {
	return 0;
}

int bs_aux(int arr[], int low, int high, int val) {
	return 0;
}

int bs_rec(int arr[], int size, int val) {
	return 0;
}
#endif /* RECURSION_H_ */
