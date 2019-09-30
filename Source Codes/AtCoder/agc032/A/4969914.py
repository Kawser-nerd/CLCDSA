n = int(input())
b = [int(i) for i in input().split()]
a = list()

while len(b) > 0 and n-1 >= 0:
    if b[n-1] == n:
        b.pop(n-1)
        a.insert(0, n)
        n = len(b)
        continue
    n -= 1

if len(b) == 0:
    [print(i) for i in a]
else:
    print(-1)