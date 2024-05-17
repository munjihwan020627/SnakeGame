#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "items.h"


// 아이템 x,y 좌표를 무작위로 지정해주기 위한 랜덤함수 
// 맵의 크기가 21이고 아이템은 벽에 생성될수 없기 때문에 1,1에서부터 19,19까지 출력되게끔 함
grid random_rc(){
    grid randomlocation;
    randomlocation.r = (rand() % 19) + 1;
    randomlocation.c = (rand() % 19) + 1;
    return randomlocation;
}

//아이템 생성 구현
grid create_item_rc(){
    grid item;
    // 아이템이 잘못된데에 생성(벽이나 snake몸체나 머리에 생성)되지 않을때까지 생성 
    while(true){
    item = random_rc();
    if ((mvinch(item.r,item.c) & A_CHARTEXT) == ' '){
        break;
    }
    }
    
    return item;
}



void create_item(const char * itemname){
    grid item;
    item = create_item_rc();

    // G라는 글씨를  growth아이템으로 설정하며 x,y에 작성함
    mvprintw(item.r, item.c, itemname);
    refresh();

    // 시작시간을 time(nullptr)로 지정함  
    time_t start_time = time(nullptr);

    // 5 초 동안 대기하면서 while문 돌기
    while (difftime(time(nullptr), start_time) < 5) {
    }

    // 5초 이후엔 해당 위치에 공백 문자 출력
    mvprintw(item.r,item.c, " ");
    refresh();
}



void growth(){
    create_item("G");
}

void poison(){
    create_item("P");
}


void timetocreate() {
    while (true) {
        growth();
        poison();
    }
}
