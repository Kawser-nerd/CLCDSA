S = list(input())
N = len(S)

if N % 2 == 0:
    n = int(N // 2)
    K = n
    i = 0
    while i < n:
        if S[n - 1 - i] == S[n + i]:
            i += 1
        else:
            break

    print(K + i)
else:
    n = int((N - 1) // 2)
    if N == 1:
        print(1)

    else:
        K = n + 1
        i = 0
        if S[n] == S[n + 1]:
            while i < n:
                if S[n - i - 1] == S[n + i + 1]:
                    i += 1
                else:
                    break
        print(K + i)