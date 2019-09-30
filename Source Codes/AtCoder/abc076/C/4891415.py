import copy
S=list(input())
S1 = "".join(S)
T=list(input())
T1 = "".join(T)
F = ["?"]*len(T)
F1 = "".join(F)
l =[]
M =[]
index =[]
B = copy.deepcopy(S)
for i in range(len(S)-len(T)+1):
    A = copy.deepcopy(S)
    c = A[i:len(T)+i]
    while "?" in c:
        c[c.index("?")] = T[c.index("?")]
    if c==T:
        A = copy.deepcopy(S)
        A[i:len(T)+i] = c
        while "?"in A:
            A[A.index("?")]="a"
        M.append(A)
if 0<len(M):
    M.sort()
    print("".join(M[0]))
else:
    print("UNRESTORABLE")