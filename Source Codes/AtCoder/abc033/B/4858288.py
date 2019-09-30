N = int(input())

s_max = ''
p_max = -1
p_sum = 0
for i in range(N):
    S, P = input().split()
    P = int(P)

    if P > p_max:
        s_max = S
        p_max = P

    p_sum += P 

if p_max > p_sum/2:
    print(s_max)
else:
    print('atcoder')