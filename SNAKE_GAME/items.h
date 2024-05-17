#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

class item{
    public:

    int calldefcnt{-1}; // 함수 호출 횟수를 통해 아이템이 몇번 만들어졌는지를 측정함
    int snakeeatitem{0}; // 추후에 뱀이 아이템을 먹는 알고리즘 구현시 함수호출횟수에서 아이템 유지초수만큼을 빼줄예정

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
};






#endif
