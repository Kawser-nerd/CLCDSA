#9
n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a = list(set(a))
a = sorted(a)
print(a[len(a)-2])