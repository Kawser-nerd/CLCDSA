k = int(input())
n = 50
p = k // n
a = [i + p for i in range(n)]
m = k % n
for i in range(n) :
        if i < m : a[i] += n - (m - 1)
        else :     a[i] -= m
print(n)
print(*a)