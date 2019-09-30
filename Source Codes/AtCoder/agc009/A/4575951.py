n = int(input())
AB = [ list(map(int, input().split())) for i in range(n)]
ans = 0
for i in range(n-1,-1,-1):
    a = AB[i][0] + ans
    b = AB[i][1]
    #print(a,b)
    if a % b == 0:
        tmp = 0
    else:
        tmp = b - ( a % b )
    ans += tmp
print(ans)