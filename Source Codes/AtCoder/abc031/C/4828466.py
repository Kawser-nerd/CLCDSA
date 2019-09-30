import sys
input = sys.stdin.readline

N = int(input())
a= [int(_) for _ in input().split()]
Tmax = -float('inf')

for i in range(N):
    Amax = -float('inf')
    Aindex = -1
    for j in range(N):
        if i == j:
            continue
        else:
            if i < j:
                tmp = sum(a[i+1:j+1:2])
            else:
                tmp = sum(a[j+1:i+1:2])
            if tmp > Amax:
                Amax = tmp
                Aindex = j
    if i < Aindex:
        tmp = sum(a[i:Aindex+1:2])
    else:
        tmp = sum(a[Aindex:i+1:2])
    if tmp > Tmax:
        Tmax = tmp

print(Tmax)