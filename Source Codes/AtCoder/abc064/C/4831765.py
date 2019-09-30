from collections import Counter

N = int(input())
a = Counter(list(map(lambda x: x//400, map(int, input().split()))))

c = n = 0
for key in [0,1,2,3,4,5,6,7]:
    if a[key]:
        c += 1
        
for key in [8,9,10,11,12]:
    n += a[key]
        
max_n = c+n
if c:
    min_n = c
else:
    min_n = 1
print(min_n, max_n)