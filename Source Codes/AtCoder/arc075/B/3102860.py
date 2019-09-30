import heapq
n,a,b= map(int,input().split())
h =[int(input()) for i in range(n)]
h.sort()
p = a-b
def c(w):
    #w de umakuikkuka
    k = 0
    for i in range(n):
        l[i] = l[i]-b*w
        if l[i] > 0:
            k += l[i]//p
            if l[i] % p != 0:
                k += 1
    if w >= k:
        return True

s = 0
f = 10**14
while f-s >=2:
    m = (f+s)//2
    l = h[::]
    if c(m):
        f = m
    else:
        s = m
l = h[::]
if c(s):
    print(s)
else:
    print(f)