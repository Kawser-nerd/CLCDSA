N = int(input())
red = []
for i in range(N):
    a,b = map(int,input().split())
    red.append((a,b))

blue = []
for i in range(N):
    c,d = map(int,input().split())
    blue.append((c,d))

red =  sorted(red,  key=lambda x:x[0])
blue = sorted(blue, key=lambda x:x[0])

ans = 0

for i in range(N):
    c = blue[i][0]
    d = blue[i][1]

    ind = -1
    y_max = -1
    for j in range(N - ans):
#        print('red = ',red[j])
        a = red[j][0]
        b = red[j][1]

        if a < c and b < d and y_max < b:
            ind = j
            y_max = b
        elif a > c:
            break

    if ind > -1:
        ans += 1
#        print('pop',c,d,red[ind])
        red.pop(ind)
#        print('remove',red)
print(ans)