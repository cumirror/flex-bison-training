#include <stdio.h>
#include <stdlib.h>
#include "application.h"

extern FILE* yyin;
extern int yyparse();
struct application_list* app_root = NULL;

void myparse()
{
  yyin = fopen("sig.conf", "r");

  if (!yyin)
    exit (2);

  yyparse();

  if (fclose (yyin) != 0)
    exit (3);
}

void dump_applications(struct application_list* root)
{
    struct application_s *app = NULL;
    struct sig_list *sigs = NULL;
    struct sig_s *sig = NULL;

    STAILQ_FOREACH(app, root, next) {
        printf("app\n\tappid    : %d\n", app->id);
        printf("\tcategory : 0x%x\n", app->category);
        printf("\tappname  : %s\n", app->name);
        sigs = app->sigs;
        STAILQ_FOREACH(sig, sigs, next) {
            printf("\tsig:\n\t\tid       : 0x%x\n", sig->id);
            printf("\t\tproto    : %d\n", sig->proto);
            printf("\t\ttype     : %d\n", sig->type);
            printf("\t\tenable   : %d\n", sig->enable);
            printf("\t\tpriority : %d\n", sig->priority);
            printf("\t\tdir      : %d\n", sig->dir);
            printf("\t\tmatch    : %s\n", sig->match);
        }
    }
}

int main(int argc, char **argv)
{
    myparse();
    dump_applications(app_root);
    return 0;
}
