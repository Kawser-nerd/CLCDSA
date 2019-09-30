from fractions import gcd
N = int(input())
A = list(map(int, input().split()))
key = 1


def lcm(a, b):
    return a * b // gcd(a, b)


for a in A:
    key = lcm(key, a)
key -= 1
ans = 0
for a in A:
    ans += key % a
print(ans)