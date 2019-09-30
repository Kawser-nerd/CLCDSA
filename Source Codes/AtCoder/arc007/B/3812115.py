# ???????????????
N, M = map(int, input().split(" "))
DISK = [int(input()) for _ in range(M)]

cases = list(range(N+1))
for disk in DISK:
    x = cases.index(disk)
    cases[0], cases[x] = disk, cases[0]

for case in cases[1:]:
    print(case)