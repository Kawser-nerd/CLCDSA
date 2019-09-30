from itertools import combinations

n = int(input())
c = input()

w = ['A', 'B', 'X', 'Y']
s = [i+j for i in w for j in w]

ans = float('inf')

for (key1, key2) in combinations(s, 2):
    i = 0
    count = 0
    while i < n:
        if i < n-1 and (c[i] + c[i+1] == key1 or c[i] + c[i+1] == key2):
            i += 2
            count += 1
        else:
            i += 1
            count += 1
    ans = min(ans, count)

print(ans)