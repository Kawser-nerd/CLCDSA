import sys
input = sys.stdin.readline

x,y = map(int,input().split())
k = int(input())

if k <= y:
    print(k+x)
else:
    print(y+ x-(k-y))