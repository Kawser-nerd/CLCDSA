A, B, K =map(int, input().split())
ans = []


for i in range(K):
    if A <= A+i <= B:
        ans.append(A+i)


for i in range(K):
    if A <= B-(K-1)+i <= B and B-(K-1)+i not in ans:
        ans.append(B-(K-1)+i)
for a in ans:
    print(a)