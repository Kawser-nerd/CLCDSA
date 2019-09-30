a_i, a_o, a_t, a_j, a_l, a_s, a_z = map(int, input().split())

tri_use = min(a_j, a_l, a_i)
p1 = tri_use * 3

j_ex = a_j - tri_use
l_ex = a_l - tri_use
i_ex = a_i - tri_use

p2 = j_ex//2 * 2 + l_ex//2 * 2 + i_ex//2 * 2

extra = j_ex%2 + l_ex%2 + i_ex%2

p3 = 0
if tri_use >= 1:
    if extra == 2:
        p3 = 1
    elif extra == 3:
        p3 = 3
        
print(p1 + p2 + p3 + a_o)