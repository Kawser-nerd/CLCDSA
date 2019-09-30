N = int(input())
D, X = map(int,input().split())
A = [ int(input()) for i in range(N)]
count = 0
for i in range(N):
    for j in range(1,D+1,A[i]):
        count += 1
print(count+X)