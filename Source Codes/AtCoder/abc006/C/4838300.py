n,m = [int(i) for i in input().split()]

if m < 2*n or 4*n < m:
    print(-1, -1, -1)
else:
    f = m-2*n
    baby = f // 2
    old = f % 2
    adult = n - baby - old
    print(adult, old, baby)