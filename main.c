#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "allocator.h"
#include "tester.h"
#include "block.h"
#include "tree.h"
#include "avl/avl_impl.h"

#include "tree.h"

int main(void)
{

	void *ptr1, *ptr2, *ptr3, *ptr4;
	ptr1 = mem_alloc(90000);
	mem_show("alloc 7000");
	printf("arena alloc - %zu\n", payload_to_block(ptr1)->size_curr);
	printf("arena alloc block_get_size_curr - %zu\n", block_get_size_curr(payload_to_block(ptr1)));
    
	ptr2 = mem_alloc(60);
	printf("ptr2 - %zu\n", payload_to_block(ptr2)->size_curr);
	ptr3 = mem_alloc(6000);
	printf("ptr3 - %zu\n", payload_to_block(ptr3)->size_curr);
	ptr4 = mem_alloc(534);
	printf("ptr4 - %zu\n", payload_to_block(ptr4)->size_curr);
	
	mem_show("allocs");
	printf("arena alloc - %zu\n", payload_to_block(ptr1)->size_curr);
	ptr1 = mem_realloc(ptr1, 60000);
	mem_show("realloc ptr1 -> 60000");

	mem_free(ptr1);
	mem_show("free ptr1");
	
	mem_realloc(ptr4, 1003);
	mem_show("realloc ptr4 -> 1003");
	printf("ptr2 - %zu\n", payload_to_block(ptr2)->size_curr);
	printf("ptr3 - %zu\n", payload_to_block(ptr3)->size_curr);
	printf("ptr4 - %zu\n", payload_to_block(ptr4)->size_curr);
	
	// srand(time(NULL));
	// tester(true);
}

