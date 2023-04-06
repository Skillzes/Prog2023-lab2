#include <stdio.h>
#include "IntVector.h"

int main()
{
    IntVector *v= int_vector_new(10);

    printf("Create a new vector\n");
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));
    printf("\n");
    
    int i;
    v->size = 4;

    for(i = 0; i < v->size; i++) {
        int_vector_set_item(v, i, i+1);
    }
    printf("Setted vector: ");
    for(i = 0; i < v->size; i++) {
        printf("%d ",int_vector_get_item(v, i));
    }
    printf("\n\n");

    IntVector *v_copy = int_vector_copy(v);

    printf("Copied vector: ");
    for(i = 0; i < v->size; i++) {
        printf("%d ",int_vector_get_item(v_copy, i));
    }
    printf("\n\n");

    
    printf("The 9th item is %d\n",int_vector_get_item(v, 9));

    int_vector_reserve(v, 15);
    printf("Reserve\n");
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));
    printf("\n");

    int_vector_shrink_to_fit(v);
    printf("Shrink to fit\n");
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));
    printf("\n");

    int_vector_resize(v, 10);
    printf("Resize\n");
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));

    printf("Current vector: ");
    for(i = 0; i < v->size; i++) {
        printf("%d ",int_vector_get_item(v, i));
    }
    printf("\n\n");

    int_vector_resize(v, 5);
    printf("Resize\n");
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));

    printf("Current vector: ");
    for(i = 0; i < v->size; i++) {
        printf("%d ",int_vector_get_item(v, i));
    }
    printf("\n\n");

    int_vector_push_back(v, 9);
    printf("Push back\n");    
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));

    printf("After push back: ");
    for(i = 0; i < v->size; i++) {
        printf("%d ",int_vector_get_item(v, i));
    }
    printf("\n\n");

    int_vector_pop_back(v);
    printf("Pop back\n");
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));
    printf("After pop back: ");
    for(i = 0; i < v->size; i++) {
        printf("%d ",int_vector_get_item(v, i));
    }
    printf("\n\n");

    int_vector_resize(v, 0);
    printf("Resize\n");
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));
    printf("\n");

    int_vector_push_back(v, 9);
    printf("Push back\n");    
    printf("Size: %ld\n", int_vector_get_size(v));
    printf("Capacity: %ld\n", int_vector_get_capacity(v));

    printf("After push back: ");
    for(i = 0; i < v->size; i++) {
        printf("%d ",int_vector_get_item(v, i));
    }
    printf("\n\n");

    int_vector_free(v);
    int_vector_free(v_copy);

    return 0;
}

