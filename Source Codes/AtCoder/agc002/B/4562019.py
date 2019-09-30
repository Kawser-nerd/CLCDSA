a,b = map(int, input().split())
n = [1]*a
r = [0]*a
r[0] = 1

for i in range(b):
    ta,tb = map(int, input().split())
    ta-=1
    tb-=1
    if r[ta] == 1:
        r[tb] = 1
    n[ta] -=1
    n[tb] +=1
    if n[ta] ==0:
        r[ta] = 0
print(sum(r))