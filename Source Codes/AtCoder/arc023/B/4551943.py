# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)

R, C, D = map(int, input().split())

even = (D % 2 == 0)

ans = 0
for i in range(R):
    l = list(map(int, input().split()))
    for j, c in enumerate(l):
        if i+j <= D:
            if even:
                if (i+j) % 2 == 0:
                    ans = max(ans, l[j])
            else:
                if (i+j) % 2 == 1:
                    ans = max(ans, l[j])
        else:
            break
print(ans)