gcc -DTEST_TS ts.h -o ts_test
gcc -std=c99 -DTEST_TS ts.h -o ts_test
gcc -std=c99 -DTEST_TS -m32 ts.h -o ts_test.exe
ts_test