import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

n = ni()
s = ns()

stack = []

left = 0
right = 0

for si in s:
    if si == '(':
        stack.append('(')
        
    elif si == ')':
        if stack:
            stack.pop()
        else:
            left += 1
            
right = len(stack)

print(left*'(' + s + right*')')