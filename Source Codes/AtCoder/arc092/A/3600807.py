n = int(input())
red =[]
blue =[]
for i in range(n):
    x, y = map(int, input().split(' '))
    red.append(x + y*1000)
for i in range(n):
    x, y = map(int, input().split(' '))
    blue.append(x*1000 + y)
red.sort()
blue.sort()
ans = 0
red = red[::-1]
for b in blue:
    flag = True
    for r in red:
        if (r%1000 < b//1000) and (r//1000 < b%1000) and flag:
            flag = False
            red[red.index(r)]=9999999999
            ans +=1
print(ans)