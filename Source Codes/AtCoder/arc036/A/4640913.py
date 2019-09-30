n,k = map(int,input().split())
L = [int(input()) for i in range(n)]+ [float('inf')]*2
for i in range(n):
    if sum(L[i:i+3]) < k:
        print(i+3)
        exit()
print(-1)