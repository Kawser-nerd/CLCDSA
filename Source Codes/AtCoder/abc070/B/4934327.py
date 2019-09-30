a,b,c,d=map(int, input().split())

if b<=c or d<=a:
    ans = 0
elif a<=c:
    if b<=d:
        ans = b-c
    elif d<=b:
        ans = d-c
elif c<=a:
    if d<=b:
        ans = d-a
    elif b<=d:
        ans = b-a
elif a==c and b==d:
    ans = b-a

print(ans)