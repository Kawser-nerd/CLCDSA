R, G, B = map(int, input().split())
ans = 10**15
for i in range(-400, 401):
    tmp = 0
    g = i+G-1
    for j in range(i,g+1):
        tmp += abs(j)
    r = min(i-1,-100+(R-1)//2)
    for j in range(r-R+1,r+1):
        tmp += abs(j+100)
    b = max(g+1,100-(B-1)//2)
    for j in range(b,b+B):
        tmp += abs(j-100)
    ans = min(ans,tmp)
print(ans)