#include<stddef.h>
#include<assert.h>

size_t Str_getLength(const char *string)
{
    size_t strlength = 0;
    assert(string != NULL);
    for( ; *string != '\0' ; string++ )
    {
        strlength++;
    }
    return strlength;
}

char *Str_copy(char *Dst , const char *Src)
{
    char *pcDstEnd = Dst ;
    assert(Src != NULL && Dst != NULL);
    for ( ; *Src != '\0' ; pcDstEnd++,Src++)
        *pcDstEnd = *Src;
    *pcDstEnd = '\0';
    return Dst;
}

char *Str_concat(char *Dst , const char *Src)
{
    char *pcDstEnd = Dst ;
    size_t DstLength = Str_getLength(Dst);
    size_t SrcLength = Str_getLength(Src);
    assert(Dst != NULL && Src != NULL);
    pcDstEnd += DstLength; 
    for (size_t i = 0; i <= SrcLength; i++)
    {
        *pcDstEnd= *Src;
        pcDstEnd++;
        Src++; 
    }
    return Dst;
}

int Str_compare(const char *s1 , const char *s2)
{
    int cmpResult = 0;
    assert(s1 != NULL && s2 != NULL);
    while (1)
    {
        if (*s1 > *s2)
        {
            return(cmpResult + 1);
        } else if (*s1 < *s2)
        {
          return (cmpResult - 1);
        } else if(*s1 == '\0' && *s2 == '\0') 
        {
            return (cmpResult = 0);
        }
        s1 ++;
        s2 ++; 
    }
}

//A help function in order to implement function of *Str_search 
int Str_contain(const char *s1 , const char *s2)
{
    int isContained = 0;
    assert(s1 != NULL && s2 != NULL);
    while (*s1 != '\0' && *s2!= '\0')
    {
        if (*s1 == *s2)
        {
           isContained = 1;
        } 
        else return 0;
        s1 ++;
        s2 ++;
    }
    if (*s2 == '\0')
    {
        return isContained;
    }
    return 0; 
}

char *Str_search( const char *s1 , const char *s2)
{
    assert(s1 != NULL && s2 != NULL);

    if(Str_getLength(s2) == 0)
    {
        return (char *)s1;
    }
    else if(Str_getLength(s2) > Str_getLength(s1))
    {
        return NULL;    
    }
    else
    {
        while (*s1 != '\0')
        {
            if (Str_contain(s1 , s2))
                return (char *)s1;
            s1 ++;
        }
        return NULL;
    } 
}
