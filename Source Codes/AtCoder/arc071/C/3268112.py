S = input()
T = input()

ms = [0]
for s in S:
    if s == 'A':
        ms.append(ms[-1] + 1)
    else:
        ms.append(ms[-1] - 1)

mt = [0]
for t in T:
    if t == 'A':
        mt.append(mt[-1] + 1)
    else:
        mt.append(mt[-1] - 1)

q = int(input())
for _ in range(q):
    a, b, c, d = map(int, input().split())
    if (ms[b] - ms[a - 1]) % 3 == (mt[d] - mt[c - 1]) % 3:
        print('YES')
    else:
        print('NO')