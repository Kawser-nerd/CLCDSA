a,b,c,k = map(int, input().split())
s,t = map(int, input().split())

if s+t >= k:
    print((a-c)*s+(b-c)*t)

else:
    print(a*s+b*t)