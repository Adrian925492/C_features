/*
 * main.c
 *
 *  Created on: 20 sty 2020
 *      Author: adria
 */
#include <stdio.h>

#include "C_features/c99_features.h"
#include "C_features/c11_features.h"

int main(void)
{
	printf("%s", "HelloWorld\n\n");

	/* C features - c99 */
	compoundLiteral();
	macrosTest();

	/* C features - c11 */
	alignmentTest();
	genericTypePrintTest();

	return 0;
}



