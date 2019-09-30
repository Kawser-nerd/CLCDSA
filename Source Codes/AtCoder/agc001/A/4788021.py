N=int(input())
L=list(map(int, input().split()))

L.sort()

sum=0
for i in range(N):
    sum += L[(i - 1) * 2]

print(sum)