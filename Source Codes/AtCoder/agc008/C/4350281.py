a,b,c,d,e,f,g = map(int,input().split())
res = []
res.append(b + (a//2)*2+ d//2*2 + e//2*2)
if a >= 1 and d >= 1 and e >= 1:
    res.append(3 + b + (a-1)//2*2 + (d-1)//2*2 + (e-1)//2*2)
print(max(res))