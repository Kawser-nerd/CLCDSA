import collections


N = int(input())
A = list(map(int, input().split(' ')))
A_plus = [A[i]+1 for i in range(len(A))]
A_minus = [A[i]-1 for i in range(len(A))]
ans = collections.Counter(A + A_plus + A_minus).most_common()[0][1]
print(ans)