#include <string.h>
#include <stdlib.h>
#include "application.h"

inline struct sig_list* create_sig_list()
{
    struct sig_list *head =
        (struct sig_list *)malloc(sizeof(struct sig_list));

    if (head != NULL) {
        STAILQ_INIT(head);
    }

    return head;
}

inline struct sig_s* create_sig()
{
    struct sig_s *sig =
        (struct sig_s *)malloc(sizeof(struct sig_s));

    return sig;
}

inline struct application_s* create_application()
{
    struct application_s *app =
        (struct application_s *)malloc(sizeof(struct application_s));

    return app;
}

inline struct application_list* create_application_list()
{
    struct application_list *head =
        (struct application_list *)malloc(sizeof(struct application_list));

    if (head != NULL) {
        STAILQ_INIT(head);
    }

    return head;
}

