#include <ncurses.h>
#include<cstdlib> // for rand()
#include<vector> //to make snake[]
#include<time.h>
#include<unistd.h> //for use usleep(time)
using namespace std;

class Position{
public:
    int x;
    int y;
    Position(int a = 3, int b =3){
        x = a;
        y = b;
    }
};
void DrawMap();
void DrawSnake();
void MoveSnake();

bool GameOver = false;
int MaxHeight(25),MaxWidth(25);
int map[25][25] = {0};
vector<Position> snake;
const char wall_char = '1';
const char iwall_char = '2';
const char snake_char = '3';
const char fruit_char = '4';
const char poison_char = '5';
const char space_char = ' ';
int dir = 1;

int main()
{
    initscr(); // to use ncurses
    noecho(); // not to  display input
    nodelay(stdscr,TRUE); //for input
    curs_set(0); // nocurser

    //  making map;
    for(int i = 0; i < MaxHeight;i++){
        for(int j = 0;  j < MaxWidth; j++){
            if( i == 0 || i == MaxHeight-1 || j ==0 || j == MaxWidth-1){
                map[i][j] = 1;
            }
        }
    }
    map[0][0] = 2;
    map[0][MaxWidth-1] = 2;
    map[MaxHeight-1][0] =2;
    map[MaxHeight-1][MaxWidth-1] = 2;

    DrawMap();
    DrawSnake();
    refresh();

    while(!GameOver){
        MoveSnake();
        refresh();
        usleep ( 100000 );
    }

    endwin();
    return 0;
}

void DrawMap(){
    for(int i = 0; i < MaxHeight;i++){
        for(int j = 0;  j < MaxWidth; j++){
            switch (map[i][j]) {
                case 0:
                    mvaddch(i,j,' ');
                    break;
                case 1:
                    mvaddch(i,j,'1');
                    break;
                case 2:
                    mvaddch(i,j,'2');
                    break;
                case 3:
                    mvaddch(i,j,'3');
                    break;
                case 4:
                    mvaddch(i,j,'4');
                    break;
                case 5:
                    mvaddch(i,j,'5');
                    break;
            }
        }
    }
}
void DrawSnake(){
    for(int i=0; i < 3; i++){
        snake.push_back(Position(10,4+i));
    }
    for(int i =0; i<snake.size();i++){
        mvaddch(snake[i].x,snake[i].y,'3');
    }
}
void MoveSnake(){
    char input = getch();
    switch (input) {
        case 'w':
            if(dir == 3)
                GameOver = true;
            else
                dir =1;
            break;
        case 'a':
            if(dir == 4) GameOver = true;
            else dir =2;
            break;
        case 's':
            if(dir == 1) GameOver = true;
            else dir = 3;
            break;
        case 'd':
            if(dir == 2) GameOver = true;
            else dir = 4;
            break;
        case 'q':
            GameOver = true;
            break;
    }
    int snakeX = snake.front().x;
    int snakeY = snake.front().y;

    mvprintw(snake[snake.size()-1].x,snake[snake.size()-1].y," ");
    snake.pop_back();
    if(dir == 1){
        snakeX--;
    }
    else if(dir == 2){
        snakeY--;
    }
    else if(dir == 3){
        snakeX++;
    }
    else if(dir == 4) {
        snakeY++;
    }
    mvaddch(snakeX,snakeY,'3');
    snake.insert(snake.begin(),Position(snakeX,snakeY) );

    if(map[snake.front().x][snake.front().y] == 1){
        GameOver =true;
    }
    map[snakeX][snakeY] = 3;
    refresh();
    usleep ( 50000 );

}
