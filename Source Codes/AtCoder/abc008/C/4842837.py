N = int(input())
c = [int(input()) for _ in range(N)]

e = [0 for _ in range(N)]
for i in range(N):
    e[i] = sum(1 for cc in c if c[i] % cc == 0) - 1
# e:=
# c??????????
# ?????

ans = 0
for i in range(N):
    ans += (e[i] // 2 + 1) / (e[i] + 1)
print(ans)