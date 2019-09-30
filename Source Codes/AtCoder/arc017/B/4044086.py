N, K = map(int, input().split())
inputs = [int(input()) for _ in range(N)]

ans = 0
length = 1
for i in range(1, N):
    if inputs[i-1] < inputs[i]:
        length += 1
    else:
        if length >= K:
            ans += length - K + 1
            length = 1
        else:
            length = 1
if length >= K:
    ans += length - K + 1

print(ans)