import sys
input = sys.stdin.readline

n = int(input())
a = [list(map(int, input().split())) for _ in range(3)]

for j in range(n):
    if not ((a[0][j] - 1 == a[1][j] and a[2][j] + 1 == a[1][j]) or (a[0][j] + 1 == a[1][j] and a[2][j] - 1 == a[1][j])):
        print("No")
        exit()

for j in range(n):
    if (j % 2) ^ (((a[0][j] - 1) // 3) % 2) == 1:
        print("No")
        exit()

# BIT
def add(a, w, bit):
    x = a
    while x <= 3 * n:
        bit[x] += w
        x += x & -x

def solve(a, bit):
    ret = 0
    x = a
    while x > 0:
        ret += bit[x]
        x -= x & -x
    return ret

bit_odd = [0] * (3*n+1)
inv_odd = 0
flip_even = 0
for j in range(n):
    if j % 2 == 1:
        if a[0][j] > a[1][j]:
            flip_even += 1
    else:
        inv_odd += j//2 - solve(a[0][j], bit_odd)
        add(a[0][j], 1, bit_odd)
if flip_even % 2 != inv_odd % 2:
    print("No")
    exit()


bit_even = [0] * (3*n+1)
inv_even = 0
flip_odd = 0
for j in range(n):
    if j % 2 == 0:
        if a[0][j] > a[1][j]:
            flip_odd += 1
    else:
        inv_even += j//2 - solve(a[0][j], bit_even)
        add(a[0][j], 1, bit_even)
if flip_odd % 2 != inv_even % 2:
    print("No")
    exit()

print("Yes")