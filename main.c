/*
 * main.c
 *
 *  Created on: Dec 29, 2015
 *      Author: Johnathan
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	printf("HELLO\n");
	int arrayofints[128];
	printf("%x", &arrayofints);

	char buffer[4096];
	gets(&buffer);
	return 0;
}
