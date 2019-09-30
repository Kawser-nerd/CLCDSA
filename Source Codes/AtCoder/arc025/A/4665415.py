d = list(map(int,input().split()))
j = list(map(int,input().split()))
g = 0
for (a,b) in zip(d,j):g += max(a,b)
print(g)