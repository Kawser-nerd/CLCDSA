import bisect

n, h = [int(item) for item in input().split()]

a_s, b_s = [], []
for i in range(n):
    a, b = [int(item) for item in input().split()]
    a_s.append(a)
    b_s.append(b)
    
a_s.sort()
b_s.sort()
throwable = bisect.bisect(b_s, a_s[-1])
throw_sum = sum(b_s[throwable:])

ans = 0
for item in b_s[throwable:][::-1]:
    h -= item
    ans += 1
    if h <= 0:
        print(ans)
        exit()

ans += h // a_s[-1]
if h % a_s[-1] != 0:
    ans += 1
if ans <= 0:
    ans = 1
print(ans)