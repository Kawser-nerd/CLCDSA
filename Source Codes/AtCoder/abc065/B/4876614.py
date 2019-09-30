N = int(input())
A = []
for i in range(N):
    A.append([i+1, int(input())])

flag = False
cnt = 0
b, new = A[0]
for i in range(2*N):
    if b == 2:
        flag = True
        break

    cnt += 1
    b, new = A[new-1]

if flag:
    print(cnt)
else:
    print(-1)