import itertools
    
K, S = map(int,input().split())

count = 0
for x,y in itertools.product(range(0,K + 1),range(0,K + 1)):
    z = S - x - y
    if 0 <= z <= K:
        count += 1

print(count)