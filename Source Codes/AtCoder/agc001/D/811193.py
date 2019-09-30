S, N = map(int, input().split())
A = list(map(int, input().split()))
O = [a for a in A if a % 2 == 1]
E = [a for a in A if a % 2 == 0]

if len(O) > 2:
    print("Impossible")
else:
    A = O[:min(len(O), 1)] + E + O[min(1, len(O)):]
    B = A[:] + ([0] if len(A) == 1 else [])
    B[0] -= 1
    B[-1] += 1
    if B[0] == 0:
        B = B[1:]
    print(" ".join(str(a) for a in A))
    print(len(B))
    print(" ".join(str(b) for b in B))