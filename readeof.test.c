#include "tus.h"


int tu_readeof_test(char * str, int expected_pos, char * testname)
{
    struct parser *p_parser;
    p_parser = malloc(sizeof(struct parser));
    p_parser->content = str;
    p_parser->current_pos = 0;

    readeof(p_parser);

    printf("\n");
    if(p_parser->current_pos != expected_pos)
    {
        printf("!!! tu_readeof: error %s\n", testname);
        printf("expected parser->current_pos = %d but got %d\n", expected_pos, p_parser->current_pos);
        free(p_parser);
        return 0;
    }
    else {
        printf("tu_readeof: %s: ok\n", testname);
        free(p_parser);
        return 1;
    }
}

int tu_readeof()
{
    int error = 0;

    // Test 1
    error += tu_readeof_test("\0", 1, "test1");
    
    // Test 2
    error +=tu_readeof_test("1\0", 0, "test2");
    
    // Test 3
    error +=tu_readeof_test("\0\0", 1, "test3");

    // Test 4
    error +=tu_readeof_test("", 1, "test4");
    

    return error > 0 ? 1 : 0;
}