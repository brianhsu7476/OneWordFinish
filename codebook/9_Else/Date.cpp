int Date(int y, int m, int d) {
    static const int md[] = {0,0,31,59,90,120,151
        ,181,212,243,273,304,334,365};
    return y*365+y/4-y/100+y/400+md[m]
        -(m<=2&&((y%4==0&&y%100!=0)||y%400==0))+d+6;
}
