n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
a = list(set(a))
a.sort()
print(a[-2])