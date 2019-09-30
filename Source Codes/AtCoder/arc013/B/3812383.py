C = int(input())
NML = [list(map(int, input().split(" "))) for _ in range(C)]

N, M, L = zip(*[sorted(nml) for nml in NML])
print(max(N)*max(M)*max(L))