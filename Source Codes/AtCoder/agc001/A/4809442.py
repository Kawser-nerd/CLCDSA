N = int(input())
L = list(map(int,input().split()))
L.sort()
count = 0
for i in range(N):
    count += L[2*i]
print(count)