a,b,c,d = map(int,input().split())
AB = abs(a-b)
AC = abs(a-c)
BC = abs(b-c)
if AC <= d :
    print('Yes')
elif AB <= d and BC <= d :
    print('Yes')
else :
    print('No')