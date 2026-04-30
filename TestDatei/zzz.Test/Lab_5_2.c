#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
   char **ptr = argv;

   if (argc < 2) 
   {
      printf("Error: At least one argument required.\n");
      return 1;  
   }
      

   for (int i = 0; i < argc; i++)
   {
      printf("Argument %d at address \"%p\" has content: %s (length: %zu)\n",i ,(void *)(*ptr) ,*ptr, strlen(*ptr));
      ptr++;
   }

    return 0;


}