#include "stdio.h"
#include "string.h"
#include <queue>
using namespace std;

int m;
int n;
int origin_map[11][11];
int pre_path[11][11][11][11];
int dp[11][11][11][11];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


struct node
{
    int x;
    int y;
    int step;
    int dir;
    int pick;
    node (int a, int c,  int b, int direction, int is_p)
    {
        pick = is_p;
        x = a;
        y = c;
        step = b;
        dir = direction;
    }
    friend bool operator < (node a, node b)
    {
        return a.step < b.step;
    }
    node(){}
};
int xx;
int yy;
int hh[11][11];
int r;
queue<node> tmp;
void get_max_path1(int x, int y, int step, int cur, int pick)
{
    if (step > r)
    {
        r = step;
        if (r == 88)
        {

        }
    }
    if (x < 0 || x >= m || y < 0 || y >= n )
    {
        return;
    }
    if (hh[x][y] == 1)
    {
        return;
    }
    hh[x][y] = 1;
    tmp.push(node(x, y, step, 0, pick));
    for (int i = 0; i < 4; i ++)
    {
        if (cur < origin_map[x + dir[i][0]][y + dir[i][1]])
        {
            get_max_path1(x + dir[i][0], y + dir[i][1], step + origin_map[x][y],
                           origin_map[x + dir[i][0]][y + dir[i][1]], 1);

        }
        {
            get_max_path1(x + dir[i][0], y + dir[i][1], step ,
                          cur, 0);


        }
    }
    tmp.pop();


    hh[x][y] = 0;

}


// int get_max_path(int x, int y)
// {
//     priority_queue<node> q;
//     q.push(node(x, y, origin_map[x][y], -1));
//     while (1)
//     {
//         if (q.empty())
//             break;
//         node front = q.top();
//         q.pop();
//         if (front.x < 0 || front.y < 0 || front.x >= m || front.y >= n)
//         {
//             continue;
//         }
//         if (dp[x][y][front.x][front.y] != -1 && dp[x][y][front.x][front.y] >= front.step)
//         {
//             continue;
//         }
//         dp[x][y][front.x][front.y]  = front.step;
//         pre_path[x][y][front.x][front.y] = front.dir;
//         for (int i = 0; i < 4; i ++ )
//         {
//             if (origin_map[front.x][front.y] <
//                 origin_map[front.x + dir[i][0]][front.y + dir[i][1]])
//             {
//                 q.push(node(front.x + dir[i][0], front.y  + dir[i][1],
//                             front.step + origin_map[front.x + dir[i][0]][front.y + dir[i][1]],
//                             i ));
//             }
//         }
//     }
//     int res = 0;
//     for (int i = 0; i < m ; i ++ )
//     {
//         for (int j = 0; j < n; j ++)
//         {
//             if (dp[x][y][i][j] > res)
//             {
//                 res = dp[x][y][i][j];
//             }
//
//         }
//
//     }
//
//     return res ;
// }
int main()
{
    while (scanf("%d %d", &m, &n) != EOF)
    {
        for (int i = 0; i < m; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                scanf("%d", &origin_map[i][j]);
            }
        }
        memset (pre_path, -1, sizeof(pre_path));
        memset (dp, -1, sizeof(dp));
        int x;
        int y;
        int max_count = 0;
        for (int i = 0; i < m ; i ++)
        {
            for (int j = 0; j < n; j++)
            {
                r = 0;
                while (!tmp.empty())
                {
                    tmp.pop();
                }
                get_max_path1(i, j, origin_map[i][j], origin_map[i][j], 1);
                printf ("%d %d %d\n", i, j, r);
                if (r> max_count)
                {
                    x = i;
                    y = j;
                }
            }
        }
        // int i;
        // int j;
        // for (i = 0; i < m ; i++)
        // {
        //     int f = 0;
        //     for (j = 0; j < n ; j++)
        //     {
        //         f = dp[x][y][i][j];
        //         if (dp[x][y][i][j] == max_count)
        //         {
        //             break;
        //         }
        //
        //     }
        //     if (f == max_count)
        //     {
        //         break;
        //     }
        // }
        // vector<int> out;
        // while (1)
        // {
        //     int d = pre_path[x][y][i][j];
        //     out.push_back(origin_map[i][j]);
        //     if (d == -1)
        //     {
        //         break;
        //     }
        //     i -= dir[d][0];
        //     j -= dir[d][1];
        // }
        // for (int i = out.size() - 1; i >= 1; i --)
        // {
        //     printf("%d ", out[i]);
        // }
        // printf("%d\n", out[0]);

    }
    return 0;
}
