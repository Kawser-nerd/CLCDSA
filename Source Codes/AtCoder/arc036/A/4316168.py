N, K = map(int, input().split())
inputs = [int(input()) for i in range(N)]

ans = -1
for i in range(N-2):
    if inputs[i] + inputs[i+1] + inputs[i+2] < K:
        ans = i + 3
        break

print(ans)