#include <stdio.h>
#include <test.h>
#include <math.h>
Function func_arr[100];
int func_cnt = 0;
struct FunctionInfo haizei_test_info;

void add_function(TestFuncT func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt += 1;
    return ;
}


int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        printf(GREEN("[====RUN====]") RED_HL(" %s\n"), func_arr[i].str);
        haizei_test_info.total = 0, haizei_test_info.success = 0;
        func_arr[i].func();
        double rate = 100.0 * haizei_test_info.success / haizei_test_info.total;
        printf(GREEN("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ]") " total : %d\tsuccess : %d\n", 
            haizei_test_info.total, 
            haizei_test_info.success);
    }
    return 0;
}
