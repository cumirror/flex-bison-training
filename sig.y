%{
#include <stdio.h>

void yyerror(char *s)
{
    printf("ERROR: %s\n", s);
}

%}

%union {
    char* ptr;
};

%token <ptr> TOKEN_SYMBOL
%token <ptr> TOKEN_VALUE
%token TOKEN_COMMA TOKEN_LBRANCH TOKEN_RBRANCH TOKEN_APPLICATION

%type <ptr> app;
%type <ptr> key_value_pair;

%%
apps:
    apps app
    | app
    ;

app:
    TOKEN_APPLICATION TOKEN_LBRANCH key_value_list TOKEN_RBRANCH
    {
        printf("application\n");
    }

key_value_list:
    key_value_list key_value_pair
    {
        printf("list\n");
    }
    | key_value_pair
    {
        printf("pair\n");
    }
    ;

key_value_pair:
    TOKEN_SYMBOL TOKEN_VALUE TOKEN_COMMA
    {
        printf("%s-%s\n", $1, $2);
    }
    ;
%%

