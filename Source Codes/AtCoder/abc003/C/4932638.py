n, k = map(int, input().split())
r = list(map(int, input().split()))
r.sort()
t_rate = 0
for i in range(len(r)-k, len(r)):
    t_rate = (t_rate + r[i])/2
print(t_rate)