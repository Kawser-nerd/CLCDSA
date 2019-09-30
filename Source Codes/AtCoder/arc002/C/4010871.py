# -*- coding: utf-8 -*-
# 1. ??????.
N = int(input())
C = str(input())

# 2. ???????????.
c = "ABXY"
ans = N
for la in range(4):
    for lb in range(4):
        # L?????.
        L = c[la:la+1] + c[lb:lb+1]
        for ra in range(4):
            for rb in range(4):
                # R?????.
                R = c[ra:ra+1] + c[rb:rb+1]
                # print(L + " " + R)
                if L != R:
                    lc = C.replace(L, "L")
                    rc = lc.replace(R, "R")
                    # ?????????.
                    ans = min(ans, len(rc))

# 3. ??.
print(ans)