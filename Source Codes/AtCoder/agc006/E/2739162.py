def merge_and_count_rec(A, W, l, r):
    if l+1 >= r:
        return 0
    m = (l+r)//2
    cnt  = merge_and_count_rec(A, W, l, m)
    cnt += merge_and_count_rec(A, W, m, r)
    i,j,k = l,m,l
    while i<m and j<r:
        if A[i]<=A[j]:
            W[k] = A[i]
            i+=1
        else:
            W[k] = A[j]
            j+=1
            cnt += m-i
        k+=1
    if i<m:
        W[k:r] = A[i:m]
    if j<r:
        W[k:r] = A[j:r]
    A[l:r] = W[l:r]
    return cnt

N = int(input())
A = tuple(list(map(int,input().split())) for _ in range(3))
O = []
ok = True
flip = [0,0]
for i in range(N):
    ok &= (A[1][i] % 3) == 2
    ok &= sorted((A[0][i], A[1][i], A[2][i]))==[A[1][i]-1, A[1][i], A[1][i]+1]
    dist = abs(A[1][i]//3 - i)
    ok &= (dist % 2) == 0
    order = [A[0][i], A[1][i], A[2][i]] == [A[1][i]-1, A[1][i], A[1][i]+1]
    if ((dist//2)%2 == 0) != order:
        flip[i%2] += 1

B = A[1][0::2]
hb = merge_and_count_rec(B, A[0], 0, len(B))
C = A[1][1::2]
hc = merge_and_count_rec(C, A[0], 0, len(C))

ok &= (hb % 2) == (flip[1]%2)
ok &= (hc % 2) == (flip[0]%2)
print("Yes" if ok else "No")