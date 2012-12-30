/**
 * Simple and Educational Assembler for EduVM (Educational Virtual Machine)
 *
 * Simple linked-list implementation to represent the bytecode
 *
 * Author : Mohammed Q. Hussain <MaaSTaaR@gmail.com>
 * Date : 31-5-2012
 * License : GNU GPL
 */

#include <stdlib.h>
#include <inttypes.h>
#include "list.h"

void llist_init( llist *l )
{
    l->head = NULL;
}

void llist_add( llist *l, uint16_t val )
{
    node *new_node;
    
    new_node = malloc( sizeof( node ) );
    
    new_node->value = val;
    new_node->next = NULL;
    
    if ( l->head == NULL )
    {
        l->head = new_node;
        l->tail = new_node;        
    }
    else
    {
        l->tail->next = new_node;
        l->tail = new_node;
    }
}
