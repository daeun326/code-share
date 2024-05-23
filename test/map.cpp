#include "header/snake_game.h"

void drawMap(){
    
// 윗면 그리기
    for (int i = 0; i < SCREEN_WIDTH; ++i) {
        mvaddch(0, i, '#');
    }

    // 아랫면 그리기
    for (int i = 0; i < SCREEN_WIDTH; ++i) {
        mvaddch(19, i, '#');
    }

    // 왼쪽 세로줄 그리기 (윗부분)
    for (int i = 1; i < 5; ++i) {
        mvaddch(i, 0, '#');
    }

    // 왼쪽 세로줄 그리기 (아랫부분)
    for (int i = 15; i < 19; ++i) {
        mvaddch(i, 0, '#');
    }

    // 오른쪽 세로줄 그리기 (윗부분)
    for (int i = 1; i < 5; ++i) {
        mvaddch(i, SCREEN_WIDTH - 1, '#');
    }

    // 오른쪽 세로줄 그리기 (아랫부분)
    for (int i = 15; i < 19; ++i) {
        mvaddch(i, SCREEN_WIDTH - 1, '#');
    }

    // 중앙 윗변 그리기
    for (int i = 0; i < 10; ++i) {
        mvaddch(5, i, '#');
    }
    for (int i = SCREEN_WIDTH - 10; i < SCREEN_WIDTH; ++i) {
        mvaddch(5, i, '#');
    }

    // 중앙 아랫변 그리기
    for (int i = 0; i < 10; ++i) {
        mvaddch(14, i, '#');
    }
    for (int i = SCREEN_WIDTH - 10; i < SCREEN_WIDTH; ++i) {
        mvaddch(14, i, '#');
    }

    // 중앙 왼쪽 세로줄 그리기 (I의 중앙 부분)
    for (int i = 6; i < 14; ++i) {
        mvaddch(i, 10, '#');
    }

    // 중앙 오른쪽 세로줄 그리기 (I의 중앙 부분)
    for (int i = 6; i < 14; ++i) {
        mvaddch(i, SCREEN_WIDTH - 11, '#');
    }
}