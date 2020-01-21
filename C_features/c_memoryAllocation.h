/*
 * c_memoryAllocation.h
 *
 *  Created on: 21 sty 2020
 *      Author: adria
 */

#ifndef C_FEATURES_C_MEMORYALLOCATION_H_
#define C_FEATURES_C_MEMORYALLOCATION_H_

#include <stdlib.h>
#include <stdio.h>

/*
 * There are 3 ways of memory alocation in C:
 * 1) Static - all objects are allocated on heap. Done automatically for global objects and
 * for local objectd with static keyword.
 * 2) Automatic - all objects are allocated on stack only at time of being in object contex.
 * Size of allocated objs must be known at compile time, with except of variable length arrays (c99)
 * 3) Dynamic - memory is allocated dynamically on heap, with runtime known length, and can be allocated and
 * freed in runtime. Gives control to programmer, but is also dangerous due to risk of memory leak and
 * fragmentation problems (memory alocation algorithm solves it)
 */

// Examples of static alocation:
int a = 0;
int staticTab[10];
void staticAllocTest(void)
{
	static int staticFuncVar = 5;
}

//Examples of automatic alocation:
void autoAllocTest(int a, int tab[])
{
	auto int autoVariable = 5;		//auto keyword - not needed
}

//Examples of dynamic memory allocation
void dynamicAllocTest(void)
{
	int* dynMem = malloc(1*sizeof(int));
	printf("Dynamic memory allocated: %i\n", *dynMem);

	dynMem = realloc(dynMem, 2*sizeof(int));
	printf("Dynamic memory reallocated to 2: %i, %i\n", *dynMem, dynMem[1]);

	free(dynMem);
	printf("Dynamic memory freed \n");

	dynMem = calloc(2, sizeof(int));
	printf("Dynamic memory calloc (alocated and init to 0): %i, %i\n", dynMem[0], dynMem[1]);
}

#endif /* C_FEATURES_C_MEMORYALLOCATION_H_ */
