N = int(input())
inputs = [int(input()) for i in range(N)]
inputs += inputs

if len(set(inputs)) == 1:
    print(-1)
else:
    max_length = 1
    length = 1
    for i in range(len(inputs)):
        if inputs[i] == inputs[i-1]:
            length += 1
        else:
            max_length = max(max_length, length)
            length = 1
    ans = max_length // 2
    print(ans + 1 if max_length % 2 == 1 else ans)