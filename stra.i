# 1 "stra.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 370 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "stra.c" 2
# 1 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.1.6/include/stddef.h" 1 3
# 35 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.1.6/include/stddef.h" 3
typedef long int ptrdiff_t;
# 46 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.1.6/include/stddef.h" 3
typedef long unsigned int size_t;
# 74 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.1.6/include/stddef.h" 3
typedef int wchar_t;
# 102 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.1.6/include/stddef.h" 3
# 1 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.1.6/include/__stddef_max_align_t.h" 1 3
# 16 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.1.6/include/__stddef_max_align_t.h" 3
typedef long double max_align_t;
# 103 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.1.6/include/stddef.h" 2 3
# 2 "stra.c" 2
# 1 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/assert.h" 1 3 4
# 42 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/assert.h" 3 4
# 1 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 1 3 4
# 659 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 3 4
# 1 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h" 1 3 4
# 660 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 2 3 4
# 725 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 3 4
# 1 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h" 1 3 4
# 726 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 2 3 4
# 43 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/assert.h" 2 3 4
# 82 "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/assert.h" 3 4
void __assert_rtn(const char *, const char *, int, const char *) __attribute__((__noreturn__)) __attribute__((__cold__)) __attribute__((__disable_tail_calls__));
# 3 "stra.c" 2
size_t Str_getLength(const char string[])
{
    size_t strlength = 0;
    (__builtin_expect(!(string != ((void*)0)), 0) ? __assert_rtn(__func__, "stra.c", 6, "string != NULL") : (void)0);

    while (string[strlength] != '\0' )
    {
        strlength++;
    }
    return strlength;
}

char *Str_copy(char Src[] , char Dst[])
{
    size_t Index = 0 ;
    (__builtin_expect(!(Src != ((void*)0) && Dst != ((void*)0)), 0) ? __assert_rtn(__func__, "stra.c", 18, "Src != NULL && Dst != NULL") : (void)0);
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
    (__builtin_expect(!(s1 != ((void*)0) && s2 != ((void*)0)), 0) ? __assert_rtn(__func__, "stra.c", 32, "s1 != NULL && s2 != NULL") : (void)0);

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
    (__builtin_expect(!(s1 != ((void*)0) && s2 != ((void*)0)), 0) ? __assert_rtn(__func__, "stra.c", 45, "s1 != NULL && s2 != NULL") : (void)0);

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

char *Str_search( char s1[] , char s2[])
{
    size_t index = 0 ;
    (__builtin_expect(!(s1 != ((void*)0) && s2 != ((void*)0)), 0) ? __assert_rtn(__func__, "stra.c", 66, "s1 != NULL && s2 != NULL") : (void)0);

    if(Str_getLength(s2) == 0)
        return s1;
    while (s1[index] != '\0')
    {
        if (!Str_compare(&s1[index] , s2))
        {
            return &s1[index];
        }
    }
       return ((void*)0);
}
