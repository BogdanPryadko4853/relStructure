#include "libs/dataStructure/Hash/HashTable.h"
#include <windows.h>




int main() {
    HashTable **table = (HashTable **)malloc(INITIAL_CAPACITY * sizeof(HashTable *));

    // Инициализация таблицы
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        table[i] = NULL;
    }

    // Тест добавления значения
    addValueInTable(table, 5);
    addValueInTable(table, 15);

    // Тест получения значения по ключу
    printf("Value for key 5: %d\n", getValueByKey(table, 5));
    printf("Value for key 10: %d\n", getValueByKey(table, 10));

    // Тест наличия значения в таблице
    printf("Contains value 5: %d\n", containsInTable(table, 5));
    printf("Contains value 10: %d\n", containsInTable(table, 10));

    // Тест удаления значения по ключу
    removeValueByKey(table, 5);
    printf("Contains value 5 after removal: %d\n", containsInTable(table, 5));

    // Тест удаления значения
    addValueInTable(table, 20);
    removeValue(table, 15);
    printf("Contains value 15 after removal: %d\n", containsInTable(table, 15));
    // Тест получения размера таблицы
    printf("Size of table: %zu\n", getSize(table));

    // Освобождение памяти
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        HashTable *current = table[i];
        while (current != NULL) {
            HashTable *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table);

    return 0;
}