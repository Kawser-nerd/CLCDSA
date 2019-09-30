r,g,b = map(int,input().split())
r *= 100
g *= 10
if (r+g+b)%4 == 0:
    print("YES")
else:
    print("NO")