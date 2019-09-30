N = int(input())
a_s = [int(x) for x in input().split()]

average = sum(a_s)
average /= len(a_s) * 1.0

ans = -1
for target in range(int(average), int(average) + 2):
    c = sum(map(lambda x: (x - target) * (x - target), a_s))
    if ans < 0:
        ans = c
    else:
        ans = min(ans, c)

print(ans)