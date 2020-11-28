
/*
 * bst.h
 *
 *  Created on: 30/10/2015
 *      Author: clase
 */

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class BST;

template <class T>
class TreeNode {
private:
	T value;
	TreeNode *left, *right;

	TreeNode<T>* succesor();

public:
	TreeNode(T);
	TreeNode(T, TreeNode<T>*, TreeNode<T>*);
	void add(T);
	bool find(T);
	void remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;

	friend class BST<T>;
};

template <class T>
TreeNode<T>::TreeNode(T val) {
	value = val;
	left = NULL;
	right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri) {
	value = val;
	left = le;
	right = ri;
}

template <class T>
void TreeNode<T>::add(T val) {
	//Si val es menor que value
	if(val < value){
		// Si no tiene rama izquierda
		
		if(left == NULL){
			//Insertamos en el nodo izquierda
			left = new TreeNode<T>(val);
		}
		// Si tiene rama izquierda
		else{
			//Insertamos el nodo en rama izquierda
			left->add(val);
		}
	}
		
	//Si val es menor que value
	if(val > value){
		// Si no tiene rama derecha
		
		if(right == NULL){
			//Insertamos en el nodo derecha
			right = new TreeNode<T>(val);
		}
		// Si tiene rama derecha
		else{
			//Insertamos el nodo en rama derecha
			right->add(val);
		}
	}

}

template <class T>
bool TreeNode<T>::find(T val) {
	//SI val es igual a valor del nodo regresamos verdadero
	if(val == value){
		return true;
	}
	//Si val es menor a value buscamos del lado izquierdo
	if(val < value && left != NULL){
		return left->find(val);
	}
	//Si val es mayor a value buscamos del lado derecho
	if(val > value && right != NULL){
		return right->find(val);
	}

	//Si no se encuentra val en el arbol regresamos falso
	return false;
}

template <class T>
TreeNode<T>* TreeNode<T>::succesor() {
	return 0;
}

template <class T>
void TreeNode<T>::remove(T val) {
}

template <class T>
void TreeNode<T>::removeChilds() {
}

template <class T>
void TreeNode<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void TreeNode<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
class BST {
private:
	TreeNode<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void remove(T);
	void removeAll();
	std::string inorder() const;
	std::string preorder() const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if(empty()){
		root = new TreeNode<T>(val);
	}
	else{
		root->add(val);
	}
}

template <class T>
void BST<T>::remove(T val) {
}

template <class T>
void BST<T>::removeAll() {
}

template <class T>
bool BST<T>::find(T val) const {
	return root->find(val);
}

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

#endif /* BST_H_ */
