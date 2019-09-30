N, K = map(int, input().split())
A = list(map(int, input().split()))

count = {}

for a in A:
    if a in count.keys():
        count[a] += 1
    else:
        count[a] = 1

v = list(sorted(count.values(), key=lambda x: -x))

ret = 0
for i in range(K, len(v)):
    ret += v[i]
print(ret)