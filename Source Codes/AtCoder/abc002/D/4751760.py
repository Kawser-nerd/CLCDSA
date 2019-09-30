import numpy as np

N, M = map(int,input().rstrip().split())

#????????????True??????
relationships = [[False for j in range(N+1)] for i in range(N+1)]
for i in range(M):
    a,b = map(int,input().rstrip().split())
    relationships[a][b] = True
    relationships[b][a] = True
for i in range(1,N+1):
    relationships[i][i] = True


def list_and(lst1, lst2):
    array = np.logical_and(np.array(lst1),np.array(lst2))
    return array.tolist()

ans = 0
for i in range(2**N):
    members = list(str(bin(i)).lstrip('0b').zfill(N+1))
    habatsu = list(map(int, members))
    for n in range(1,len(members)):
        if members[n] == '1':
            habatsu = list_and(habatsu,relationships[n])
    total = sum(habatsu)
    if ans < total:
        ans = total
print(ans)