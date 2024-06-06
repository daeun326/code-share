#include "header/snake_game.h"

void drawScreen() {
    // 화면 클리어
    clear();

    drawMap(mapState);

    // 먹이 그리기
    attron(COLOR_PAIR(2)); 
    mvaddch(foodY, foodX, '@');
    attroff(COLOR_PAIR(2)); 

    //독 그리기
    attron(COLOR_PAIR(3)); 
    mvaddch(poisonY, poisonX, '%');
    attroff(COLOR_PAIR(3)); 

    // 더블 그리기
    attron(COLOR_PAIR(4)); 
    mvaddch(doubleY, doubleX, '&');
    attroff(COLOR_PAIR(4)); 

    // 스네이크 그리기
    attron(COLOR_PAIR(1)); // 색상 쌍 1 사용
    for (int i = 0; i < snakeLength; ++i) {
        mvaddch(snakeY[i], snakeX[i], 'O');
    }
    attroff(COLOR_PAIR(1)); 

    // 게이트 그리기
    mvaddch(portal1Y, portal1X, ' ');
    mvaddch(portal2Y, portal2X, ' ');

    // Score Board 표시
    auto now = std::chrono::steady_clock::now();
    int gameTimeSeconds = std::chrono::duration_cast<std::chrono::seconds>(now - gameStartTime).count();
    float B = static_cast<float>(snakeLength) / MAX_LENGTH;
    mvprintw(1, SCREEN_WIDTH + 5, "Score Board");
    mvprintw(3, SCREEN_WIDTH + 5, "B: %.2f", B);
    mvprintw(4, SCREEN_WIDTH + 5, "+: %d", growthItemCount);
    mvprintw(5, SCREEN_WIDTH + 5, "-: %d", poisonItemCount);
    mvprintw(6, SCREEN_WIDTH + 5, "G: %d", gateCount); // 게이트 사용 횟수, 필요시 수정
    mvprintw(8, SCREEN_WIDTH + 5, "Time: %d seconds", gameTimeSeconds);

    // Mission 표시
    mvprintw(10, SCREEN_WIDTH + 5, "Mission");
    mvprintw(11, SCREEN_WIDTH + 5, "B: 10 (%s)", (snakeLength >= 10 ? "v" : " "));
    mvprintw(12, SCREEN_WIDTH + 5, "+: 5 (%s)", (growthItemCount >= 5 ? "v" : " "));
    mvprintw(13, SCREEN_WIDTH + 5, "-: 2 (%s)", (poisonItemCount >= 2 ? "v" : " "));
    mvprintw(14, SCREEN_WIDTH + 5, "G: 1 (%s)", (gateCount >= 1 ? "v" : " ")); // 게이트 사용 횟수, 필요시 수정
    refresh(); // 화면 업데이트
}
