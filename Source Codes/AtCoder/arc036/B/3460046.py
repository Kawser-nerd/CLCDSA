n = int(input())
h = [int(input()) for i in range(n)]
l = 0
r = 0
ans = 0
if n == 1:
    print(1)
    quit()
while r < n-1:
    while h[r+1] > h[r]:
        r += 1
        if r == n-1:
            ans = max(ans, r-l+1)
            print(ans)
            quit()
    while h[r+1] < h[r]:
        r += 1
        if r == n-1:
            ans = max(ans, r-l+1)
            print(ans)
            quit()
    ans = max(ans, r-l+1)
    l = r
    r += 1
print(ans)