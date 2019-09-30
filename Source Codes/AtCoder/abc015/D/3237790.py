W = int(input())
N, K = [int(x) for x in input().split()]
G = [0] * N

def calc(i, max_a, w, k):
    if i >= N or k >= K:
        return 0
    g_i0 = G[i][0]
    a = calc(i + 1, max_a if max_a < g_i0 else g_i0, w, k)
    if w + g_i0 > W or g_i0 > max_a:
        return a
    b = G[i][1] + calc(i + 1, max_a, w + g_i0, k + 1)
    return a if a > b else b

for i in range(N):
    A, B = [int(x) for x in input().split()]
    G[i] = (A, B)
G.sort(key=lambda x:x[1], reverse=True)
# print(G)
print(calc(0, 100000, 0, 0))