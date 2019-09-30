n = int(input())
s = [input() for i in range(n)]
m= int(input())
t = [input() for i in range(m)]

c = 0

for i in range(n):
    a = 0
    b = 0
    for j in range(n):
        if s[i] == s[j]:
            a += 1

    for j in range(m):
        if s[i] == t[j]:
            b += 1

    if c < a-b:
        c = a-b

print(c)