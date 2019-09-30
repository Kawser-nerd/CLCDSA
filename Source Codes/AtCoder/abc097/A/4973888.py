#097
a,b,c,d= map(int,input().split())

if abs(a-c)<=d or (abs(a-b)<=d and abs(b-c)<=d):
    print('Yes')
else:
    print('No')