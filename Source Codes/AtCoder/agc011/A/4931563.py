from collections import defaultdict

N, C, K = map(int, input().split())

ps = defaultdict(int)
for i in range(N):
    T = int(input())
    ps[T] += 1

count = 0
current_ps = 0
time_limit = 10**9+K+1

for t in sorted(ps.keys()):
    if t > time_limit and current_ps > 0:
        count += 1
        current_ps = 0

    if current_ps == 0:
        time_limit = t + K

    current_ps += ps[t]
    while current_ps >= C:
        count += 1
        current_ps -= C
        time_limit = t + K

if current_ps > 0:
    count += 1

print(count)