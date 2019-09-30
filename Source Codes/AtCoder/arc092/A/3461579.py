n = int(input())
red = []
for i in range(n):
    a,b = map(int,input().split())
    red.append([a,b])
blue = []
for i in range(n):
    c,d = map(int,input().split())
    blue.append([c,d])

red.sort(key = lambda x:(x[1],x[0]))
blue.sort(key = lambda x:(x[0],x[1]))

ans = 0
for i in range(n):
    for k in range(n):
        if blue[i][0] > red[n-1-k][0] and blue[i][1] > red[n-1-k][1]:
            ans += 1
            red[n-1-k][0] = 2000
            red[n-1-k][1] = 2000
            break
print(ans)