N = int(input())
src = [int(input()) for i in range(N)]
ans = tmp = 1
asc = True
for a,b in zip(src, src[1:]):
    if not asc and a < b:
        ans = max(ans, tmp)
        tmp = 2
        asc = True
    else:
        if asc and a > b:
            asc = False
        tmp += 1
print(max(ans, tmp))