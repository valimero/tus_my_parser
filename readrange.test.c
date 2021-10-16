#include "tus.h"


int tu_readrange_test(char * str, char b, char e, int expected_pos, char * testname)
{
    struct parser *p_parser;
    p_parser = malloc(sizeof(struct parser));
    p_parser->content = str;
    p_parser->current_pos = 0;

    readrange(p_parser, b, e);

    printf("\n");
    if(p_parser->current_pos != expected_pos)
    {
        printf("!!! tu_readrange: error %s\n", testname);
        printf("expected parser->current_pos = %d but got %d\n", expected_pos, p_parser->current_pos);
        free(p_parser);
        return 0;
    }
    else {
        printf("tu_readrange: %s: ok\n", testname);
        free(p_parser);
        return 1;
    }
}

int tu_readrange()
{
    int error = 0;

    // Test 1
    error += tu_readrange_test("val", 'a', 'b', 0, "test1");
    
    // Test 2
    error +=tu_readrange_test("al", 'a', 'b', 1, "test2");
    
    // Test 3
    error +=tu_readrange_test("caaaaa", 'a', 'b', 0, "test3");

    // Test 4
    error +=tu_readrange_test("aaaaaa", 'a', 'b', 1, "test4");
    

    return error > 0 ? 1 : 0;
}
