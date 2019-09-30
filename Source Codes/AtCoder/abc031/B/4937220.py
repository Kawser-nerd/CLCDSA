L,H=map(int,input().split())
n=int(input())
for i in range(n):
  a=int(input())
  print(-1 if a>H else 0 if a>L else L-a)