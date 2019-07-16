#include<cstdio>
using namespace std;

int main() {
    int A;
    while(~scanf("%d", &A)) {
        if (A == 0) {
            break;
        }
        int ans = 1;
        while(A > 0 && A % 2 == 0) {
            A = A / 2;
            ans *= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}