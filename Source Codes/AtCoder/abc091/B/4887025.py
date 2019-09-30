N = int(input())
s = [input() for _ in range(N)]
M = int(input())
t = [input() for _ in range(M)]
a = 0
for i in s:
    b = s.count(i) - t.count(i)
    if a < b:
        a = b
print(a)