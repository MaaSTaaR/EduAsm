/**
 * Simple and Educational Assembler for EduVM (Educational Virtual Machine)
 *
 * The Parser
 *
 * Author : Mohammed Q. Hussain <MaaSTaaR@gmail.com>
 * Date : 21-5-2012
 * License : GNU GPL
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "lex.h"
#include "binary_system.h"
#include "list.h"

void get_register_bin( char *reg, char binary[] )
{
    char reg_bin[ WORD_SIZE + 1 ];
    
    if ( strcmp( reg, "a" ) == 0 )
        strcpy( binary, "0000000000000000" );
    else if ( strcmp( reg, "b" ) == 0 )
        strcpy( binary, "0000000000000001" );
    else if ( strcmp( reg, "c" ) == 0 )
        strcpy( binary, "0000000000000010" );
}

void readOprands( int number_of_oprands, tokenType types[], oprand values[] )
{
    int k;
    
    for ( k = 0; k < number_of_oprands; k++ )
    {
        token tok = getNextToken();
        
        if ( tok.type == types[ k ] )
        {
            if ( tok.type == REGISTER )
            {
                // The name of the register
                strcpy( values[ k ].name, tok.value.name ); // TODO : incorrect
                
                // The binary representation
                get_register_bin( tok.value.name, values[ k ].binary );
                
                if ( strcmp( tok.value.name, "a" ) == 0 )
                    values[ k ].number = 0;
                else if ( strcmp( tok.value.name, "b" ) == 0 )
                    values[ k ].number = 1;
                else if ( strcmp( tok.value.name, "c" ) == 0 )
                    values[ k ].number = 2;
            }
            else if ( tok.type == DIGIT )
            {
                // The binary representation
                dec_to_bin( tok.value.number, values[ k ].binary ); // TODO : incorrect
                
                // The decimal value
                values[ k ].number = tok.value.number;
            }
            
            // If the current oprand is not the last one, so check the comma
            if ( k != ( number_of_oprands - 1 ) )
            {
                tok = getNextToken();
            
                if ( tok.type == COMMA )
                {
                    continue;
                }
                else
                {
                    // Syntax Error
                    
                    return;
                }
            }
        }
        else
        {
            // Synatx error
            
            return;
        }
    }
}

char *parse_instruction( char *inst, llist *bytecode )
{
    if ( strcmp( inst, "mov" ) == 0 )
    {
        tokenType oprand_types[ 2 ] = { REGISTER, DIGIT };
        oprand values[ 2 ];
        char binary_number[ WORD_SIZE + 1 ];
        
        readOprands( 2, oprand_types, values );
        
        llist_add( bytecode, 0 );
        llist_add( bytecode, values[ 0 ].number );
        llist_add( bytecode, values[ 1 ].number );
        
        //printf( "0000000000000000 " );
        //printf( "%s %s\n", values[ 0 ].binary, values[ 1 ].binary );
    }
    else if ( strcmp( inst, "addr" ) == 0 )
    {
        tokenType oprand_types[ 3 ] = { REGISTER, REGISTER, REGISTER };
        oprand values[ 3 ];
        
        readOprands( 3, oprand_types, values );
        
        llist_add( bytecode, 1 );
        llist_add( bytecode, values[ 0 ].number );
        llist_add( bytecode, values[ 1 ].number );
        llist_add( bytecode, values[ 2 ].number );
        
        //printf( "0000000000000001 " );
        //printf( "%s %s %s\n", values[ 0 ].binary, values[ 1 ].binary, values[ 2 ].binary );
    }
    else if ( strcmp( inst, "addv" ) == 0 )
    {
        tokenType oprand_types[ 3 ] = { DIGIT, DIGIT, REGISTER };
        oprand values[ 3 ];
        
        readOprands( 3, oprand_types, values );
        
        llist_add( bytecode, 2 );
        llist_add( bytecode, values[ 0 ].number );
        llist_add( bytecode, values[ 1 ].number );
        llist_add( bytecode, values[ 2 ].number );
        
        //printf( "0000000000000010 " );
        //printf( "%s %s %s\n", values[ 0 ].binary, values[ 1 ].binary, values[ 2 ].binary );
    }
    else if ( strcmp( inst, "print" ) == 0 )
    {
        tokenType oprand_types[ 1 ] = { REGISTER };
        oprand values[ 1 ];
        
        readOprands( 1, oprand_types, values );
        
        llist_add( bytecode, 3 );
        llist_add( bytecode, values[ 0 ].number );
        
        //printf( "0000000000000011 " );
        //printf( "%s\n", values[ 0 ].binary );
    }
    else if ( strcmp( inst, "cpuid" ) == 0 )
    {
        llist_add( bytecode, 4 );
    }
    else
    {
        // No such instruction!
    }
}

void parse( llist *bytecode )
{
    token tok;
    
    do
    {
        tok = getNextToken();
        
        switch( tok.type )
        {
            case INSTRUCTION:
                parse_instruction( tok.value.name, bytecode );
                break;
        }
        
    } while ( tok.type != END );
}
