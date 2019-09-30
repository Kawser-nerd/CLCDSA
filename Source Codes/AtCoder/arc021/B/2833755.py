N = int(input())
B = [int(input()) for i in range(N)]

ans = [0]
for i in range(N):
    ans.append(ans[-1] ^ B[i])

if ans[0] != ans[-1]:
    print(-1)
else:
    print(*ans[:-1], sep="\n")