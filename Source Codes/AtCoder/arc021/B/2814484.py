L = int(input())
B = [int(input()) for i in range(L)]

ans = [0]
for i in range(L-1):
    ans.append(ans[-1] ^ B[i])

if ans[-1] != B[-1]:
    print(-1)
else:
    print(*ans, sep="\n")