n, h = map(int, input().split())


an = [0]*n
bn = [0]*n

for i in range(n):
    an[i],bn[i] = map(int, input().split())
    

an.sort(reverse = True)
bn.sort(reverse = True)

ans = 0
for b in bn:
    if b>an[0] and h>0:
        h -= b
        ans += 1


ans += 0 if h<=0 else h//an[0] + (1 if h%an[0]>0 else 0) 

print(ans)