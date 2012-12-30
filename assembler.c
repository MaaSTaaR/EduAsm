/**
 * Simple and Educational Assembler for EduVM (Educational Virtual Machine)
 *
 * Author : Mohammed Q. Hussain <MaaSTaaR@gmail.com>
 * Date : 20-5-2012
 * License : GNU GPL
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "parser.h"

char *getText( char *filename )
{
    FILE *fp;
    int code_size;
    char *ret_text,*text;
    
    // Open the assembly code
    fp = fopen( filename, "r" );
    
    // ... //
    
    // Get the size of code for malloc
    
    fseek( fp, 0, SEEK_END );
    
    code_size = ftell( fp );
    
    fseek( fp, 0, SEEK_SET );
    
    // ... //
    
    text = (char *) malloc( ( code_size * sizeof( char ) ) + 1 ); // Yeah, I know that sizeof( char ) = 1 :-)
    
    ret_text = text;
        
    // ... //
    
    while ( !feof( fp ) )
    {
        *text = getc( fp );
        
        text++;
    }
    
    *text = '\0';
    
    fclose( fp );
    
    return ret_text;
}


int main( int argv, char *args[] )
{
    llist *bytecode;
    FILE *output;
    
    if ( argv == 1 )
    {
        printf( "Error : Please write the assembly filename as an argument\n" );
        return EXIT_FAILURE;
    }
    
    bytecode = malloc( sizeof( llist ) );
    
    llist_init( bytecode );
    
    code = getText( args[ 1 ] );
    
    parse( bytecode );
    
    // ... //
    
    node *curr;
    
    output = fopen( "a.edu", "wb" );
    
    curr = bytecode->head;
    
    while ( curr != NULL )
    {
        fwrite( &curr->value, sizeof( curr->value ), 1, output );
        
        curr = curr->next;
    }
    
    fclose( output );
    
    // ... //
    
    return 0;
}
