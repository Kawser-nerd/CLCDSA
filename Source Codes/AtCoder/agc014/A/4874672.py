A,B,C = map(int,input().split())
if A%2 == 1 or B%2 == 1 or C%2 == 1:
    print(0)
elif A == B == C:
    print(-1)
else:
    def Base_10_to_n(X, n):
        if X//n:
            return Base_10_to_n(X//n, n)+str(X%n)
        return str(X%n)
    A = Base_10_to_n(A, 2)[::-1]
    B = Base_10_to_n(B, 2)[::-1]
    C = Base_10_to_n(C, 2)[::-1]
    ans = 0
    for i in range(min(len(A),len(B),len(C))):
        if A[i] == B[i] == C[i]:
            ans += 1
        else:
            break
    print(ans)