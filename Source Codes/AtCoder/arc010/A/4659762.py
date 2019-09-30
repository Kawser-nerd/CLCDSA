N, M, A, B = map(int, input().split())
flag = True

for i in range(M):
    if N <= A:
        N += B
    c = int(input())
    if N < c:
        flag = False
        break
    else:
        N -= c

print("complete" if flag else i+1)