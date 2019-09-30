N = int(input())
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
c = list(map(int, input().split(' ')))

sorted_a = sorted(a)
sorted_b = sorted(b)
sorted_c = sorted(c)
ans = 0
before_a = 0
before_c = 0
count_a = 0
count_c_rest = 0
for each_b in sorted_b:
    for ai in range(before_a, len(sorted_a)):
        if each_b > sorted_a[ai]:
            count_a += 1
            before_a += 1
        else:
            before_a = ai
            break

    for ci in range(before_c, len(sorted_c)):
        if sorted_c[ci] <= each_b:
            count_c_rest += 1
            before_c += 1
        else:
            before_c = ci
            break

    ans += count_a * (len(sorted_c)-count_c_rest)
print(ans)