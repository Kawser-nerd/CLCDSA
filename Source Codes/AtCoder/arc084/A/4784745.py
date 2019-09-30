N = int(input())
A = [int(_) for _ in input().split()]
B = [int(_) for _ in input().split()]
C = [int(_) for _ in input().split()]

A = sorted(A)
B = sorted(B)
C = sorted(C)
ans = 0
midnum = []
index = 0

for i in B:
    while True:
        if index == N or A[index] >= i:
            midnum.append(index)
            break
        else:
            index += 1

index = 0
midCnum = []
tmp = 0
for i in midnum:
    tmp += i
    midCnum.append(tmp)

for i in C:
    while True:
        if index == N:
            ans += midCnum[index-1]
            break
        elif i <= B[index]:
            if index != 0:
                ans += midCnum[index-1]
            break
        else:
            index += 1

print(ans)