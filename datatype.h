#include <inttypes.h>

#define INSTRUCTION_MAX_LEN 10
#define NUMBER_MAX_LEN 10
#define REGISTER_MAX_LEN 1
#define WORD_SIZE 16

typedef enum
{
    INSTRUCTION,
    REGISTER,
    DIGIT,
    COMMA,
    END_OF_LINE,
    END
}  tokenType;


typedef struct
{
    union {
        char name[ 255 ];
        uint16_t number;
    } value;
    tokenType type;
} token;

typedef union 
{
    char name[ 255 ];
    uint16_t number;
    char binary[ WORD_SIZE + 1 ];
} oprand;

char *code; // I have to, at least for now.
