#ifndef __KEY_PAIR_H__
#define __KEY_PAIR_H__

#include "queue.h"
#include "types.h"

struct key_pair_s {
	char* key;
	char* value;
	STAILQ_ENTRY(key_pair_s) next;
};
STAILQ_HEAD(key_pair_list, key_pair_s);

struct key_pair_list* create_pair_list();
struct key_pair_s* create_key_value_pair(char* key, char* value);
uint get_int_value_from_key(struct key_pair_list* head, char* key);
char* get_str_value_from_key(struct key_pair_list* head, char* key);
uint get_sigProto_value(struct key_pair_list* head);
uint get_matchType_value(struct key_pair_list* head);
#endif
