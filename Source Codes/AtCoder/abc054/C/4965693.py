N, M = map(int, input().split())
L = [[] for i in range(N)]
for i in range(M):
    a,b = map(int, input().split())
    L[a-1].append(b-1)
    L[b-1].append(a-1)
    
import itertools
count = 0
for p in itertools.permutations(range(N)):
    if p[0] == 0:
#         print("p",p)
        flag = True
        for i in range(N-1):
#             print(p[i+1], L[p[i]])
            if not p[i+1] in L[p[i]]:
                flag = False
#             print(flag)
        if flag:
            count += 1
print(count)