# -*- encoding:  UTF-8 -*-
import math

def crossY(y, R): # 横线交
    '''float, float -> complex'''
    return math.sqrt(R * R - y * y) + y * 1j

def crossX(x, R): # 竖线交
    '''float, float -> complex'''
    return x + math.sqrt(R * R - x * x) * 1j

def Sfan(p1, p2, R):
    '''complex, complex, float -> float'''
    t = p1 / p2
    # R = abs(t)
    return abs(.5 * R * R * math.atan(t.imag / t.real))

def Striangle(p1, p2): # 就是叉积 / 2
    '''complex, complex -> float'''
    return .5 * (p1.real*p2.imag - p1.imag*p2.real)

def Spoly(*p_list):
    result = 0.0
    for i in xrange(len(p_list)-1):
        result += Striangle(p_list[i],p_list[i+1])
    return abs(result)

def Sarea(p, g, R):
    '''complex, float, float -> float'''
    p_tr = p + g + g*1j # top-right
    if abs(p_tr) <= R :
        return g*g
    if abs(p) >= R :
        return -1.0

    p_br = p + g # bottom-right corner
    p_tl = p + g*1j # top-left corner
    r_br = abs(p_br)
    r_tl = abs(p_tl)
    c_r, c_b, c_t, c_l = [None] * 4
    if (r_br <= R):
        c_r = crossX(p_br.real, R)
    else:
        c_b = crossY(p_br.imag, R)
    if (r_tl <= R):
        c_t = crossY(p_tl.imag, R)
    else:
        c_l = crossX(p_tl.real, R)

    # 现在分类讨论
    if c_r and c_t :
        return g * g + Sfan(c_r, c_t, R) - Spoly(c_r, p_tr, c_t)
    if c_r and c_l :
        return g * g + Sfan(c_r, c_l, R) - Spoly(c_r, p_tr, p_tl, c_l)
    if c_t and c_b :
        return g * g + Sfan(c_b, c_t, R) - Spoly(c_b, p_br, p_tr, c_t)
    else :
        return Sfan(c_b, c_l, R) - Spoly(c_b, p, c_l)

def Shole(f, R, t, r, g):
    R_mod = R - t - f
    if R_mod <= 0 : # 拍太小
        return 0
    g_mod = g - 2 * f
    if g_mod <= 0 : # 线太粗
        return 0
    # 现在苍蝇大小为0
    vx = g + 2 * r + 0j
    vy = vx * 1j
    p0 = r + f
    p0 += p0*1j # 初始方形
    result = 0.0
    while True:
        tmp0 = Sarea(p0, g_mod, R_mod)
        if tmp0 == -1:
            break
        result += tmp0
        p1 = p0 + vx
        while True:
            tmp1 = Sarea(p1, g_mod, R_mod)
            if tmp1 == -1:
                break
            result += tmp1
            p1 += vx
        p0 += vy # 下一行
    return result * 4

f_input=open('C-large.in','rb')
f_output=open('output.txt','w')
f_output.seek(0)
N = int(f_input.readline())
for case in xrange(1,N+1):
    f, R, t, r, g = [ float(t) for t in f_input.readline().split(' ') ]
    p = 1 - Shole(f, R, t ,r ,g)/(R*R*3.1415926535)
    f_output.write('Case #%d: %f\n' % (case, p))
f_output.close()
f_input.close()
