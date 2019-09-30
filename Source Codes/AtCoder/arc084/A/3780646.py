import bisect

N = int(input())
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
c = list(map(int, input().split(' ')))

sorted_a = sorted(a)
sorted_c = sorted(c)
ans = 0
for each_b in b:
    ai = bisect.bisect_left(sorted_a, each_b)
    ci = bisect.bisect_right(sorted_c, each_b)
    ans += ai * (len(c)-ci)
print(ans)