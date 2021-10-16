#include "tus.h"


int tu_readfloat_test(char * str, int expected_pos, int expected_return, char * testname)
{
    struct parser *p_parser;
    p_parser = malloc(sizeof(struct parser));
    p_parser->content = str;
    p_parser->current_pos = 0;

    int r;

    r = readfloat(p_parser);

    printf("\n");
    if(p_parser->current_pos != expected_pos || r != expected_return)
    {
        printf("!!! tu_readfloat: error %s\n", testname);
        printf("expected parser->current_pos = %d got %d\n", expected_pos, p_parser->current_pos);
        printf("expected return %d got %d\n", expected_return, r);
        free(p_parser);
        return 0;
    }
    else {
        printf("tu_readfloat: %s: ok\n", testname);
        free(p_parser);
        return 1;
    }
}

int tu_readfloat()
{
    int error = 0;

    // Test 1
    error += tu_readfloat_test("-123.234E-12", 12, 1, "test1");
    
    // Test 2
    error +=tu_readfloat_test("_*asdasd8374_", 0, 0, "test2");
    
    // Test 3
    error +=tu_readfloat_test("\0\0", 0, 0, "test3");

    // Test 4
    error +=tu_readfloat_test("-+---+++-+++++----06969.123", 27, 1, "test4");

    // Test 5
    error +=tu_readfloat_test("-+---+++-+++++----.123e90069", 28, 1, "test5");
    
    // Test 6
    error +=tu_readfloat_test("_______*", 0, 0, "test6");

    error +=tu_readfloat_test(".9", 2, 1, "test7");
    
    return error > 0 ? 1 : 0;
}
