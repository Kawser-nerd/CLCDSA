d0 = [i for i in range(102) if i != 100]
d1 = [i * 100 for i in d0]
d2 = [i * 100 for i in d1]

D,N=map(int, input().split())

print([d0, d1, d2][D][N])