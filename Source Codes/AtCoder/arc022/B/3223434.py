N = int(input())
a = list(map(int, input().split()))
ans, l, count, _set = 1, 0, 1, {a[0]}
add, remove = _set.add, _set.remove

for n in a[1:]:
    while n in _set:
        remove(a[l])
        count -= 1
        l += 1
    add(n)
    count += 1
    if ans < count:
        ans = count
print(ans)