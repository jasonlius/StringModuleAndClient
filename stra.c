#include<stddef.h>
#include<assert.h>
size_t Str_getLength(const char string[])
{
    size_t strlength = 0;
    assert(string != NULL);
    
    while (string[strlength] != '\0' )
    {
        strlength++;
    }
    return strlength;
}

char *Str_copy(char Src[] , char Dst[])
{
    size_t Index = 0 ;
    assert(Src != NULL && Dst != NULL);
    while (Src[Index] != '\0')
    {
        Dst[Index] = Src[Index];
        Index++;
    }
    Dst[Index] = '\0';
    return Dst;
}

char *Str_concat(char s1[] , char s2[])
{
    size_t s1Length = Str_getLength(s1);
    size_t s2Length = Str_getLength(s2);
    assert(s1 != NULL && s2 != NULL);

    for (size_t i = 0; i <= s2Length; i++)
    {
        s1[s1Length+i] =s2[i]; 
    }
    return s1;
}

int Str_compare(const char s1[] , const char s2[])
{
    size_t index = 0;
    int cmpResult=0;
    assert(s1 != NULL && s2 != NULL);

    while (s1[index] !='\0' && s2[index] !='\0')
    {
        if (s1[index] > s2[index])
        {
            return(cmpResult + 1);
        } else if (s1[index] < s2[index])
        {
            return cmpResult - 1;
        } else
        {
            cmpResult =0;
        }
    }
    return cmpResult;
}

char *Str_search( char s1[] ,  char s2[])
{
    size_t index = 0 ;
    assert(s1 != NULL && s2 != NULL);

    if(Str_getLength(s2) == 0)
        return s1;
    while (s1[index] != '\0')
    {
        if (!Str_compare(&s1[index] , s2))
        {
            return &s1[index];
        }
    }
       return NULL;
}
