#include "tus.h"

int tu_readtext_test(char * str, char *c, int expected_pos, char * testname)
{
    struct parser *p_parser;
    p_parser = malloc(sizeof(struct parser));
    p_parser->content = str;
    p_parser->current_pos = 0;

    readtext(p_parser, c);

    printf("\n");
    if(p_parser->current_pos != expected_pos)
    {
        printf("!!! tu_readtext: error %s\n", testname);
        printf("expected parser->current_pos = %d but got %d\n", expected_pos, p_parser->current_pos);
        free(p_parser);
        return 0;
    }
    else {
        printf("tu_readtext: %s: ok\n", testname);
        free(p_parser);
        return 1;
    }
}

int tu_readtext()
{
    int error = 0;

    // Test 1
    error += tu_readtext_test("cbe", "cbe", 3, "test1");
    
    // Test 2
    error +=tu_readtext_test("123", "2", 0, "test2");
    
    // Test 3
    error +=tu_readtext_test("0/0", "0/", 2, "test3");

    // Test 4
    error +=tu_readtext_test("poopasdasd", "poop", 4, "test4");

    // Test 5
    error +=tu_readtext_test("hello world", "hello", 5, "test5");
    
    return error > 0 ? 1 : 0;
}