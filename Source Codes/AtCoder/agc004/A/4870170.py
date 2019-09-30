A, B, C = [int(x) for x in input().split()]

c1 = 0 if C % 2 == 0 else A * B
c2 = 0 if B % 2 == 0 else A * C
c3 = 0 if A % 2 == 0 else B * C
ans = min(c1, c2, c3)

print(ans)