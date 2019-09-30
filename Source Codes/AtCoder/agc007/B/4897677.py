n = int(input())
p = list(map(int, input().split()))
a = [(i+1) * 2*10**4 for i in range(n)]
b = [(n-i) * 2*10**4 for i in range(n)]
for i in range(n):
    a[p[i]-1] += i
print(" ".join(list(map(str, a))))
print(" ".join(list(map(str, b))))