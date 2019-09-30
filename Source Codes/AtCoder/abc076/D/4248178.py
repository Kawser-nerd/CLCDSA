N = int(input())
t = [0] + list(map(int, input().split())) + [0]
v = [0] + list(map(int, input().split())) + [0]
for i in range(N, 0, -1):
    v[i] = min(v[i], v[i + 1] + t[i])
for i in range(1, N + 1):
    v[i] = min(v[i], v[i - 1] + t[i])
ans = 0
v_f = 0
for i in range(1, N + 1):
    v_l = min(v_f + t[i], v[i + 1], v[i])
    if 2 * v[i] - v_f - v_l <= t[i]:
        ans += (v[i] + v_f) * (v[i] - v_f) / 2 + v[i] * (t[i] - 2 * v[i] + v_f + v_l) + (v[i] + v_l) * (v[i] - v_l) / 2
    else:
        t_1 = (t[i] + v_l - v_f) / 2
        t_2 = t[i] - t_1
        ans += (2 * v_f + t_1) * t_1 / 2 + (2 * v_l + t_2) * t_2 / 2
    v_f = v_l
print('{:.10f}'.format(ans))