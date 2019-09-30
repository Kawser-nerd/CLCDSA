S, N = map(int, input().split())
A = list(map(int, input().split()))
O = [a for a in A if a % 2 == 1]
E = [a for a in A if a % 2 == 0]

if len(O) > 2:
    print("Impossible")
else:
    A = O[:min(len(O), 1)] + E + O[1:]
    B = A[:] + ([0] if N == 1 else [])
    B[0] -= 1
    B[-1] += 1
    if B[0] == 0:
        B = B[1:]
    print(*A, sep=" ")
    print(len(B))
    print(*B, sep=" ")