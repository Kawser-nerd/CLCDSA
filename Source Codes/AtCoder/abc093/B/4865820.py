A, B, K = map(int,input().strip().split())

res = []

for a in range(A,min(A + K,B)):
    res.append(a)
for b in range(max(A,B - K + 1),B + 1):
    res.append(b)

for r in sorted(list(set(res))):
    print(r)