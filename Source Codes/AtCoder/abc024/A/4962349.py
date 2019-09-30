a, b, c, k = map(int,input().split())
s, t = map(int,input().split())
u = int(s + t)
if u >= k:
    print(int(a*s + b*t - u*c))
else:
    print(int(a*s + b*t))