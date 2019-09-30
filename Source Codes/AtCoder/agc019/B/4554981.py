S = input()
N = len(S)
ans = N * (N - 1) // 2 + 1
a = []
cnt = 0
for c in [chr(i) for i in range(97, 97+26)]:
    cnt = S.count(c)
    a.append(cnt * (cnt - 1) // 2)
ans -= sum(a)
print(ans)