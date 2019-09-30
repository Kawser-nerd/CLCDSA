from sys import exit
# A,B,C = [int(n) for n in input().split()]
N = int(input())
# a = [int(input()) for _ in range(N)]
anss = 1
for i in range(1,N+1):
    if(i**2>N):
        anss = i-1
        break
print(anss**2)