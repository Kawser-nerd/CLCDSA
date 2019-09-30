n = int(input())
s = input()
s = list(map(lambda x:1 if x=="o" else -1,list(s)))
flag = False
for start in [[1,1], [1,-1], [-1, 1], [-1, -1]]:
    circle = start + [0]*(n-2)
    for i in range(1,n-1):
        circle[i+1] = circle[i]*s[i]*circle[i-1]
    # ???????????????
    if circle[-2] == circle[-1]*s[-1]*circle[0] and circle[-1] == circle[0]*s[0]*circle[1]:
        flag = True
        break
if flag:
    ans = ""
    for i in circle:
        if i == 1:
            ans += "S"
        else:
            ans += "W"
    print(ans)
else:
    print(-1)