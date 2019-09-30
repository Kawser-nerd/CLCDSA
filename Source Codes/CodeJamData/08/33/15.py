import sys

def genseq(n,m,X,Y,Z,A):
    s=[]
    for i in range(n):
        s.append(A[i % m])
        A[i % m]=(X*A[i % m] + Y*(i+1)) % Z
    return s

def go_seq(seq):
    s=[0 for x in range(len(seq))]
    for i in range(len(seq)):
        s[i]=1

        for j in range(i):
            if seq[i]>seq[j]:
                s[i]+=s[j]
    return sum(s)

def go(name):
    f=file(name)

    line=f.readline().strip()
    total=int(line)
    
    for i in range(total):
        n,m,X,Y,Z=[int(x) for x in f.readline().strip().split()]
        A=[]
        for j in range(m):
            A.append(int(f.readline().strip()))

        seq=genseq(n,m,X,Y,Z,A)
    
        r=go_seq(seq) % 1000000007
        print "Case #%d: %d" %(i+1, r)
    f.close()

            
try:
    fn=sys.argv[1]
except:
    print "Usage:\n", "python", sys.argv[0]+" input_file_name"
    sys.exit(1)

go(fn)
