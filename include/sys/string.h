#pragma once

#include <sys/types.h>

/**
 * @brief get length of string
 * 
 * @param str source string
 * @return size_t string length
 * 
 * @see https://en.wikibooks.org/wiki/C_Programming/string.h/strlen
 */
size_t strlen(const char * str);

/**
 * @brief reverse string s in place
 * 
 * @param s source & target string
 * 
 * @see https://en.wikibooks.org/wiki/C_Programming/stdlib.h/itoa
 */
void reverse(char s[]);

/**
 * @brief convert n to characters in s
 * 
 * @param n source value
 * @param s target buffer
 * 
 * @see https://en.wikibooks.org/wiki/C_Programming/stdlib.h/itoa
 */
void itoa(int n, char s[]);

/**
 * @brief compare s1 to s2
 * 
 * @param s1 one source string
 * @param s2 other source string
 * @return int
 * 
 * @see https://en.wikibooks.org/wiki/C_Programming/string.h/strcmp
 */
int strcmp (const char * s1, const char * s2);

/**
 * @brief copy src to dest
 * 
 * @param dest target string
 * @param src source string
 * @return char* 
 * 
 * @see https://en.wikibooks.org/wiki/C_Programming/string.h/strcpy#Usage_and_implementation
 */
char *strcpy(char *dest, const char *src);