// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

	void *start = mem_list_head.prev->start + mem_list_head.prev->len;

	void *ret = mmap(start, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if(ret == MAP_FAILED){
		return NULL;
	}

	//successful memory allocation 
	mem_list_add(ret, size);

	return ret;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */

	size_t total_size = nmemb * size;

	void *ret = malloc(total_size);

	if(ret == NULL){
		return NULL;
	}

	//successful memory allocation 
	memset(ret, 0, total_size);

	return ret;
	
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

	struct mem_list* node = mem_list_find(ptr);

	if(node == NULL){
		return;
	}

	void* save_start = node->start;

	// int ret2 = munmap(node->start, node->len);
	int ret2 = munmap(save_start, node->len);

	if(ret2 == -1){
		return;
	}

	int ret1 = mem_list_del(save_start);
	if(ret1 == -1){
		return;
	}

	return;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

	struct mem_list *node = mem_list_find(ptr);

	void *new_start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	memcpy(new_start, ptr, node->len);

	munmap(ptr, node->len);

	node->start = new_start;
	node->len = size;


	return new_start;
	
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	struct mem_list *node = mem_list_find(ptr);

	size_t new_len = nmemb * size;

	void *new_start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	memcpy(new_start, ptr, node->len);

	munmap(ptr, node->len);

	node->start = new_start;
	node->len = new_len;


	return new_start;

}
