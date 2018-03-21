start/b "" "wc.exe" -c ..\test\test0.c
start/b "" "wc.exe" -c ..\test\test1.c
start/b "" "wc.exe" -c ..\test\test2.c
start/b "" "wc.exe" -w ..\test\test3.c
start/b "" "wc.exe" -l ..\test\test4.c
start/b "" "wc.exe" -a ..\test\test5.c
start/b "" "wc.exe" -w -e stopwordlist.txt ..\test\test6.c
start/b "" "wc.exe" -c -l -w ..\test\sub\test7.c
start/b "" "wc.exe" -l -w -c -o output.txt ..\test\sub\test8.c
start/b "" "wc.exe" -w -l -c -a ..\test\sub\test9.c
start/b "" "wc.exe" -s -l -w -c -o output.txt -a ..\test\*.c
pause
exit