N = int(input())
inputs = [int(input()) for i in range(N)]
inputs += inputs

if len(set(inputs)) == 1:
    print(-1)
else:
    X = 1
    tmp = 1
    for i in range(len(inputs)):
        if inputs[i] == inputs[i-1]:
            tmp += 1
        else:
            X = max(X, tmp)
            tmp = 1
    if X % 2 == 1:
        ans = X // 2 + 1
    else:
        ans = X // 2
    print(ans)