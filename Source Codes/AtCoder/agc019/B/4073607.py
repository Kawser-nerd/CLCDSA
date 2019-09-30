A = input()
D = [0]*(26)
ans = 0
D[ord( A[0]) - ord("a")] = 1
for i, a in enumerate(A[1:]):
    ans += i + 1- D[ ord( a) - ord("a")]
    D[ ord( a) - ord("a")] += 1
print( ans + 1)