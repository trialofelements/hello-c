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
	printf("%p\n", &arrayofints);

	char buffer[4096];
	if(fgets(&buffer[0], 4096, stdin)!=NULL){
		printf("%s\n", &buffer[0]);
	} else {
		printf("Error\n");
	}
	return 0;
}
