#!/usr/bin/python3
# -*- coding: utf-8 -*-

def solve():
    s,n = input().split()
    n = int(n)
    cnt=0
    last=0
    has = False
    ans = 0
    for i,x in enumerate(s):
        if x in ['a', 'e', 'i', 'o', 'u']:
            cnt = 0
        else:
            cnt+=1
        if cnt>=n:
            has = True
            last = i-n+1
            ans += last+1
        elif has:
            ans += last+1
    print (ans)

if __name__=="__main__":
    T = int(input())
    for t in range(1,T+1):
        print("Case #%d:"%t,end=' ')
        solve()

