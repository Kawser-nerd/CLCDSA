from itertools import accumulate

N, K = map(int, input().split())
a_list = list(map(int, input().split()))

b_list = []
for a in a_list:
    if a > 0:
        b_list.append(a)
    else:
        b_list.append(0)
b_list = list(accumulate(b_list))
a_acc = list(accumulate(a_list))

b_list.insert(0, 0)
b_list.append(b_list[-1])
a_acc.insert(0, 0)
ans = 0


for i in range(N - K + 1):

    ans = max(ans, b_list[i] + a_acc[i + K] - a_acc[i] + b_list[N] - b_list[i + K])
    ans = max(ans, b_list[i] + b_list[N] - b_list[i + K])
print(ans)