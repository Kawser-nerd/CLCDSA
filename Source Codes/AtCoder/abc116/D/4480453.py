N, K = map(int, input().split())
sushi = []
for i in range(N):
    s = list(map(int, input().split()))
    sushi.append(s)


sushi.sort(key=lambda x: x[1], reverse=True)

# pick from first
point = 0
neta_set = set()
removable_idx = list()
for i in range(K):
    s = sushi[i]
    point += s[1]
    if s[0] not in neta_set:
        neta_set.add(s[0])
    else:
        removable_idx.append(i)
point += len(neta_set) **2
max_point = point

# pick latest
for s in sushi[K:]:
    if len(removable_idx) == 0:
        break
    if s[0] in neta_set:
        continue
    idx = removable_idx[-1]
    count = len(neta_set)
    point += s[1] - sushi[idx][1]
    point += (count + 1) ** 2 - count ** 2
    neta_set.add(s[0])
    removable_idx = removable_idx[:-1]

    if point > max_point:
        max_point = point
print(max_point)