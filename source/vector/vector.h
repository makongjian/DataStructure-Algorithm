/*
 * @Author: yanxinhao
 * @Email: 1914607611xh@i.shu.edu.cn
 * @LastEditTime: 2020-10-15 19:37:51
 * @LastEditors: yanxinhao
 * @Description: 
 */
#pragma once

typedef int Rank;
#define DEFAULT_CAPACITY 100

#include <iostream>

enum SORTING
{
    BUBBLESORT,
    MERGESORT
};

enum SEARCHING
{
    BINSEARCH
};

template <typename T>
class Vector
{
private:
    Rank _size;
    int _capacity;
    T *_elem;
    void copyfrom(T const *A, Rank lo, Rank hi);
    void expand();

public:
    // Vector() : _capacity(DEFAULT_CAPACITY), _size(0){};
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0);
    Vector(T const *A, Rank lo, Rank hi);
    ~Vector();

    bool empty() { return _size == 0; };
    void insert(Rank r, const T &elem);
    int insert(const T &elem)
    {
        insert(_size, elem);
        return _size - 1;
    }; //尾插,返回插入节点的位置index
    int remove(Rank lo, Rank hi);
    T remove(Rank r);
    void traverse(void (*visit)(T &)) const;
    Rank size() { return _size; }
    T &operator[](Rank r) const;

    // 无序向量
    Rank find(const T &e, Rank lo, Rank hi);
    int deduplicate();
    int deduplicate_2();

    // 有序向量
    int uniquify();
    bool sort(Rank lo, Rank hi, SORTING kind = BUBBLESORT);
    bool bubblesort(Rank lo, Rank hi);
    Rank bubble(Rank lo, Rank hi);
    bool mergesort(Rank lo, Rank hi);
    bool merge(Rank lo, Rank mid, Rank hi);

    Rank search(const T &e, Rank lo, Rank hi, SEARCHING kind = BINSEARCH);
    static Rank binsearch(const T *A, const T &e, Rank lo, Rank hi);
    static Rank binsearch_2(const T *A, const T &e, Rank lo, Rank hi);
    static Rank binsearch_3(const T *A, const T &e, Rank lo, Rank hi);
};

#include "vector/vector_implement.h"