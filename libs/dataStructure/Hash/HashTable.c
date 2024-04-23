//
// Created by Bogdan on 22.04.2024.
//

#include "HashTable.h"

// Добавление значения в таблицу
void addValueInTable(HashTable **table, int value) {
    int key = hashKey(value);
    int index = key % INITIAL_CAPACITY; // Получаем индекс списка

    // Создаем новый элемент
    HashTable *newElement = (HashTable *) malloc(sizeof(HashTable));
    newElement->val = value;
    newElement->key = key;
    newElement->next = NULL;

    // Добавляем новый элемент в начало соответствующего списка
    if (table[index] == NULL) {
        table[index] = newElement;
    } else {
        newElement->next = table[index];
        table[index] = newElement;
    }
}

// Получение значения по ключу
bool getValueByKey(HashTable **table, int key) {
    bool ret = false;
    int index = key % INITIAL_CAPACITY;
    HashTable *current = table[index];

    while (current != NULL) {
        if (current->key == key) {
            printf("%d\n", current->val);
            ret = true;
        }
        current = current->next;
    }
    return ret;
}

bool containsInTable(HashTable **table, int value) {
    int key = hashKey(value);
    int index = key % INITIAL_CAPACITY;
    HashTable *current = table[index];
    while (current != NULL) {
        if (current->val == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void removeValueByKey(HashTable **table, int key) {
    int index = hashKey(key) % INITIAL_CAPACITY;
    HashTable *current = table[index];
    HashTable *previous = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (previous == NULL) {
                table[index] = current->next; // Удаление первого элемента
            } else {
                previous->next = current->next; // Удаление элемента в середине или конце
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void removeValue(HashTable **table, int value) {
    int key = hashKey(value);
    int index = hashKey(key) % INITIAL_CAPACITY;
    HashTable *current = table[index];
    HashTable *previous = NULL;
    while (current != NULL) {
        if (current->val == value) {
            if (previous == NULL) {
                table[index] = current->next; // Удаление первого элемента
            } else {
                previous->next = current->next; // Удаление элемента в середине или конце
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

size_t getSize(HashTable **table) {
    size_t count = 0;

    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        HashTable *current = table[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }

    return count;
}

int hashKey(int val) {
    return val % 10;
}

bool isEmpty(HashTable **table) {
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        HashTable *current = table[i];
        if (current != NULL) {
            return false; // Если хотя бы один элемент в ячейке не пуст, таблица не пуста
        }
    }
    return true; // Если все ячейки пусты, таблица пуста
}

int *getKeys(HashTable **table) {
    size_t count = 10;
    int *res = (int *) malloc(count * sizeof(int));
    size_t k = 0;
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        HashTable *current = table[i];
        while (current != NULL) {
            res[k] = current->key;
            k++;
            if (k >= count) {
                count += 10;
                res = (int *) realloc(res, count * sizeof(int));
            }
            current = current->next;
        }
    }

    for (int i = 0; i < k; ++i) {
        printf("%d ", res[i]);
    }

    return res;
}

int *getValues(HashTable **table) {
    size_t count = 10;
    int *res = (int *) malloc(count * sizeof(int));
    size_t k = 0;

    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        HashTable *current = table[i];
        while (current != NULL) {
            res[k] = current->val;
            k++;
            if (k >= count) {
                count += 10;
                res = (int *) realloc(res, count * sizeof(int));
            }
            current = current->next;
        }
    }
    for (int i = 0; i < k; ++i) {
        printf("%d ", res[i]);
    }
    return res;
}

void clearTable(HashTable **table){
    HashTable *current, *next;
    current = *table;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }

    *table = NULL;
}

int getMinValue(HashTable **table) {
    int minValue = INT_MAX;
    HashTable *current;

    for(size_t i =0;i<INITIAL_CAPACITY;i++){
        current = table[i];
        while(current!=NULL){
            if(current->val<minValue){
                minValue=current->val;
            }
            current = current->next;
        }
    }
    return minValue;
}

int getMaxValue(HashTable **table) {
    int maxValue = INT_MIN;
    HashTable *current;

    for(size_t i =0;i<INITIAL_CAPACITY;i++){
        current = table[i];
        while(current!=NULL){
            if(current->val>maxValue){
                maxValue=current->val;
            }
            current = current->next;
        }
    }
    return maxValue;
}

int getAverageValue(HashTable **table) {
    int count = 0;
    int sumOfAllElements = 0;

    HashTable *current;

    for(size_t i =0;i<INITIAL_CAPACITY;i++){
        current = table[i];
        while(current!=NULL){
            sumOfAllElements+= current->val;
            current = current->next;
            count++;
        }
    }

    return sumOfAllElements/count ;
}

int getModelValue(HashTable **table) {
    int sumOfAllElements = 0;
    int modelValue = 0;

    HashTable *current;

    for(size_t i =0;i<INITIAL_CAPACITY;i++){
        current = table[i];
        while(current!=NULL){
            sumOfAllElements+= current->val;
            current = current->next;
        }
    }

    modelValue = sumOfAllElements;

    return modelValue;
}
