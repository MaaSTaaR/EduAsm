/**
 * Simple and Educational Assembler for EduVM (Educational Virtual Machine)
 *
 * Lexical Analyzer
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

token getNextToken()
{
    int k;
    token currToken;
    
    //printf( "Current Code : %p, Value : %c\n", code, *code );
    
    while ( !isspace( *code ) )
    {
        if ( isalpha( *code ) )
        {
            char inst[ INSTRUCTION_MAX_LEN + 1 ];
            
            k = 0;
            
            // Get the instruction
            while ( !isspace( *code ) && *code != ';' )
            {
                inst[ k++ ] = *code;
        
                code++;
            }
            
            inst[ k ] = '\0';
            
            currToken.type = INSTRUCTION;
            strcpy( currToken.value.name, inst );
            
            break;
        }
        else if ( isdigit( *code ) )
        {
            char digit[ NUMBER_MAX_LEN + 1 ];
            
            k = 0;
            
            while ( isdigit( *code ) )
            {
                digit[ k++ ] = *code;
        
                code++;
            }
            
            digit[ k ] = '\0';
            
            currToken.type = DIGIT;
            currToken.value.number = (int) atoi( digit );
            
            break;
        }
        else if ( *code == '$' )
        {
            char reg[ 2 ];
            
            reg[ 0 ] = *( ++code );
            reg[ 1 ] = '\0';
            
            currToken.type = REGISTER;
            strcpy( currToken.value.name, reg );
            
            code++;
            
            break;
        }
        else if ( *code == ',' )
        {
            currToken.type = COMMA;
            strcpy( currToken.value.name, "," );
            
            code++;
            
            break;
        }
        else if ( *code == ';' )
        {
            currToken.type = END_OF_LINE;
            strcpy( currToken.value.name, ";" );
            
            code++;
            
            break;
        }
        else if ( *code == '/' )
        {
            if ( *( ++code ) == '/' )
                while ( ( isalpha( *code ) || isspace( *code ) ) && *code != '\n' ) code++;

            break;
        }
        else if ( *code == '\0' )
        {
            currToken.type = END;
            strcpy( currToken.value.name, "" );
            
            return currToken;
        } 
        
        code++;
    }
    
    // Eat spaces for the next token
    while ( isspace( *code ) ) code++;
    
    return currToken;
}
