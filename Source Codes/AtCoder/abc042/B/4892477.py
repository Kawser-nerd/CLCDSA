# -*- coding utf-8 -*-
n,s =map(int,input().split())
 
s = [str(input()) for i in range(n)]
s.sort()

print(*s, sep="")