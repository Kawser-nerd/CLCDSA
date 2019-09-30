def add_list(buf, new_lists, removals):
    l = len(buf)
    if l >= k:
        sbf = sorted(buf)
        removals.extend(sbf[:l - k + 1])
        new_lists.append(buf)


n, k, q = map(int, input().split())
aaa = list(map(int, input().split()))
srt = sorted(set(aaa))
lists = [aaa]
ans = float('inf')
for a in srt:
    new_lists = []
    removals = []
    for lst in lists:
        buf = []
        for b in lst:
            if a > b:
                add_list(buf, new_lists, removals)
                buf = []
            else:
                buf.append(b)
        add_list(buf, new_lists, removals)
    if len(removals) < q:
        break
    removals.sort()
    ans = min(ans, removals[q - 1] - a)
    lists = new_lists

print(ans)