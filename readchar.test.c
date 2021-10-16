#include "tus.h"


int tu_readchar_test(char * str, char c, int expected_pos, char * testname)
{
    struct parser *p_parser;
    p_parser = malloc(sizeof(struct parser));
    p_parser->content = str;
    p_parser->current_pos = 0;

    readchar(p_parser, c);

    printf("\n");
    if(p_parser->current_pos != expected_pos)
    {
        printf("!!! tu_readchar: error %s\n", testname);
        printf("expected parser->current_pos = %d but got %d\n", expected_pos, p_parser->current_pos);
        free(p_parser);
        return 0;
    }
    else {
        printf("tu_readchar: %s: ok\n", testname);
        free(p_parser);
        return 1;
    }
}

int tu_readchar()
{
    int error = 0;

    // Test 1
    error += tu_readchar_test("cbe", 'c', 1, "test1");
    
    // Test 2
    error +=tu_readchar_test("123", '2', 0, "test2");
    
    // Test 3
    error +=tu_readchar_test("0\0", '0', 1, "test3");

    // Test 4
    error +=tu_readchar_test("", '\0', 0, "test4");
    

    return error > 0 ? 1 : 0;
}