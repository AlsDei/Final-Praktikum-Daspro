#include <stdio.h>

const int M = 8;
const int N = 8;

int jalan = 0;
int map[M][N];

int isValid(int x, int y, int visit[M][N]) {
    return (x >= 0 && x < M && y >= 0 && y < N && map[x][y] == 0 && visit[x][y] == 0 && map[x][y] % 2 == 1);
}

void dfs(int x, int y, int visit[M][N], int i, int j){
    if(x == i && y == j){
        jalan++;
        return;
    }


}

int paths(int i, int j, int x, int y){
    int visit[N][M] = {0};
    visit[i][j] = 1;
    dfs(i, j, visit, x, y);

}
int main()
{
    int x, y, starti, startj, endi, endj;

    scanf("%d %d", &x, &y);

    int map[x][y];

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0){
                starti = i ;
                startj = j ;
            } 
            if(map[i][j] == 1){
                endi = i;
                endj = j;
            }
        }
    }

    int path = paths(starti, startj, endi, endj);


    return 0;
}
