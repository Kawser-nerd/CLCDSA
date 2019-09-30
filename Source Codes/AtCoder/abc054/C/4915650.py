N, M = map(int, input().split())
L = [[] for i in range(N)]
for i in range(M):
    a,b = map(int, input().split())
    L[a-1].append(b-1)
    L[b-1].append(a-1)
    
import itertools
s = [int(i) for i in range(N)]
count = 0
for p in itertools.permutations(s, N):
#     print("p",p)
    if p[0] == 0:
#         print("Yes")
        flag = True
        for i in range(N-1):
#             print(p[i+1])
#             print(L[p[i]])
            if p[i+1] not in L[p[i]]:
                flag = False
        if flag:
#             print("flag!!")
            count += 1
print(count)