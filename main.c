/*
 * main.c
 *
 *  Created on: Dec 29, 2015
 *      Author: Johnathan
 */

#include <stdio.h>

/*
 * Does memcpy. But probably less efficiently?
 */
void *jlmemcpy(void *dest, const void *src, unsigned int n)
{
	char *bytedest = (char *)dest;
	const char *bytesrc = (const char *)src;
	for (unsigned int i = 0; i < n; i++) {
		bytedest[i] = bytesrc[i];
	}
	return dest;
}

int main(int argc, char **argv)
{
	printf("HELLO\n");
	int arrayofints[128];
	printf("%p\n", &arrayofints);

	char buffer[4096];
	char destination[4096];
	char *result;
	result = fgets(&buffer[0], 4096, stdin);
	if(result!=NULL) {
		printf("%s\n", &buffer[0]);
		jlmemcpy((void *)&destination, (const void *)buffer, 4096);
		printf("%s\n", &destination[0]);
	} else {
		printf("Error\n");
	}

	return 0;
}
