
/*
 * New features in C99 vs older standards:
 * -> Inline functions
 * -> Restrict and Static keywords
 * -> No implicit int rule
 * -> Wariadic macros
 * -> Variable - length arrays
 * -> Complex type support
 * -> Compound literals
 * -> Struct elements initializer list by name
 * -> Bool type in <stdbool.h>
 * -> Better support for floating-point numbers (double, long double)
 * -> New types: long and long long
 * -> C++ one line style comments - starting with //
 */

#include <stdio.h>

#define SUM(X, Y) ((X)+(Y))					// Classic macro
#define TYPE_VARIADIC(...) __VA_ARGS__		// Variadic macro

//Xmacro: step1 - define order of X macros
#define XMACRO_LIST \
	XMACRO("str1") \
	XMACRO("str2") \
	XMACRO("str3")

//Step 2: define macro that will be compound in each place in list order
#define XMACRO(name) (printf("%s%s\n", "X-macro String named: ", name));

struct struktura
{
	int a;
	int b;
};
struct struktura p = {.a = 2, .b = 3};		//Nazywanie elementów struktury po .


void foo(const char* data);

void compoundLiteral(void)
{
	/* Classic style literal */
	char sign[] = "Classic style literal";
	foo(sign);

	/* Compound style literal */
	foo((const char*){"Compound style literal"});

}

void macrosTest(void)
{
	/* Classic style macro: sum */
	printf("%s %d\n", "Sum of classic style macro 2 + 3: ", SUM(2,3));

	/* Variadic style macro: sum */
	printf("%s %d %d %d\n", "Numbers 2,3,4 variadic: ", TYPE_VARIADIC(2,3,4));
	printf("%s %d %d %d %d\n", "Numbers 2,3,4,5 variadic: ", TYPE_VARIADIC(2,3,4,5));

	/* Xmacro */
	XMACRO_LIST
}

void foo(const char* data)
{
	printf("%s\n", data);
}
