n = int(input())
s = []
p = []
sum = 0
newName = "atcoder"

for i in range(n):
    name, population = input().split()
    s.append(name)
    p.append(int(population))
    sum += int(population)

for i in range(n):
    if p[i] > sum/2:
        newName = s[i]

print(newName)