#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "items.h"


// 아이템 x,y 좌표를 무작위로 지정해주기 위한 랜덤함수 
// 맵의 크기가 21이고 아이템은 벽에 생성될수 없기 때문에 1,1에서부터 19,19까지 출력되게끔 함
item::grid item::random_rc(){
    item::grid randomlocation;
    randomlocation.r = (rand() % 19) + 1;
    randomlocation.c = (rand() % 19) + 1;
    return randomlocation;
}

//아이템 생성 구현
item::grid item::create_item_rc(){
    item::grid item;
    // 아이템이 잘못된데에 생성(벽이나 snake몸체나 머리에 생성)되지 않을때까지 생성 
    while(true){
    item = random_rc();
    if ((mvinch(item.r,item.c) & A_CHARTEXT) == ' '){
        break;
    }
    }
    
    return item;
}



void item::create_item(const char * itemname){
    item::grid item;
    item = create_item_rc();

    // G라는 글씨를  growth아이템으로 설정하며 x,y에 작성함
    mvprintw(item.r, item.c, itemname);
    refresh();

    // 시작시간을 time(nullptr)로 지정함  
    time_t start_time = time(nullptr);

    bool temp = true;
    while (temp){
        if(difftime(time(nullptr), start_time) >= 5){
        mvprintw(item.r,item.c, " ");
        temp = false;
        }
    }


    // 5초 이후엔 해당 위치에 공백 문자 출력
    refresh();
}



void item::growth(){
    create_item("G");
}

void item::poison(){
    create_item("P");
}


void item::timetocreate() {
    while (true) {
        int i = rand() % 2;
        if (i==0){growth();}
        else {poison();}
        }
}

