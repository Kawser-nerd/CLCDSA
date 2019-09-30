# ??????n_C_r
def comb(n,r):
    r = min(r,n-r)
    result = 1
    for i in range(n-r+1,n+1):
        result *= i
    for i in range(1,r+1):
        result //= i
    return result

N,A,B = map(int,input().split())
V = list(map(int,input().split()))

V.sort(reverse=True)

ave = sum(V[:A])/A
pat = 0
note = 0
cnt = 0
for v in V:
    if v > V[A-1]:
        note += 1
    elif v == V[A-1]:
        cnt += 1
    elif v < V[A-1]:
        break

if V[0] == V[A-1]:
    for i in range(A-note,B+1-note):
        if i > cnt:
            break
        pat += comb(cnt,i)
else:
    pat = comb(cnt,A-note)

print(ave)
print(pat)