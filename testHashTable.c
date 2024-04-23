#include "libs/dataStructure/Hash/HashTable.h"
#include <windows.h>
#include <assert.h>

void testAddValueInTable() {
    HashTable *table[INITIAL_CAPACITY];
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        table[i] = NULL;
    }

    addValueInTable(&table, 10);
    addValueInTable(&table, 20);
    addValueInTable(&table, 30);

    assert(getValueByKey(&table, 10) == true);
    assert(getValueByKey(&table, 20) == true);
    assert(getValueByKey(&table, 30) == true);
}

void testGetValueByKey() {
    HashTable *table[INITIAL_CAPACITY];
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        table[i] = NULL;
    }

    addValueInTable(&table, 10);
    addValueInTable(&table, 20);
    addValueInTable(&table, 30);

    assert(getValueByKey(&table, 10) == true);
    assert(getValueByKey(&table, 20) == true);
    assert(getValueByKey(&table, 30) == true);
}

void testContainsInTable() {
    HashTable *table[INITIAL_CAPACITY];
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        table[i] = NULL;
    }

    addValueInTable(&table, 10);
    addValueInTable(&table, 20);
    addValueInTable(&table, 30);

    assert(containsInTable(&table, 10) == true);
    assert(containsInTable(&table, 20) == true);
    assert(containsInTable(&table, 30) == true);
}

void testRemoveValueByKey() {
    HashTable *table[INITIAL_CAPACITY];
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        table[i] = NULL;
    }

    addValueInTable(&table, 10);
    addValueInTable(&table, 20);
    addValueInTable(&table, 30);

    removeValueByKey(&table, 10);
    assert(getValueByKey(&table, 10) == false);

    removeValueByKey(&table, 20);
    assert(getValueByKey(&table, 20) == false);

    removeValueByKey(&table, 30);
    assert(getValueByKey(&table, 30) == false);
}

void testRemoveValue() {
    HashTable *table[INITIAL_CAPACITY];
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        table[i] = NULL;
    }

    addValueInTable(&table, 10);
    addValueInTable(&table, 20);
    addValueInTable(&table, 30);

    removeValue(&table, 10);
    assert(getValueByKey(&table, 10) == false);

    removeValue(&table, 20);
    assert(getValueByKey(&table, 20) == false);

    removeValue(&table, 30);
    assert(getValueByKey(&table, 30) == false);
}

void testGetKeys() {
    HashTable *table[INITIAL_CAPACITY];
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        table[i] = NULL;
    }

    addValueInTable(&table, 12);
    addValueInTable(&table, 23);
    addValueInTable(&table, 31);

    int *keys = getKeys(&table);
    for (int i = 0; i < 3; i++) {
        printf("%d ", keys[i]);
    }

    free(keys);
}

void testGetValues() {
    HashTable *table[INITIAL_CAPACITY];
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        table[i] = NULL;
    }

    addValueInTable(&table, 10);
    addValueInTable(&table, 20);
    addValueInTable(&table, 30);

    int *values = getValues(&table);
    assert(values[0] == 10);
    assert(values[1] == 20);
    assert(values[2] == 30);

    free(values);
}

int main() {
    testAddValueInTable();
    testGetValueByKey();
    testContainsInTable();
    testRemoveValueByKey();
    testRemoveValue();
    testGetKeys();
    testGetValues();

    printf("All tests passed\n");
    return 0;
}