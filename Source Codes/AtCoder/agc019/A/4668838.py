q, h, s, d = map(int, input().split())
o = min(q * 4, h * 2, s)
t = min(o * 2, d)
n = int(input())
print(n//2 * t + n % 2 * o)