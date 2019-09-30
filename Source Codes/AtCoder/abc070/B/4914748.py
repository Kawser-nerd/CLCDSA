a,b,c,d = map(int,input().split())
e = max(a,c)
f = min(b,d)
print(max(f-e,0))