#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_


struct grid{
    int r;
    int c;
};

grid random_rc();
grid create_item_rc();

void create_item(const char * itemname);
void growth();
void poison();

void timetocreate();




#endif