#include<stdio.h>
#include<string.h>
#include"stra.c"
int main()
{
      const char acHaystack[] = "abcde";
      const char acNeedle[] = "d";
      const char *pcResult1 = Str_search(acHaystack, acNeedle);
      char *pcResult2 = strstr(acHaystack, acNeedle);
   printf("iResult2 = %d,iResult1 =%d \n",*pcResult1,*pcResult2);
   return 0;
}