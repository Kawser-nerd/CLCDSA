import sys
input=sys.stdin.readline
N=int(input())
A=[int(input()) for i in range(N)]
print(sorted(list(set(A)),reverse=True)[1])