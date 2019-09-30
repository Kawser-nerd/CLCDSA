import collections


N, K = map(int, input().split(' '))
A = input().split(' ')
counter_A = collections.Counter(A)
diversity = len(counter_A) - K
ans = 0
if diversity <= 0:
    print(ans)
    exit()
for item in counter_A.most_common()[-1*diversity:]:
    ans += item[1]
print(ans)