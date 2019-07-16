#include<cstdio>
#include <algorithm>
using namespace std;
#define SIZE 11000
int order[SIZE];
struct Product {
    double rate;
    int index;
};
Product prds[SIZE];
bool Cmp(Product a, Product b) {
    return a.rate > b.rate;
}
bool Cmp1(int a, int b) {
    return a > b;
}

int main() {
    int N, M, K;
    double temp;
    while(~scanf("%d%d%d", &N, &M, &K)) {
        for(int i = 0; i < M; i++) {
            prds[i].rate = 0.0;
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf("%lf", &temp);
                prds[j].rate += temp;
                prds[j].index = j + 1;
            }
        }
        sort(prds, prds + M , Cmp);
        for(int j = 0; j < K; j++) {
            order[j] = prds[j].index;
        }
        sort(order, order + K , Cmp1);
        for(int i = 0; i < K - 1; i++) {
            printf("%d ", order[i]);
        }
        printf("%d\n", order[K - 1]);

    }
    return 0;
}