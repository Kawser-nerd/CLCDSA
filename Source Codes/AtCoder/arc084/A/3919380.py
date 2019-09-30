from bisect import bisect_left,bisect
N = int(input())
info = [sorted(list(map(int,input().split()))) for i in range(3)]
ans = 0
for j in range(N):
    small = bisect_left(info[0],info[1][j])
    large = N - bisect(info[2],info[1][j])
    ans += small * large
print(ans)