from heapq import heappushpop

N, K = map(int, input().split())
a = list(map(lambda x: (-int(x[1]), x[0]), enumerate(input().split(), start=1)))
ans = sorted(a[:K-1]+[(float("-inf"), 1)])

print(*([heappushpop(ans, n) and ans[0][1] for n in a[K-1:]]), sep="\n")