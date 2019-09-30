N = int(input())
v_T = 1
v_A = 1
for _ in range(N):
    t, a = list(map(int, input().split()))
    d = max(((-v_T)//t)*(-1), ((-v_A)//a)*(-1))
    v_T = d*t
    v_A = d*a


print(v_T+v_A)