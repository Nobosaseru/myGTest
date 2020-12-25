/*************************************************************************
	> File Name: test.h
	> Author: lvxiaojun
	> Mail: 2310054126@qq.com
	> Created Time: Thu 24 Dec 2020 03:26:23 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#include <string.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#define TEST(a, b) void a##_haizei_##b(); \
__attribute__((constructor)) \
void add##_haizei_##a##_haizei_##b() { \
    add_function(a##_haizei_##b, #a "." #b); \
} \
void a##_haizei_##b()



#define TYPE(a) _Generic((a), \
    int  : "%d", \
    double : "%lf", \
    float : "%f", \
    long long : "%lld", \
    const char * : "%s", \
    char * : "%s" \
)

#define P(a, color) { \
    char frm[1000]; \
    sprintf(frm, color("%s"), TYPE(a)); \
    printf(frm, a); \
} 

#define EXCEPT(a, b, c) { \
    __typeof(a) _a = (a); \
    __typeof(b) _b = (b); \
    haizei_test_info.total += 1; \
    if (_a c _b) haizei_test_info.success += 1; \
    else { \
        printf("\n"); \
        printf(YELLOW_HL("\t%s:%d: failure\n"), __FILE__, __LINE__); \
        printf(YELLOW_HL("\t\texpect : " #a " " #c " " #b "\n\t\t" "actual : ")); \
        P(_a, YELLOW_HL); \
        printf(YELLOW_HL(" vs ")); \
        P(_b, YELLOW_HL); \
        printf("\n\n"); \
    } \
    printf(GREEN("[-----------] ")); \
    printf("%s " #c " %s ? %s\n", #a, #b, _a c _b ? GREEN("TRUE") : RED("FALSE")); \
}

#define EXCEPT_EQ(a, b) EXCEPT(a, b, ==)
#define EXCEPT_NE(a, b) EXCEPT(a, b, !=)
#define EXCEPT_GT(a, b) EXCEPT(a, b, >)
#define EXCEPT_GE(a, b) EXCEPT(a, b, >=)
#define EXCEPT_LT(a, b) EXCEPT(a, b, <)
#define EXCEPT_LE(a, b) EXCEPT(a, b, <=)

typedef void (*TestFuncT)();

typedef struct Function {
    TestFuncT func;
    const char *str;
} Function;

struct FunctionInfo {
    int total, success;
} ;

extern struct FunctionInfo haizei_test_info;
void add_function(TestFuncT, const char *);

int RUN_ALL_TESTS();
#endif
