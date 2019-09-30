import itertools

def solve_triangle(a, b, c):
    S = abs((b[0]-a[0])*(c[1]-a[1]) - (c[0]-a[0])*(b[1]-a[1]))
    return (S % 2 == 0) and (S != 0)

N = int(input())

lattice = []

for _ in range(N):
    lattice.append(list(map(int, input().split())))

cnt = 0
for triangle in itertools.combinations(lattice, 3):
    if solve_triangle(triangle[0], triangle[1], triangle[2]):
        cnt += 1

print(cnt)