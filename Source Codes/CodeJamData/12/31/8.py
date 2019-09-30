#! /usr/bin/python
# -*-coding:Utf-8 -*

def readint():    return int(raw_input())
def readarray(f): return map(f, raw_input().split())

T = readint()
for t in range(T):
    print 'Case #'+str(t+1)+':',

    N = readint()
    
    H = []
    M = []
    roots = list(range(N))
    for i in range(N):
        input = readarray(int)
        M.append(input[0])
        H.append(map(lambda x:x-1, input[1:]))
        roots = [x for x in roots if x not in H[-1]]
    
    flag = False
    for r in roots:
        V = [False]*N
        V[r] = True
        Q = [r]
        while Q and not flag:
            p = Q.pop()
            for s in H[p]:
                if V[s]:
                    flag = True
                else:
                    V[s] = True
                    Q.append(s)
        if flag:
            break

    print 'Yes' if flag else 'No'
