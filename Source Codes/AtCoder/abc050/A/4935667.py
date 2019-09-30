import sys, os

f = lambda:list(map(int,input().split()))
if 'local' in os.environ :
    sys.stdin = open('./input.txt', 'r')

def solve():
    a, op, b = input().split()
    a = int(a)
    b = int(b)
    if op == '+':
        print(a+b)
    elif op == '-':
        print(a-b)

solve()