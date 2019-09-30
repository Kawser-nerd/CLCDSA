N, Va, Vb, L = map(int, input().split())

K = Vb / Va

for n in range(N):
    L *= K

print('%.7f' % L)