/*************************************************************************
	> File Name: main.c
	> Author: lvxiaojun
	> Mail: 2310054126@qq.com
	> Created Time: Thu 24 Dec 2020 01:32:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include<test.h>
int add(int a, int b) {
    return a + b;
}

double ADD(double a, double b) {
    return a + b;
}


TEST(func, test1) {
    EXCEPT_EQ(add(2, 3), 5);
    EXCEPT_NE(add(2, 3), 6);
}

TEST(func, test2) {
    EXCEPT_EQ(add(-1, 1), 0);
    EXCEPT_GT(add(3, -2), 1);
    EXCEPT_LT(add(3, 4), 5);
}

TEST(f, unctest1) {
    EXCEPT_EQ(add(0, 0), 0);
    EXCEPT_EQ(add(12, -12), 0);
}


TEST(func, double) {
    EXCEPT_EQ(ADD(-1.7, 1.9), 0);
    EXCEPT_GT(ADD(3.14, -2.16), 1);
    EXCEPT_LT(ADD(3.001, 4.99), 5);
}
int main() {
    return RUN_ALL_TESTS();
}
