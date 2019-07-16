//最短路，使用Dijkstra

#include<cstdio>
#define INF 0x3f3f3f3f
int cost[10010][10010];
int low[10010];
int vis[10010];

void Dijkstra(int n) {
    int edge, k;
    for(int i = 1; i <= n; ++i) {
        low[i] = cost[0][i];
        vis[i] = 0;
    }
    vis[0] = 1;
    low[0] = 0;
    for(int i = 1; i <= n; ++i) {
        edge = INF;
        for(int j = 1; j <= n; ++j) {
            if(vis[j] == 0 && edge > low[j]) {
                edge = low[j];
                k = j;
            }
        }
        vis[k] = 1;
        for(int j = 1; j <= n; ++j) {
            if(vis[j] == 0 && low[j] > low[k] + cost[k][j]) {
                low[j] = low[k] + cost[k][j];
            }
        }
    }
}

int main() {
    int m, n;
    int a, b, c;
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0) {
            break;
        }
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= n; ++j) {
                cost[i][j] = INF;
            }
            cost[i][i] = 0;
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d\n", &a, &b, &c);
            cost[a][b] = cost[b][a] = c;
        }
        cost[0][1]=cost[1][0]=0;
        Dijkstra(n);
        printf("%d\n", low[n]);
    }
    return 0;
}
