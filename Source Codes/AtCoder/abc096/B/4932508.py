A,B,C = map(int,input().split())
K=int(input())
M = max(A,B,C)
print(A+B+C+M*(-1+2**K))