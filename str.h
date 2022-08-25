#include<stdlib.h>
//Functions below from source file "stra.c"
size_t Str_getLength(const char string[]);
char *Str_copy(char Dst[] , const char Src[]);
char *Str_concat(char s1[] , const char s2[]);
int Str_compare(const char s1[] , const char s2[]);
char *Str_search( const char s1[] , const char s2[]);
int Str_contain(const char s1[] , const char s2[]);

//Functions below from source file "strp.c"
size_t Str_getLength(const char *string);
char *Str_copy(char *Dst , const char *Src);
char *Str_concat(char *Dst , const char *Src);
int Str_compare(const char *s1 , const char *s2);
int Str_contain(const char *s1 , const char *s2);
char *Str_search( const char *s1 , const char *s2);