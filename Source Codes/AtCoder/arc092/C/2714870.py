N = int(input())
*A, = map(int, input().split())

def calc(A):
    if len(A) == 1:
        return [], A[0]
    res = []
    if len(A) % 2 == 0:
        res.append(len(A))
        A = A[:-1]
    if all(a <= 0 for a in A[::2]):
        ma = max(A[::2])
        i = 0
        while A[i] != ma:
            i += 1
            res.append(1)
        j = len(A)
        while i < j-1:
            res.append(j-i)
            j -= 1
        return res, ma

    l = 0; r = len(A)
    while A[0] < 0:
        res.append(1)
        res.append(1)
        A = A[2:]
    v = 0
    while len(A) > 2:
        if A[2] < 0:
            res.append(3)
            if len(A) > 4:
                A = A[:2] + A[4:]
            else:
                A = A[:2]
        else:
            res.append(2)
            A[2] += A[0]
            A = A[2:]
    if len(A) > 1:
        res.append(2)
    return res, A[0]
r, v = calc(A)
if len(A) > 1:
    r0, v0 = calc(A[1:])
    if v < v0:
        r = [1] + r0
        v = v0
print(v, len(r), *r, sep='\n')