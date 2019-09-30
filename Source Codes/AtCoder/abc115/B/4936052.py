p = [int(input()) for _ in range(int(input()))]

half = p.pop(p.index(max(p)))/2
sum = 0

for i in range(len(p)):
    sum += p[i]

print(int(half + sum))