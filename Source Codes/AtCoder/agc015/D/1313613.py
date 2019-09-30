# D
res = 0

A = int(input())
B = int(input())

def pow2_floor_log2(x):
    res = 1
    while res*2 <= x:
        res *= 2
    return res

if A == B:
    res += 1
    
while A < B:
    # find log2A and log2B
    C = pow2_floor_log2(B)
    if A < C:
        # A to C
        res += C - A
        if B > C:
            B_ = C + pow2_floor_log2(B - C)*2 - 1
        else:
            B_ = C
        if C + A <= B_:
            res += C
            break
        else:
            res += (C - A) + (B_ - C + 1)
            break
    else:
        A -= C
        B -= C

print(res)