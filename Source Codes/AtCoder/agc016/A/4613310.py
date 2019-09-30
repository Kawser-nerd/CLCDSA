L = [chr(i) for i in range(97, 123)]
s = list(input())
N = len(s)

ans = float("inf")
for i in L:
    c = 0
    X = s
    while True:
        if X.count(i) == N - c:
            break
        else:
            Y = []
            for j in range(N - c - 1):
                if X[j] == i or X[j + 1] == i:
                    Y.append(i)
                else:
                    Y.append(".")
            X = Y
        c += 1

    if c < ans:
        ans = c

print(ans)