import math
x,y = map(int, input().split())
a = min(x,y)
b = max(x,y)
n = int(input())
for _ in range(n):
    x,y = map(int ,input().split())
    c = min(x,y)
    d = max(x,y)
    if a <= c and b <= d:
        print("YES")
    else:
        if a > c or a**2 + b**2 >= c**2 + d**2:
            print("NO")
        else:
            thi_2 = math.atan(((a**2+b**2-c**2)**(1/2))/c)
            thi_3 = math.atan(((a**2+b**2-d**2)**(1/2))/d)
            thi_1 = math.acos((b**2-a**2)/(a**2+b**2))
            if 3.14159265358979/2-thi_2-thi_3 > thi_1:
                print("YES")
            else:
                print("NO")