a,b,c = map(int,input().split())

l = sorted([a,b,c])

if l[0]+l[1]==l[2]:
    print("Yes")

else:
    print("No")