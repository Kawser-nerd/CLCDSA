from heapq import heapify, heappop, heappush

n = int(input())
a = list(map(int, input().split()))
b = a[::-1]

left_q = a[:n]
heapify(left_q)
sum_left = sum(left_q)
left = [sum_left]

right_q = [-i for i in b[:n]]
heapify(right_q)
sum_right = sum(right_q)
right = [sum_right]

for i in range(n):
    if a[i+n] > left_q[0]:
        min_a = heappop(left_q)
        sum_left -= min_a
        sum_left += a[i+n]
        heappush(left_q, a[i+n])
    left.append(sum_left)
    if b[i+n] < -right_q[0]:
        min_b = heappop(right_q)
        sum_right -= min_b
        sum_right += -b[i+n]
        heappush(right_q,-b[i+n])
    right.append(sum_right)
ans = -float("inf")
for i, j in zip(left, right[::-1]):
    ans = max(ans, j+i)
print(ans)