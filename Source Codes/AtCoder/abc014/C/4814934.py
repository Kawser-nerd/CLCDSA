import itertools

n = int(input())
color = [0]*1000002

for i in range(n):
    a, b = map(int, input().split())
    color[a] += 1
    color[b+1] -= 1

print(max(list(itertools.accumulate(color))))