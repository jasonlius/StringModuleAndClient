/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Jason,L.                                                   */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
   size_t placeAcount = 0;
   size_t pcFromLength = Str_getLength(pcFrom);
   char headPcline[4096] ;
   char tailPcline[4096];
   char *pcContain;
   assert(pcLine != NULL && pcFrom != NULL && pcTo !=NULL);
   if(Str_getLength(pcFrom) == 0)
   {
      fprintf(stdout,"%s",pcLine);
      return 0;
   }else
   {
      while (Str_search(pcLine , pcFrom ) != NULL)
      {
         //------------------------------------------------------
         //当我们找到函数中有我们需要的替换的字符串时，我们定位到这个字符串
         //从这个位置将字符串截取成两段，分别保存起来为新的数组，然后将我们
         //需要替换的字符串与我们刚刚保存的新的数组拼接起来。
         //-------------------------------------------------------
         pcContain =Str_search(pcLine , pcFrom );
         *pcContain = '\0';
         (void)Str_copy(headPcline , pcLine);
         (void)Str_copy(tailPcline , pcContain+pcFromLength);
         (void)Str_concat( Str_concat(headPcline ,pcTo),tailPcline);
         (void)Str_concat( Str_concat(headPcline ,pcTo),tailPcline);
         (void)Str_copy((char *)pcLine , headPcline);
         //替换成功之后将替换次数++
         placeAcount ++;
      }     
   }
   return placeAcount;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL){
      //-----------------------------------------------
      //首先替换为中间字符“犇”的原因是为了该避免算法缺陷
      //这个算法无法替换相同的字符串 比如将 11 替换为111，
      //由于111里面本身包含11如果不进行中间替换会报错
      //------------------------------------------------
      (void)replaceAndWrite(acLine,pcFrom,"犇");
      uReplaceCount +=replaceAndWrite(acLine, "犇" , pcTo);
      printf("%s",acLine);
   }
   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
