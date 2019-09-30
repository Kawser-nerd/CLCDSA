N, A, B = map(int, input().split())
if bin(A).count("1")%2 == bin(B).count("1")%2:
    print("No")
    exit(0)

print("Yes")

ans = []
def solve(c, A, B, S):
    P = A ^ B
    U = P & S
    b = 1
    if c == 1:
        ans.append(A)
        ans.append(B)
        return
    for i in range(N):
        if U & b:
            assert S & b > 0, (P, S, U, b)
            S0 = S ^ b
            k = 1
            while not S0 & k:
                k <<= 1
            C = A ^ k
            solve(c-1, A, C, S0)
            solve(c-1, C^b, B, S0)
            break
        b <<= 1
solve(N, A, B, 2**N-1)
print(*ans)