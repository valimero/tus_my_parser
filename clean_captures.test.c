#include "tus.h"


int verify_clean_capture_list(struct capture_list *c)
{
    if(c == NULL) return 0;
    else {
        printf("NOT CLEAN: %s", c->tagname);
        return 1;
    }
}

int                     tu_clean_captures()
{
    // Build captre_list
    struct capture_list *c5 = malloc(sizeof(struct capture_list));
    c5->tagname = "tagname->c5";
    c5->begin = 1;
    c5->end = 10;

    struct capture_list *c4 = malloc(sizeof(struct capture_list));
    c4->tagname = "tagname->c4";
    c4->begin = 1;
    c4->end = 10;
    c4->next = c5;

    struct capture_list *c3 = malloc(sizeof(struct capture_list));
    c3->tagname = "tagname->c3";
    c3->begin = 1;
    c3->end = 10;
    c3->next = c4;

    struct capture_list *c2 = malloc(sizeof(struct capture_list));
    c2->tagname = "tagname->c2";
    c2->begin = 1;
    c2->end = 10;
    c2->next = c3;
    
    struct capture_list *c1 = malloc(sizeof(struct capture_list));
    c1->tagname = "tagname->c1";
    c1->begin = 1;
    c1->end = 10;
    c1->next = c2;


    clean_captures(&c1);

    if (verify_clean_capture_list(c1) ||
        verify_clean_capture_list(c2) ||
        verify_clean_capture_list(c3) ||
        verify_clean_capture_list(c4) ||
        verify_clean_capture_list(c5)) 
    {
        printf("\n!!!! ERROR tu_clean_captures !!!!\n");
        return 1;
    }

    return 0;
}

