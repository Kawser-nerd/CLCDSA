N,T = map(int,input().split())
t = [int(i) for i in input().split()]

res = T
pre = t[0]
for i in t[1:]:
    if i < pre + T:
        res += i - pre
    else:
        res += T
    pre = i

print(res)