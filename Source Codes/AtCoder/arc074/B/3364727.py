from heapq import heappushpop

N = int(input())
A = list(map(int, input().split()))

l_list = sorted(A[:N])
l_sum = [sum(l_list)]
for a in A[N:2 * N]:
    l_sum.append(l_sum[-1] - heappushpop(l_list, a) + a)

r_list = sorted(-x for x in A[-N:])
r_sum = [sum(r_list)]
for a in reversed(A[N:2 * N]):
    r_sum.append(r_sum[-1] - heappushpop(r_list, -a) - a)

ans = -(10 ** 15)
for l, r in zip(l_sum, r_sum[::-1]):
    ans = max(ans, l + r)
print(ans)