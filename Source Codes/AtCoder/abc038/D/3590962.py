N = int(input())
rec = []
for i in range(N):
    w, h = map(int, input().split())
    rec.append((w, h))

rec = sorted(rec, key=lambda x: (x[1], -x[0]))
M = 10 ** 5 + 5
data = [0] * M


def update(k, x):
    while k < M:
        data[k] = max(data[k], x)
        k += k & -k


def get(k):
    s = 0
    while k > 0:
        s = max(s, data[k])
        k -= k & -k

    return s


ans = 0
for w, h in rec:
    num = get(w - 1) + 1
    ans = max(ans, num)
    update(w, num)

print(ans)