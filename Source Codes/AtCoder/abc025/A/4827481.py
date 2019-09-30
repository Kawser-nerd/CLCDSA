s = list(input())
n = int(input())

p = []

for i in range(5):
    for j in range(5):
        p.append(s[i] + s[j])

p.sort()

print(p[n-1])