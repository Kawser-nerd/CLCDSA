N,A,B = map(int,input().split())
h = []
for _ in range(N):
    h.append(int(input()))
h.sort(reverse=True)
def judge(M):
    i = 0
    j = M
    while True:
        if i >= N:
            return(True)
        if h[i] <= M*B:
            return(True)
        diff = h[i] - M*B
        needs = diff//(A-B)
        if diff%(A-B) != 0:
            needs += 1
        #need better/shorter impl
        j -= needs
        if j < 0:
            return(False)
        i += 1
#Binary search on the answer
ok = N*10**9
ng = 0
while ok > ng + 1:
    mid = (ok+ng)//2
    if judge(mid):
        ok = mid
    else:
        ng = mid
print(ok)