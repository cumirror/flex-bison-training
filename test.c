#include <stdio.h>
#include <stdlib.h>

extern FILE* yyin;
extern int yyparse();

void myparse()
{
  yyin = fopen("sig.conf", "r");

  if (!yyin)
    exit (2);

  yyparse();

  if (fclose (yyin) != 0)
    exit (3);
}

int main(int argc, char **argv)
{
    myparse();
    return 0;
}
