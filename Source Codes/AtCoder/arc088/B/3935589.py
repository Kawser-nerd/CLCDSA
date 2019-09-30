a = list(input())
n = len(a)
a = [0] + a
s = n
for i in range (1, n):
    if(a[i] != a[i + 1]):
        s = min(s, max(i, n - i))
print(s)