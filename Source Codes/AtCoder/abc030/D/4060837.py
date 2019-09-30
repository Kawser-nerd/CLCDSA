N,a = map(int,input().split())
k = int(input())
L = list(map(int,input().split()))

for i in range(N) :
    L[i] -= 1
a -= 1
visit = [a]
ind = k
for i in range(N) :
    a = L[a]
    if a not in visit :
        visit.append(a)
    else :
        ind = visit.index(a)
        break
if k > ind :
    ans = visit[ind + (k - ind) % (len(visit) - ind)] + 1
else :
    ans = visit[ind]
print(ans)


#print(ind,k-ind,len(visit)-ind)