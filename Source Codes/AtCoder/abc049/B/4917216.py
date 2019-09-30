import sys, os

f = lambda:list(map(int,input().split()))
def init():
    if 'local' in os.environ :
        sys.stdin = open('./input.txt', 'r')

def solve():
    n ,m = f()
    for i in range(n):
        a = input()
        print(a)
        print(a)


init()
solve()