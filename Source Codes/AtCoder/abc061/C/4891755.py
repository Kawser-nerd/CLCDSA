from sys import stdin

n, k = list(map(int, stdin.readline().split()))
ax = [0]*100001
c = 0
j = 0

for i in range(n):
    a, b = list(map(int, stdin.readline().split()))
    ax[a] += b

while c < k:
    c += ax[j]
    j += 1

print(j-1)