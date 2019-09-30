S = input()
N = len(S)

if N < 26:
    for i in range(97, 123):
        if chr(i) not in S:
            print(S + chr(i))
            exit()

min_c = [S[-1]]
for c, i in zip(S[-2::-1], range(24, -1, -1)):
    for mc in min_c:
        if c < mc:
            print(S[:i] + mc)
            exit()
    else:
        min_c.append(c)
        min_c.sort()
print(-1)