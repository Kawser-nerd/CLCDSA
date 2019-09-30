from collections import Counter

N, C = map(int, input().split(" "))
A = [int(input()) for _ in range(N)]

one = sorted(Counter(A[::2]).items(), key=lambda x:x[1], reverse=True) + [(0, 0)]
two = sorted(Counter(A[1::2]).items(), key=lambda x:x[1], reverse=True) + [(0, 0)]
if one[0][0] == two[0][0]:
    print(C*min(N-one[0][1]-two[1][1], N-one[1][1]-two[0][1]))
else:
    print(C*(N-one[0][1]-two[0][1]))