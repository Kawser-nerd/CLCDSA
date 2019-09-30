n, a, b, c, d = map(int, input().split())
diff_ab = abs(b-a)
diff_cd = d - c
mod = c + d
mod_ab = diff_ab % mod
MAX = d * (n-1)
MAX_mod = MAX % mod
MIN_mod = (c * (n-1)) % mod
if MAX >= diff_ab:
    if diff_cd * (n-1) + 1 >= mod:
        print("YES")
    else:
        if MAX_mod >= MIN_mod:
            if mod_ab <= MAX_mod and mod_ab >= MIN_mod:
                print("YES")
            else:
                print("NO")
        else:
            if mod_ab >= MIN_mod or mod_ab <= MAX_mod:
                print("YES")
            else:
                print("NO")
        
else:
    print("NO")