flex lexical.l
bison -d -v syntax.y
gcc -std=gnu99 lex.yy.c syntax.tab.c ts.c quad.c -lfl -ly -o lexical.exe
lexical.exe < test_optimisation.txt
