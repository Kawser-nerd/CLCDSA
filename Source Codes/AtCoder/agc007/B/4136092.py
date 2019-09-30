N = int(input())
p = list(map(int, input().split()))

a = list(i*29000+1 for i in range(N))
b = list(29000*(N-i)+1 for i in range(N))

for i, n in enumerate(p):
    a[n-1] += i

print(*a)
print(*b)