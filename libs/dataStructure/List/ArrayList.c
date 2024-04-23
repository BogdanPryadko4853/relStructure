//
// Created by Bogdan on 22.04.2024.
//
#include "ArrayList.h"

void addNewElement(ArrayList **arrayListPtr, int element) {
    ArrayList *arrayList = *arrayListPtr;
    // Увеличиваем размер выделенной памяти
    arrayList = realloc(arrayList, (arrayList->num + 1) * sizeof(ArrayList));
    if (arrayList == NULL) {
        // Обработка ошибки выделения памяти
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }
    // Добавляем новый элемент
    arrayList[arrayList->num].val = element;
    arrayList->num++;
    // Обновляем указатель
    *arrayListPtr = arrayList;
}
