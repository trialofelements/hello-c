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

/*
 * Does memmove. But probably less efficiently?
 */
void *jlmemmove(void *dest, const void *src, unsigned int n)
{
	char *bytedest = (char *)dest;
	const char *bytesrc = (const char *)src;
	if (bytedest > bytesrc && bytedest < (bytesrc + n)) {
		for (unsigned int i = 0; i < n; i++) {
			int x = n - 1 - i;
			bytedest[x] = bytesrc[x];
		}
	} else if (bytedest == bytesrc) {
		//Do nothing because dest == src
	} else {
		//Copy left to right (which jlmemcpy does)
		jlmemcpy(dest, src, n);
	}
	return dest;
}

int main(int argc, char **argv)
{
	int arraysize = 128;
	printf("HELLO\n");
	int arrayofints[arraysize];
	printf("%p\n", &arrayofints);

	char buffer[4096];
	char destination[4096];
	char *result;

	result = fgets(&buffer[0], 4096, stdin);

	if(result!=NULL) {
		printf("%s\n", &buffer[0]);
		jlmemcpy((void *)destination, (const void *)buffer, 4096);
		printf("%s\n", &destination[0]);
		jlmemmove((void *)&buffer[2], (const void *)buffer, 4094);
		printf("%s\n", &buffer[0]);

	} else {
		printf("Error\n");
	}

	for (int i = 0; i < arraysize; i++) {
		arrayofints[i] = i + 1;
	}
	for (int i = 0; i < arraysize; i++) {
		printf("%d ", arrayofints[i]);
	}
	printf("\n");
	jlmemmove((void *)&arrayofints[3], (const void *)&arrayofints[0],
			  sizeof(int)*(arraysize - 3));
	for (int i = 0; i < arraysize; i++) {
		printf("%d ", arrayofints[i]);
	}
	printf("\n");
	jlmemmove((void *)&arrayofints[0], (const void *)&arrayofints[3],
			  sizeof(int)*(arraysize - 3));
	for (int i = 0; i < arraysize; i++) {
		printf("%d ", arrayofints[i]);
	}
	printf("\n");

	return 0;
}
