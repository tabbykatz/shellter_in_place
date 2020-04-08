int _getline(char **lineptr, size_t *n, FILE *stream)
{
static char line[256];
char *ptr;
unsigned int len;

   if (lineptr == NULL || n == NULL)
   {
      errno = EINVAL;
      return -1;
   }

   if (ferror (stream))
      return -1;

   if (feof(stream))
      return -1;
     
   fgets(line,256,stream);

   ptr = _strchr(line,'\n');   
   if (ptr)
      *ptr = '\0';

   len = _strlen(line);
   
   if ((len+1) < 256)
   {
      ptr = _realloc(*lineptr, 256);
      if (ptr == NULL)
         return(-1);
      *lineptr = ptr;
      *n = 256;
   }

   _strcpy(*lineptr,line); 
   return(len);
}
