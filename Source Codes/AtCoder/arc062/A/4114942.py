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

    d = max(floor(v_T, t), floor(v_A, a))
    v_T = d*t
    v_A = d*a


print(v_T+v_A)