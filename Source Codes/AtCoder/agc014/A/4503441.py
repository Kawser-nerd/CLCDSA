a,b,c = map(int,input().split())
if a % 2 == 1 or b % 2 == 1 or c % 2 == 1:
    print(0)
    exit()
    
if a == b == c:
    print(-1)
    exit()

cnt = 0
while True:
    x = (b+c)//2
    y = (a+c)//2
    z = (a+b)//2
    cnt += 1
    if x % 2 == 1 or y % 2 == 1 or z % 2 == 1:
        break
    a,b,c = x,y,z
print(cnt)