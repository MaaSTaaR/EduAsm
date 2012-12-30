#include <inttypes.h>

typedef struct _node
{
    uint16_t value;
    struct _node *next;
} node;

typedef struct _llist
{
    node *head,*tail;
} llist;

void llist_init( llist * );
void llist_add( llist *, uint16_t );
