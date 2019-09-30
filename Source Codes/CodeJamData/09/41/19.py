f = open('A_Rnd2.in', 'r')
out=open('A_Rnd2.out','w')
cases = int(f.readline()[:-1])

def isok(a):
    for i in range(len(a)):
        if a[i]>i:
            return False
    return True
def maxindex(a):
    max = -1
    for i in range(len(a)):
        if a[i]==1:
            max=i
    return max
for i in range(cases):
    n = int(f.readline()[:-1])
    a=[]
    for j in range(n):
        s=f.readline()[:-1]
        a.append(maxindex([int(x) for x in s]))
    print a
    ct=0
    row=0
    while (not isok(a)):
        m=-1
        for j in range(row,len(a)):
            if a[j]<=row:
                m=j
                break
        a=a[:row]+[a[j]]+a[row:j]+a[j+1:]
        print a
        ct+=m-row
        row+=1
    print ct
    out.write("Case #"+str(i+1)+": "+str(ct)+"\n")