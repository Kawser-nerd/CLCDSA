n = int(input())
A = []
B = []
for i in range(n):
    a,b = map(int, input().split())
    A.append(a)
    B.append(b)
ans = 0
for i in range(n-1,-1,-1):
    a = A[i] + ans
    b = B[i]
    #print(a,b)
    if a % b == 0:
        tmp = 0
    else:
        tmp = (a // b + 1) * b - a
    ans += tmp
print(ans)