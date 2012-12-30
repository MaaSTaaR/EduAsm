#include <stdio.h>

void dec_to_bin( int value, char binary[] )
{
    // 16-bit
    if ( value > 65535 )
        return;
    
    int k,x;
    
    int bin_sign[ 16 ] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
    
    for ( k = 15, x = 0; k >= 0; k--, x++ )
    {
        if ( ( value - bin_sign[ k ] ) >= 0 )
        {
            binary[ x ] = '1';
            
            value = value - bin_sign[ k ];
        }
        else
        {
            binary[ x ] = '0';
        }
    }
    
    binary[ x ] = '\0';    
}
