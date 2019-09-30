import bisect

nums = [0, 0] + [1 for i in range(10**5-2)]
x = []

for i in range(2, 10**5):
    if nums[i]:
        for l in range(i*2, 10**5, i):
            nums[l] = 0
        if nums[(i+1)//2]:
            x.append(i)

Q = int(input())
for i in range(Q):
    l, r = list(map(int, input().split()))
    l_ = bisect.bisect_left(x, l)
    r_ = bisect.bisect_right(x, r)
    print(r_-l_)