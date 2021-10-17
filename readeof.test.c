#include "tus.h"


int tu_readeof_test(char * str, int expected_pos, int expected_return, char * testname)
{
    struct parser *p_parser = new_parser(str);
    // p_parser = malloc(sizeof(struct parser));
    // p_parser->content = str;
    // p_parser->current_pos = 0;

    int r;

    r = readeof(p_parser);
    int current_pos = p_parser->current_pos;

    clean_parser(p_parser);


    printf("\n");
    if(current_pos != expected_pos || r != expected_return)
    {
        printf("!!! tu_readeof: error %s\n", testname);
        printf("expected parser->current_pos = %d got %d\n", expected_pos, current_pos);
        printf("expected return %d got %d\n", expected_return, r);
        return 0;
    }
    else {
        printf("tu_readeof: %s: ok\n", testname);
        return 1;
    }
}

int tu_readeof()
{
    int error = 0;

    // Test 1
    error += tu_readeof_test("\0", 0, 1, "test1");
    
    // Test 2
    error +=tu_readeof_test("1\0", 0, 0, "test2");
    
    // Test 3
    error +=tu_readeof_test("\0\0", 0, 1, "test3");

    // Test 4
    error +=tu_readeof_test("", 0, 1, "test4");

    error +=tu_readeof_test("\n", 0, 0, "test5");
    

    return error > 0 ? 1 : 0;
}
