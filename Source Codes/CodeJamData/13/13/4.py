def readline():
    return [int(x) for x in raw_input().split(' ')]
def prod(l):
    m=1
    for i in l:m*=i
    return m
readline()
r,n,m,k=readline()

xs = [[]]
for i in range(n):
    xs=[y+[j] for j in range(2,m+1) for y in xs]
#print xs

ks= {}
kxs = [{} for x in xs]
j=0
for x in xs:
    vals = [[]]
    for i in x:
        vals=[y+[i] for y in vals]+vals
    
    #print vals
    for val in vals:
        k = prod(val)
        if k in ks:
            ks[k]+=1
        else:
            ks[k]=1
        if k in kxs[j]:
            kxs[j][k]+=1
        else:
            kxs[j][k]=1
    j+=1

#print ks
#print kxs

print "Case #1:"

for _ in range(r):
    prob=[1.0]*len(xs)
    given=readline()
    for k in given:
        for i in range(len(xs)):
          prob[i] *= kxs[i][k] if k in kxs[i] else 0
          prob[i] /= ks[k] if k in ks else 0
    #print prob
    m=0.0
    mi=0
    for i in range(len(xs)):
        if prob[i]>m:
            m=prob[i]
            mi=i
    #print mi
    print ''.join(str(y) for y in xs[mi])
          
