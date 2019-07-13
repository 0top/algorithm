// 一天中0点，12点和24点，时分秒指针都会重合，所以我们可以计算0-12点之间，即43200s
// 按照时间维度计算，时针和分针的happyTime在时针和分针相对时间的一个周期内有意义
// 所以选取时间作为维度进行计算

#include<cstdio>

int main() {
    double n;
    double sum;
    double sm, sh, mh;  //相对速度
    double smCycle, shCycle, mhCycle;   // 相对周期
    double startsm, endsm, startsh, endsh, startmh, endmh;
    sm = 10.0 / 59.0;
    sh = 120.0 / 719.0;
    mh = 120.0 / 11.0;
    smCycle = 360.0 * sm;
    shCycle = 360.0 * sh;
    mhCycle = 360.0 * mh;
    while(~scanf("%lf", &n)) {
        if(n < 0) {
            break;
        }
        sum = 0;
        startsm = n * sm;  endsm = smCycle - startsm;
        startsh = n * sh;  endsh = shCycle - startsh;
        startmh = n * mh;  endmh = mhCycle - startmh;
        double s, e, s1, e1, s2, e2, s3, e3;
        for(s3 = startmh, e3 = endmh; e3 <= 43200.0001; s3 += mhCycle, e3 += mhCycle) {
            for(s2 = startsh, e2 = endsh; e2 <= 43200.0001; s2 += shCycle, e2 += shCycle) {
                if(e2 < s3) {
                    continue;
                }
                if (s2 > e3) {
                    break;
                }
                for(s1 = startsm, e1 = endsm; e1 <= 43200.0001; s1 += smCycle, e1 += smCycle) {
                    if(e1 < s2 || e1 < s3) {
                        continue;
                    }
                    if (s1 > e2 || s1 > e3) {
                        break;
                    }
                    s = s1 > s2 ? s1 : s2;
                    s = s > s3 ? s : s3;
                    e = e1 < e2 ? e1 : e2;
                    e = e < e3 ? e : e3;
                    sum += e - s;
                }
            }
        }
        printf("%.3f\n", sum / 432.0);
    }
    return 0;
}
