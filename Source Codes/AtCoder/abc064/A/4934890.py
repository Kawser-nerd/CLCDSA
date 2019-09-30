r, g, b = map(int, input().split())
X = 10*g + b
if(X%4 == 0):
    print("YES")
else:
    print("NO")