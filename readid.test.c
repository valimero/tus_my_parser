#include "tus.h"


int tu_readid_test(char * str, int expected_pos, int expected_return, char * testname)
{
    struct parser *p_parser;
    p_parser = malloc(sizeof(struct parser));
    p_parser->content = str;
    p_parser->current_pos = 0;

    int r;

    r = readid(p_parser);

    printf("\n");
    if(p_parser->current_pos != expected_pos || r != expected_return)
    {
        printf("!!! tu_readid: error %s\n", testname);
        printf("expected parser->current_pos = %d got %d\n", expected_pos, p_parser->current_pos);
        printf("expected return %d got %d\n", expected_return, r);
        free(p_parser);
        return 0;
    }
    else {
        printf("tu_readid: %s: ok\n", testname);
        free(p_parser);
        return 1;
    }
}

int tu_readid()
{
    int error = 0;

    // Test 1
    error += tu_readid_test("_asdasd8374_", 12, 1, "test1");
    
    // Test 2
    error +=tu_readid_test("_*asdasd8374_", 1, 1, "test2");
    
    // Test 3
    error +=tu_readid_test("\0\0", 0, 0, "test3");

    // Test 4
    error +=tu_readid_test("", 0, 0, "test4");

    // Test 5
    error +=tu_readid_test("_______*", 7, 1, "test5");
    

    return error > 0 ? 1 : 0;
}
