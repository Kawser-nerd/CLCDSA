N = int(input())
NG1 = int(input())
NG2 = int(input())
NG3 = int(input())
NG = [NG1, NG2, NG3]

for _ in range(100):
    if N in NG:
        break
    N -= 3
    if N in NG:
        N += 1
        if N in NG:
            N+= 1
            if N in NG:
                break

print("YES" if N < 1 else "NO")