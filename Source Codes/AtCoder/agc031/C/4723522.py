N, A, B = map(int, input().split())
if bin(A).count("1")%2 == bin(B).count("1")%2:
    print("No")
    exit(0)

print("Yes")

ans = []
def solve(c, A, B, S):
    P = (A ^ B) & S
    b = 1
    if c == 1:
        ans.append(A)
        ans.append(B)
        return
    while not P & b:
        b <<= 1

    S0 = S ^ b
    k = 1
    while not S0 & k:
        k <<= 1
    C = A ^ k
    solve(c-1, A, C, S0)
    solve(c-1, C^b, B, S0)

solve(N, A, B, 2**N-1)
print(*ans)