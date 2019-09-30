import bisect
N = int(input())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]

A.sort()
B.sort()
C.sort()
ans = 0

for i in range(N):

    count_a = bisect.bisect_left(A,B[i])
    count_c = N -bisect.bisect_right(C,B[i])
    ans += count_a*count_c
    
print(ans)