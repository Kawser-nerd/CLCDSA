r,g,b = (int(i) for i in input().split())  
r *= 100
g *= 10
if (r + g + b) % 4 == 0 :
    print('YES')
else :
    print('NO')