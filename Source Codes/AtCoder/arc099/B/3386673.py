K = int(input())
al = []

def sums(i):
    s = 0
    old = i
    while i>0:
        s += i%10
        i = i//10
    return (s,old)

for i in range(1,1000):
    al.append(sums(i))
for j in range(4,16):
    for k in range(100,1000):
        al.append(sums(k*(10**(j-3))+10**(j-3)-1))
anslist = []
al.reverse()
maxs,maxi = sums(10**15)
for j in al:
    if maxs*j[1] <= maxi*j[0]:
        anslist.append(j[1])
        maxs = j[0]
        maxi = j[1]
anslist.reverse()

for i in range(K):
    print(anslist[i])