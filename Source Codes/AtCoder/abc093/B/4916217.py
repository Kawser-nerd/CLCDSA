A, B, K = map(int, input().split())
mitasu_seisu = []
for i in range(A, min(A + K, B)):
    mitasu_seisu.append(i)
for j in range(max(A, B - K + 1), B + 1):
    mitasu_seisu.append(j)
for k in sorted(set(mitasu_seisu)):
    print(k)