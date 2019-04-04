// File.cpp

#include "File.h"

#include <stdlib.h>
#include <stdio.h>

// Reads an entire file and null-terminates the string it returns
char* readEntireFile(const char* path) {
   char* buffer = NULL;
   long bufferSize, readSize;
   FILE* file = fopen(path, "rb");

   if (file == NULL) {
     printf("Failed to open file '%s\'\n", path);
     fclose(file);
     return buffer;
   }

   fseek(file, 0, SEEK_END);

   bufferSize = ftell(file);

   rewind(file);

   buffer = (char*)malloc(sizeof(char) * bufferSize);

   readSize = fread(buffer, sizeof(char), bufferSize, file);
   buffer[readSize] = 0;

   if (bufferSize != readSize) {
     free(buffer);
     buffer = NULL;
   }

   fclose(file);
   return buffer;
}