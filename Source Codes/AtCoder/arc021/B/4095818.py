L = int(input())
inputs = [int(input()) for _ in range(L)]

ans = [0]
for i in range(L-1):
    ans.append(ans[-1]^inputs[i])

if ans[0] ^ ans[-1] == inputs[-1]:
    print('\n'.join(map(str, ans)))
else:
    print(-1)