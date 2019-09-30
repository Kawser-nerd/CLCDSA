n = int(input())
c = [int(input()) for _ in range(n)]

s = sum(c)
if s%n == 0:
    print(-1)
    exit()

a = []
for i in range(n):
    a.append(1 if sum([c[i-j] for j in range(3)])%3==0 else 0)
m = 0
head = 0
c = 0
for i in range(n):
    if a[i] == 1:
        c += 1
    else:
        m = max(m, c)
        if i == c:
            head = c
        c = 0
m = max(m, head+c)
print((m+3)//2)