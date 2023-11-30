#include <bits/stdc++.h>
using namespace std;


bool check(int dis[][8], int m, int n, int x, int y,
             int pre, int num)
{
    if (x < 0 || x >= m || y < 0 || y >= n
        || dis[x][y] != pre || dis[x][y] == num)
        return false;
    return true;
}


void fill(int dis[][8], int m, int n, int x, int y,
               int pre, int num)
{
    queue<pair<int, int> > queue;


    pair<int, int> p(x, y);
    queue.push(p);

    dis[x][y] = num;


    while (queue.size() > 0) {
        pair<int, int> currPixel = queue.front();
        queue.pop();

        int posX = currPixel.first;
        int posY = currPixel.second;


        if (check(dis, m, n, posX + 1, posY, pre,
                    num)) {

            dis[posX + 1][posY] = num;
            p.first = posX + 1;
            p.second = posY;
            queue.push(p);
        }

        if (check(dis, m, n, posX - 1, posY, pre,
                    num)) {
            dis[posX - 1][posY] = num;
            p.first = posX - 1;
            p.second = posY;
            queue.push(p);
        }

        if (check(dis, m, n, posX, posY + 1, pre,
                    num)) {
            dis[posX][posY + 1] = num;
            p.first = posX;
            p.second = posY + 1;
            queue.push(p);
        }

        if (check(dis, m, n, posX, posY - 1, pre,
                    num)) {
            dis[posX][posY - 1] = num;
            p.first = posX;
            p.second = posY - 1;
            queue.push(p);
        }
    }
}


