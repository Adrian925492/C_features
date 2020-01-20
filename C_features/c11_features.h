/*
 * C11 features:
 * -> alignment specificators
 * -> multithreading support
 * -> generic type macros
 * -> static assertions
 * -> no-name structs and unions
 * -> bounds checking interface
 * -> char16_t and char32_t types
 */

/* No - name structs and unions */
struct
{
	int a;
}oStruktura;	//No - name structure, only instance

union
{
	int a;
	long int b;
}oUnia;

/* Alignment specificators */
#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void alignmentTest(void)
{
	size_t a = alignof(max_align_t);
	/* Alignof - returns alignment requirement of is argument, for example, alignof(char) = 1 */
	printf("Alignment of max_align_t is %du\n", a);
}

/* Noreturn functions */
#include <stdnoreturn.h>

noreturn void noreturnFcnTest(void)		/* Noreturn - informs that the function never returns (like FreeRTOS task) */
{
	for (;;){}		/* If noreturn function returns - the behaviour is undefined! */
}

/* Generic type macros */

//First step: define n number of functions for several argument type cases
#include <float.h>

static void printInt(int a)
{
	printf("%s %i\n", "Print int: ", a);
}

static void printFloat(float a)
{
	printf("%s %f\n", "Print float: ", a);
}

static void printString(const char* a)
{
	printf("%s %s\n", "Print string: ", a);
}

//Second step: use generic type macro
#define wyswietl(x) _Generic((x), \
		const char* : printString, \
		default: printInt, \
		float: printFloat)(x)

void genericTypePrintTest(void)
{
	int a = 2;
	float b = 2.2;
	const char* s = "string";

	wyswietl(a);
	wyswietl(b);
	wyswietl(s);
}

/* Static assertions in C */
#include <assert.h>

enum {N = 5};
_Static_assert(N == 5, "N does not equal 5");		/* just a literal, do nothing */
static_assert(N > 10, "N is not greater than 10");  /* compiler error */
