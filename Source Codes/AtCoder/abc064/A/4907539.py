r, g, b = map(int, input().split())

number=100*r + 10*g + b

if number %4 ==0:
    print("YES")
else:
    print("NO")