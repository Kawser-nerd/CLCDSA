def floor(a, b):
    return ((-a)//b)*-1


N = int(input())
ratio = []
for _ in range(N):
    ratio.append(list(map(int, input().split())))

v_T = ratio[0][0]
v_A = ratio[0][1]

for t, a in ratio[1:]:
    diff_t = t - v_T
    diff_a = a - v_A

    if diff_t < 0 and diff_a < 0:
        d = max(floor(v_T, t), floor(v_A, a))
        v_T = d*t
        v_A = d*a

    elif diff_t < 0:
        d = floor(v_T, t)
        v_T = d*t
        v_A = d*a

    elif diff_a < 0:
        d = floor(v_A, a)
        v_T = d*t
        v_A = d*a

    elif diff_t >= 0 and diff_a >= 0:
        m = max(diff_t, diff_a)
        v_T = t
        v_A = a

print(v_T+v_A)