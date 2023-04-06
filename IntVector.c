#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"


IntVector *int_vector_new(size_t initial_capacity) {
    IntVector *v = malloc(sizeof(IntVector));
    if (v == NULL) {
        return NULL;
    }
    v->data = malloc(initial_capacity * sizeof(int));
    if (v->data == NULL) {
        free(v);
        return NULL;
    }
    v->size = 0;
    v->capacity = initial_capacity;
    return v;
}

IntVector *int_vector_copy(const IntVector *v) {
    IntVector *copy = int_vector_new(v->capacity);
    if (copy == NULL) {
        return NULL;
    }
    memcpy(copy->data, v->data, v->size * sizeof(int));
    copy->size = v->size;
    return copy;
}

void int_vector_free(IntVector *v) {
    if (v == NULL) {
        return;
    }
    free(v->data);
    free(v);
}

int int_vector_get_item(const IntVector *v, size_t index) {
    if (index < v->size) {
        return v->data[index];
    } else {
        return 0;
    }
}

void int_vector_set_item(IntVector *v, size_t index, int item) {
    if (index < v->size) {
        v->data[index] = item;
    }
}

size_t int_vector_get_size(const IntVector *v) {
    return v->size;
}

size_t int_vector_get_capacity(const IntVector *v) {
    return v->capacity;
}

int int_vector_push_back(IntVector *v, int item) {
    if (v->size == v->capacity) {
        size_t new_capacity = v->capacity * 2;
        int *new_data = realloc(v->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            return -1;
        }
        v->data = new_data;
        v->capacity = new_capacity;
    }
    v->data[v->size] = item;
    v->size++;
    return 0;
}

void int_vector_pop_back(IntVector* v) {
    if (v->size > 0) {
        v->size--;
    }
}

int int_vector_shrink_to_fit(IntVector *v) {
    int *new_data = realloc(v->data, sizeof(int) * v->size);
    if (!new_data) {
        return -1;
    }
    v->data = new_data;
    v->capacity = v->size;
    return 0;
}

int int_vector_resize(IntVector *v, size_t new_size) {
    if (v == NULL) {
        return -1;
    }

    if (new_size == v->size) {
        return 0;
    }

    if (new_size < v->size) {
        v->size = new_size;
        if (v->capacity > 4 * new_size) {
            return int_vector_shrink_to_fit(v);
        }
        return 0;
    }

    if (new_size > v->capacity) {
        size_t new_capacity = v->capacity;
        while (new_capacity < new_size) {
            new_capacity *= 2;
        }
        int result = int_vector_reserve(v, new_capacity);
        if (result != 0) {
            return -1;
        }
    }

    for (size_t i = v->size; i < new_size; i++) {
        v->data[i] = 0;
    }

    v->size = new_size;
    return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) {
    if (new_capacity <= v->capacity) {
        return 0;
    }

    int *new_data = realloc(v->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        return -1;
    }

    v->data = new_data;
    v->capacity = new_capacity;

    return 0;
}



