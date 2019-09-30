S = list(input())
A = list(map(int, input().split()))
A.sort()
for i in range(4):
    S.insert(A[i]+i, '"')
print(''.join(S))