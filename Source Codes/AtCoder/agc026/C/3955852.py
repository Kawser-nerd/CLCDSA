N = int(input())
S = input()


def count(s):
    res = {}
    for i in range(2**N):
        t1 = ''
        t2 = ''
        for j in range(N):
            if i & 1 << j:
                t1 += s[j]
            else:
                t2 += s[j]
        k = t1 + t2 + 'abcdefghijklmnoprst'[bin(i).count('1')]
        res[k] = res.get(k, 0) + 1
    return res


h1 = count(S[:N])
h2 = count(S[N:][::-1])
ans = 0
for k, v in h1.items():
    if k in h2:
        ans += v * h2[k]
print(ans)

# https://www.youtube.com/watch?v=eB0eT-948Vw