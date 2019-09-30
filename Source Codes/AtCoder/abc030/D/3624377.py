import sys
N,a=map(int,input().split())
k=int(input())
B=list(map(int,input().split()))

if k<=10**5:
    NOW=a
    for i in range(k):
        NOW=B[NOW-1]

    print(NOW)
    sys.exit()
        


LIST=[0]*(N+1)

NOW=a
for i in range(N+1):
    LIST[NOW]+=1
    if LIST[NOW]==2:
        break
    NOW=B[NOW-1]

ROOP=NOW
ROOPEND=i

NOW=a
for i in range(N):
    if NOW==ROOP:
        break
    NOW=B[NOW-1]

ROOPBEGIN=i

ROOPS=(ROOPEND-ROOPBEGIN)

k=(k-ROOPBEGIN)%ROOPS

NOW=ROOP
for i in range(k):
    NOW=B[NOW-1]

print(NOW)