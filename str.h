#include<stdlib.h>
//Functions below from source file "stra.c"

//-------------------------------------------------------------------------
//Str_getLength is to get the length of cetain string.  
//the only parameter must a constant string array  
//Return Value is size_t typed integer.
//--------------------------------------------------------------------------                      
size_t Str_getLength(const char string[]);

//--------------------------------------------------------------------------
//Str_copy is to cope Src String to Dst string.  
//one of two parameters must a  string array,another must be constant.  
//Return Value is the address which point to the frist element in Dst array.
//-------------------------------------------------------------------------- 
char *Str_copy(char Dst[] , const char Src[]);

//--------------------------------------------------------------------------
//Str_concat is to concat string S2 to string s1 .  
//one of two parameters must a  string array,another must be constant.  
//Return Value is the address which point to the frist element in S1 array.
//--------------------------------------------------------------------------- 
char *Str_concat(char s1[] , const char s2[]);

//---------------------------------------------------------------------------
//Str_compare is to compare the two string.  
//two parameters must a const string array,    
//Return Value is the signed integer which is greater , equal ,less than 
//zero ,Corresponding S1 ASCII value is greater , equal , less than S2 
//----------------------------------------------------------------------------
int Str_compare(const char s1[] , const char s2[]);

//----------------------------------------------------------------------------
//Str_getLength is to search S2 string whether or not is the substring in S1.  
//two parameters must a const string array,     
//Return Value is the address which point to the frist element of substring 
//which match S2 string in S1 string.
//---------------------------------------------------------------------------- 
char *Str_search( const char s1[] , const char s2[]);

//----------------------------------------------------------------------------
//Str_getLength is to get the length of cetain string.  
//the only parameter must a constant string array  
//Return Value is size_t typed integer.
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//Functions below from source file "strp.c"
//all the functions has same affect as the function above.
//----------------------------------------------------------------------------
size_t Str_getLength(const char *string);
char *Str_copy(char *Dst , const char *Src);
char *Str_concat(char *Dst , const char *Src);
int Str_compare(const char *s1 , const char *s2);
char *Str_search( const char *s1 , const char *s2);
