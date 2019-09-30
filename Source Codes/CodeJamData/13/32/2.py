#!/usr/bin/python3
# -*- coding: utf-8 -*-

def check(xx,yy):
    points = set([(0,0)])
    for step in range(30):
        t1 = (0,0) in points
        t2 = step%4 in (0,3)
        d = step+1
        if (xx,yy) in points:
            return step
        points = set([a for b in [[(x+d,y),(x-d,y),(x,y+d),(x,y-d)] for x,y in points] for a in b])

def calc(x,y):
    d = s = 0
    while s<abs(x)+abs(y):
        d+=1
        s+=d
    add_zero = d%4 in (0,3)
    while ((abs(x)+abs(y))%2==0)!=(d%4 in (0,3)):
        d+=1
        s+=d
    res = ''
    for i in range(d,0,-1):
        if abs(x)>abs(y) and x>0:
            x-=i
            res = 'E' + res
        elif abs(x)>abs(y):
            x+=i
            res = 'W' + res
        elif y>0:
            y-=i
            res = 'N' + res
        else:
            y+=i
            res = 'S' + res
    assert (x,y)==(0,0),(x,y,d)
    return res

def solve():
    x,y = map(int,input().split())
    res = calc(x,y)
    #assert len(res) == check(x,y)
    print (res)

if __name__=="__main__":
    T = int(input())
    for t in range(1,T+1):
        print("Case #%d:"%t,end=' ')
        solve()

