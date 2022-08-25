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

char *Str_copy(char Dst[] , const char Src[])
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

char *Str_concat(char s1[] , const char s2[])
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
    int cmpResult = 0;
    assert(s1 != NULL && s2 != NULL);

    while (1)
    {
        if (s1[index] > s2[index])
        {
            return(cmpResult + 1);
        } else if (s1[index] < s2[index])
        {
          return (cmpResult - 1);
        } else if(s1[index] == '\0' && s2[index] == '\0') 
        {
            return (cmpResult = 0);
        }
        index ++; 
    }
}

//A help function in order to implement function of *Str_search 
int Str_contain(const char s1[] , const char s2[])
{
    size_t index = 0;
    int isContained = 0;
    assert(s1 != NULL && s2 != NULL);
    while (s1[index] != '\0' && s2[index] != '\0')
    {
        if (s1[index] == s2[index])
        {
           isContained = 1;
        } 
        else return 0;
        index ++; 
    }
    if (s2[index] == '\0')
    {
        return isContained;
    }
    return 0; 
}

char *Str_search( const char s1[] , const char s2[])
{
    size_t index = 0;
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
        while (s1[index] != '\0')
        {
            if (Str_contain(&s1[index] , s2))
                return (char *)&s1[index];
            index ++;
        }
        return NULL;
    } 
}
