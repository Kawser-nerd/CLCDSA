n = int(input())
import sys
s = list(map(int, sys.stdin.readlines()))
s.sort()
ans = sum(s)
if ans%10:
    print(ans)
else:
    for i in s:
        if i%10:
            print(ans - i)
            exit()
    print(0)