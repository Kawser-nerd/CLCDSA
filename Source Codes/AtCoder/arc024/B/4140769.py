N = int(input())
inputs = [int(input()) for _ in range(N)]

inputs += inputs

if len(set(inputs)) == 1:
    ans = -1
else:
    length = 1
    max_length = 1
    for i in range(len(inputs)):
        if inputs[i-1] == inputs[i]:
            length += 1
        else:
            max_length = max(max_length, length)
            length = 1
    ans = max_length // 2
    if max_length % 2 == 1:
        ans += 1

print(ans)