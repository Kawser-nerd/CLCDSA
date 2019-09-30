d = list(map(int,input().split()))
j = list(map(int,input().split()))
res = 0
for (a,b) in zip(d,j):
    res += max(a, b)
print(res)