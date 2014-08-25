#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "queue.h"
#include "types.h"

#define MAX_APP_LENGTH 16
#define MAX_SIG_LENGTH 64

struct sig_s {
	uint id;
	uint proto;
	uint type;
	uint enable;
	uint priority;
	uint dir;
	char match[MAX_SIG_LENGTH];
	STAILQ_ENTRY(sig_s) next;
};
STAILQ_HEAD(sig_list, sig_s);

struct application_s {
	uint id;
	uint category;
	char name[MAX_APP_LENGTH];
    struct sig_list* sigs;
	STAILQ_ENTRY(application_s) next;
};
STAILQ_HEAD(application_list, application_s);

struct sig_list* create_sig_list();
struct sig_s* create_sig();
struct application_s* create_application();
struct application_list* create_application_list();
#endif
