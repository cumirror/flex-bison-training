#include <string.h>
#include <stdlib.h>
#include "key_pair.h"

inline struct key_pair_list* create_pair_list()
{
    struct key_pair_list *head =
        (struct key_pair_list *)malloc(sizeof(struct key_pair_list));

    if (head != NULL) {
        STAILQ_INIT(head);
    }

    return head;
}

inline struct key_pair_s* create_key_value_pair(char* key, char* value)
{
    struct key_pair_s *pair = NULL;
   
    pair = (struct key_pair_s *)malloc(sizeof(struct key_pair_s));

    if (pair != NULL) {
       pair->key = key;
       pair->value = value;
    }

    return pair;
}

inline uint get_int_value_from_key(struct key_pair_list* head, char* key)
{
    struct key_pair_s *pair; 
    uint value = 0;

    STAILQ_FOREACH(pair, head, next) {
        if (strcmp(pair->key, key) == 0) {
            value = strtol(pair->value, NULL, 0);            
            break;
        }
    }

    return value;
}

inline char* get_str_value_from_key(struct key_pair_list* head, char* key)
{
    struct key_pair_s *pair; 
    char *value = NULL;

    STAILQ_FOREACH(pair, head, next) {
        if (strcmp(pair->key, key) == 0) {
            value = pair->value;            
            break;
        }
    }

    return value;
}

inline static uint proto_to_value(char *proto)
{
    if (strcmp(proto, "UDP") == 0)
        return 1;
    if (strcmp(proto, "TCP") == 0)
        return 2;
    if (strcmp(proto, "HTTP") == 0)
        return 3;

    return 0;
}

inline uint get_sigProto_value(struct key_pair_list* head)
{
    struct key_pair_s *pair; 
    uint value = 0;

    STAILQ_FOREACH(pair, head, next) {
        if (strcmp(pair->key, "sig_proto") == 0) {
            value = proto_to_value(pair->value);            
            break;
        }
    }

    return value;
}

inline static uint matchType_to_value(char *type)
{
    if (strcmp(type, "AC") == 0)
        return 1;
    if (strcmp(type, "AC_MULTI") == 0)
        return 2;
    if (strcmp(type, "REGEX") == 0) 
        return 3;

    return 0;
}

inline uint get_matchType_value(struct key_pair_list* head)
{
    struct key_pair_s *pair; 
    uint value = 0;

    STAILQ_FOREACH(pair, head, next) {
        if (strcmp(pair->key, "sig_type") == 0) {
            value = matchType_to_value(pair->value);            
            break;
        }
    }

    return value;
}
