from heapq import nsmallest


def get_add_list():
    cache = {}

    def add_list(s, t):
        global new_lists, removables
        l = t - s
        if l >= k:
            new_lists.append((s, t))

            if (s, t) in cache:
                removables.extend(cache[s, t])
                return

            cache[s, t] = nsmallest(l - k + 1, aaa[s:t])
            removables.extend(cache[s, t])

    return add_list


n, k, q = map(int, input().split())
aaa = list(map(int, input().split()))
srt = sorted(set(aaa))
lists = [(0, n)]
ans = float('inf')
add_list = get_add_list()
for a in srt:
    new_lists = []
    removables = []
    for s, t in lists:
        r = s
        for i, b in enumerate(aaa[s:t]):
            if a > b:
                add_list(r, s + i)
                r = s + i + 1
        add_list(r, t)
    if len(removables) < q:
        break
    removables.sort()
    ans = min(ans, removables[q - 1] - a)
    lists = new_lists

print(ans)