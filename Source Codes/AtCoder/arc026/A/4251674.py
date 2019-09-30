N,A,B = map(int,input().split(" "))
c = 0
ans = 0
for i in range(N):
    if c < 5:
        ans += B
        c += 1
    else:
        ans += A
print(ans)