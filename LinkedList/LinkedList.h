#pragma once
#include <memory>
#include <initializer_list>
using std::unique_ptr;

template<template U>
struct Node<U> {
	U data;
	unique_ptr< Node<U> > next{ nullptr };
};


template<typename T>
class LinkedList<T>
{
	unique_ptr< Node<T> > head{ nullptr };
	int size{ 0 };
public:
	LinkedList(std::initializer_list<T>);

	T operator[](int);

	LinkedList(const LinkedList&) = delete;
	LinkedList(LinkedList&&) = delete;
};

