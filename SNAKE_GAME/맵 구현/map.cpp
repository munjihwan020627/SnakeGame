#include<ncurses.h>
#include<time.h>
#include"items.h"


void printScorePlaytime(time_t start_time,int score){
    time_t in_time = time(nullptr);
    while (difftime(time(nullptr), start_time) < 1) {
    }
    mvprintw(0,25, "score : %d",score);
    mvprintw(11,25, "playtime : %ld", time(nullptr)- start_time );
    refresh();
}

void draw_maps() {
    int rows{22}; 
    int cols{22};
    
    int score{};
    time_t start_time = time(nullptr);
    
    
    

    mvaddch(0,0, 'X');
    mvaddch(22,22, 'X');
    mvaddch(22,0, 'X');
    mvaddch(0,22, 'X');


    for (int c = 1; c < cols; ++c) {
        mvaddch(0, c, '0');
        mvaddch(22, c, '0');

    }
    
    for (int r = 1; r < rows; ++r) {
        mvaddch(r,0, '0');
        mvaddch(r,22, '0');

    }



}





int main() {
    int score = 0;
    time_t start_time = time(nullptr);
    initscr();            
    cbreak();             
    noecho();             
    draw_maps();
time_t last_time_create = start_time; // timetocreate 마지막 실행 시간 저장
    while (true) {

        time_t current_time = time(nullptr);
        printScorePlaytime(start_time, score); // 항상 시간과 점수를 출력

        if (current_time - last_time_create >= 5) {
            timetocreate(); // 5초마다 호출
            last_time_create = current_time; // 마지막 실행 시간을 현재 시간으로 업데이트
        }

        refresh(); 
    }
    
    refresh();
        
    
    refresh();            
    getch();              
    endwin();             

    return 0;
}
