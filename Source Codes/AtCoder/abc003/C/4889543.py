n,k = map(int,input().split())
r_list = sorted(list(map(int,input().split())))
res = 0
for r in r_list[-k:]:
    res = (res+r)/2
print(res)