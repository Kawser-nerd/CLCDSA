a,b,c,d = map(int,input().split())

if b/a > d/c:
    print("TAKAHASHI")
elif b/a < d/c:
    print("AOKI")
else:
    print("DRAW")