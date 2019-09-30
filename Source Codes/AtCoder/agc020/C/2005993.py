import sys
readline = sys.stdin.readline

N = int(readline())
A = list(map(int, readline().split()))
S = sum(A)
bits = 1
for a in A:
    bits |= bits << a
ans = (S + 1) // 2
bits >>= ans
while True:
    if bits & 1:
        print(ans)
        exit()
    bits >>= 1
    ans += 1