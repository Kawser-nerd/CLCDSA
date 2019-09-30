N = int(input())
A1 = [int(a) for a in input().split()]
A2 = [int(a) for a in input().split()]

maxi = prev = A1[0] + sum(A2)
for i in range(1, N):
    cur = prev + A1[i] - A2[i-1]
    maxi = max(maxi, cur)
    prev = cur
print(maxi)