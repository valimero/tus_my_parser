#include "tus.h"


int tu_readint_test(char * str, int expected_pos, char * testname)
{
    struct parser *p_parser;
    p_parser = malloc(sizeof(struct parser));
    p_parser->content = str;
    p_parser->current_pos = 0;

    readint(p_parser);

    printf("\n");
    if(p_parser->current_pos != expected_pos)
    {
        printf("!!! tu_readint: error %s\n", testname);
        printf("expected parser->current_pos = %d but got %d\n", expected_pos, p_parser->current_pos);
        free(p_parser);
        return 0;
    }
    else {
        printf("tu_readint: %s: ok\n", testname);
        free(p_parser);
        return 1;
    }
}

int tu_readint()
{
    int error = 0;

    // Test 1
    error += tu_readint_test("1234567890", 10, "test1");
    
    // Test 2
    error +=tu_readint_test("123a123", 3, "test2");
    
    // Test 3
    error +=tu_readint_test("\0\0", 0, "test3");

    // Test 4
    error +=tu_readint_test("333e", 3, "test4");
    

    return error > 0 ? 1 : 0;
}