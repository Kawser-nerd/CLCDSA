N, Va, Vb, L = [int(_) for _ in input().split()]

result = L
for i in range(N):
    t = result / Va
    result = t * Vb

print("%.12f" % result)