//
// Created by Bogdan on 22.04.2024.
//


#ifndef RELISSTRUCTURE_ARRAYLIST_H
#define RELISSTRUCTURE_ARRAYLIST_H

#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

typedef struct arrayList {
    int val;
    int num; // Количество элементов
} ArrayList;

//добавление нового элемента
void addNewElement(ArrayList **arrayListPtr, int element) ;

//удаление элемента по индексу
void deleteElementByIndex(ArrayList **arrayList,int index);

//получение элемента по индексу
int getElementByIndex(ArrayList **arrayList,int index);

//проверка содержится ли элемент в листе
bool contains(ArrayList **arrayList,int element);

#endif //RELISSTRUCTURE_ARRAYLIST_H
