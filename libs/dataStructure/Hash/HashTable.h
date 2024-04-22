//
// Created by Bogdan on 22.04.2024.
//

#ifndef RELISSTRUCTURE_HASHTABLE_H
#define RELISSTRUCTURE_HASHTABLE_H
#define INITIAL_CAPACITY 10

#include <stdio.h>
#include <stdbool.h>
#include "malloc.h"

//структура хеш таблицы
typedef struct hashTable{
    int val;
    int key;
    struct hashTable *next;
}HashTable;

//добавление нового значения в таблицу
void addValueInTable(HashTable **table, int value);

//метод хеширования ключа с помощью значения
int hashKey(int value);

//получение значения по ключу
bool getValueByKey(HashTable **table, int key);

//проверка содержится ли значение в таблице
//возвращает 1 если содержится и 0 если нет
bool containsInTable(HashTable **table, int value);

//удаление элементов по ключу
void removeValueByKey(HashTable **table, int key);

//удаление элемента по его значению
void removeValue(HashTable **table, int value);

//получение размера таблицы
size_t getSize(HashTable **table);


#endif //RELISSTRUCTURE_HASHTABLE_H
