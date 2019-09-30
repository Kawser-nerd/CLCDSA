n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
print(int(sum(a)-max(a)/2))