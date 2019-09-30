#22
n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
print(len(a)-len(list(set(a))))