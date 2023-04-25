// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	char *dest = destination;
	char *src = (char*) source;

	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	
	*dest = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	char *dest = destination;
	char *src = (char *) source;

	while(*src != '\0' && len > 0){

		*dest = *src;
		dest++;
		src++;
		len--;

	}

	if(len > 0){
		*dest = '\0';
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	char *dest = destination;
	dest += strlen(destination);

	char *src = (char *) source; 

	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	char *dest = destination;
	dest += strlen(destination);

	char *src = (char *) source; 

	while(*src != '\0' && len > 0){
		*dest = *src;
		dest++;
		src++;
		len--;
	}

	*dest = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	char *cstr1 = (char *) str1;
	char *cstr2 = (char *) str2;

	while(*cstr1 != '\0' && *cstr2 != '\0'){

		if(*cstr1 < *cstr2){ 
			return -1;
		}

		if(*cstr1 > *cstr2){
			return 1;
		}

		if(*cstr1 == *cstr2){
			cstr1++;
			cstr2++;
		}
	}

	if(*cstr1 == '\0' && *cstr2 == '\0'){ // equal
		return 0;
	}

	if(*cstr1 == '\0'){   // the word "str1" is included in the word "str2"
		return -1;
	}

	if(*cstr2 == '\0'){   // the word "str1" is included in the word "str2"
		return 1;
	}
	
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	char *cstr1 = (char *) str1;
	char *cstr2 = (char *) str2;

	
	while(*cstr1 != '\0' && *cstr2 != '\0' && len > 0){

		if(*cstr1 < *cstr2){ 
			return -1;
		}

		if(*cstr1 > *cstr2){
			return 1;
		}

		if(*cstr1 == *cstr2){
			cstr1++;
			cstr2++;
			len--;
		}
	}

	if(len == 0){ // the first len bytes in str1 are equal to the first len bytes in str2 
		return 0;
	}

	if(*cstr1 == '\0' && *cstr2 == '\0'){ // equal words
		return 0;
	}

	if(*cstr1 == '\0'){   // the word "str1" is included in the word "str2"
		return -1;
	}

	if(*cstr2 == '\0'){   // the word "str1" is included in the word "str2"
		return 1;
	}
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	char *cstr = (char *) str;

	while(*cstr != '\0'){
		if(*cstr == c){
			return cstr;
		}else{
			cstr++;
		}
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	char *cstr = (char *) str;

	int len = strlen(str);
	len--;

	cstr = cstr + len;

	while(len >= 0){
		if(*cstr == c){
			return cstr;
		}else{
			cstr--;
			len--;
		}

	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	char *occ = strchr(haystack, *needle);
	char *cneedle, *cocc;

	
	while(occ != NULL){
		cneedle = (char *) needle;
		cocc = occ;

		while(*cneedle != '\0'){
			if(*cneedle == *cocc){
				cneedle++;
				cocc++;
			}else{
				break;
			}
		}

		if(*cneedle == '\0'){
			return occ;
		}

		occ = strchr(occ + 1, *needle);
		
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	char *cneedle;
	char *occ, *cocc;
	char *chaystack = (char *)haystack;

	int len = strlen(haystack);
	len--; 

	chaystack += len;

	while(len >= 0){
		if(*chaystack == *needle){
			occ = chaystack;
			cocc = occ;
			cneedle = needle;

			while(*cneedle != '\0' && *cocc != '\0'){
				if(*cneedle == *cocc){
					cneedle++;
					cocc++;
				}else{
					break;
				}
			}

			if(*cneedle == '\0'){
				return occ;
			}

			chaystack--;
			len--;

		}else{
			chaystack--;
			len--;
		}

	} 

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char*) destination;
	char *src = (char*) source;

	while(num > 0 ){

		*dest = *src;
		dest++;
		src++;

		num--;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	char* src = (char*) source;
	char* dest = (char*) destination;

	char temp[num];

 	memcpy((void*) &temp, source, num);
 	memcpy(destination, (void*) &temp, num);

	return destination;

}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	
	char *cptr1 = (char*) ptr1;
	char *cptr2 = (char*) ptr2;

	for(size_t i = 0; i < num; i++){

		if(*cptr1 < *cptr2){
			return -1;
		}

		if(*cptr1 > *cptr2){
			return 1;
		}
		
		// *cptr1 == *cptr2
		cptr1++;
		cptr2++;
	}	

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	unsigned char c = (unsigned char) value;
	char *src = (char*) source;

	for(size_t i = 0 ; i < num; i++){
		*(src + i) = c;
	}

	return source;
}
