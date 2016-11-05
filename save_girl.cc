#include "stdio.h"
#include "string.h"
#include <queue>
using namespace std;
int dp[100101];

struct node
{
    int cur;
    int step;
    node (int a, int b)
    {
        cur = a;
        step = b;
    }
    friend bool operator < (node a, node b)
    {
        return a.step > b.step;
    }
};


void find_path(int n, int k)
{
    priority_queue<node> q;
    q.push(node(n, 0));
    while (1)
    {
        if (q.empty())
            break;
        node front = q.top();
        q.pop();
        if (front.cur >= k + 10)
        {
            continue;
        }
        if (dp[front.cur] != -1 && dp[front.cur] <= front.step)
        {
            continue;
        }
        dp[front.cur] = front.step;
        // printf ("%d %d %d\n", front.cur, front.step, k);
        if (front.cur == k)
        {
            break;
        }

        q.push(node(front.cur + 1, front.step + 1));
        q.push(node(front.cur - 1, front.step + 1));
        q.push(node(front.cur * 2, front.step + 1));


    }


    return ;
}
// void find_path(int n, int k, int step)
// {
//     if (dp[n] <= step && dp[n] != -1)
//     {
//         return;
//     }
//     dp[n] = step;
//     if (2 * n <= 100011)
//         find_path(2 * n, k , step + 1);
//     find_path(n - 1, k, step+1);
//     find_path(n + 1, k, step+1);
//     return;
//
//
//
// }
int main()
{
    int n = 0;
    int k = 0;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        if (n >= k)
        {
            printf ("%d\n", n - k);
            continue;
        }
        else
        {
            memset(dp, -1, 4*(k + 100));
            find_path(n, k);
            printf ("%d\n", dp[k]);
        }

    }
    return 0;
}
