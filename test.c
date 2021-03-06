#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* allocation(unsigned int size, char c){
        void *mem_1 = malloc(size);
        assert(memset(mem_1, c, size-1) != NULL);
        memset(mem_1 + size-1, '\0', 1);
        printf("%p %s\n", mem_1, mem_1);
        return mem_1;
}

void testScenarioFree(){
        void* ptr_1 = allocation(16, 'a');
        void *ptr_2 = allocation(16, 'b');
        free(ptr_2);
        free(ptr_1);
        allocation(16, 'c');
}

void testScenarioMalloc(){
        // Testing Heap Consistency for consequetive mallocs
        allocation(16, 'a');
        allocation(16, 'b');
        allocation(16, 'c');
        allocation(2000, 'd');
        allocation(2000, 'e');
}

void testScenarioCalloc(unsigned int size){
        void *mem_1 = calloc(size, 1);
        printf("%p\n", mem_1);
        int count = 0;
        while(count < size) {
                printf("%d\n", *((int *)mem_1));
                count++;
                mem_1++;
        }
}

void testScenarioRealloc(unsigned int size){
        void* mem_1 = malloc(16);
        memset(mem_1, 'c', 16);
        printf("%p\n", mem_1);
        void *mem_2 = realloc(mem_1, size);
        printf("%p\n", mem_2);
        int count = 0;
        while(count < size) {
                printf("%c\n", *((char *)mem_2));
                count++;
                mem_2++;
        }
        void* mem_3 = malloc(16);
        printf("%p\n", mem_3);
}

int main(int argc, char **argv)
{
        testScenarioMalloc();
        testScenarioFree();
        testScenarioCalloc(16);
        testScenarioRealloc(32);
        return 0;
}
