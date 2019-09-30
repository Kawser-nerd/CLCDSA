n,t = map(int,input().split())
a = []
for i in range(n):
    c,x = map(int,input().split())
    if x <= t:
        a.append(c)
if len(a) > 0:
    print(min(a))
else:
    print("TLE")