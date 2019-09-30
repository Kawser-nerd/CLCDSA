N,K=map(int,input().split())
p=[int(i)-1 for i in input().split()]
q=[int(i)-1 for i in input().split()]
def inv(seq):
    res=[0 for i in range(N)]
    for i in range(N):
        res[seq[i]]=i
    return res
def times(seq1,seq2):
    res=[0 for i in range(N)]
    for i in range(N):
        res[i]=seq1[seq2[i]]
    return res
md=[[0 for i in range(N)] for i in range(6)]
for i in range(N):
    md[0][i]=p[i]
    md[1][i]=q[i]
for i in range(2,6):
    md[i]=times(md[i-1],inv(md[i-2]))
A=times(times(q,inv(p)),times(inv(q),p))
T=(K-1)//6
def expseq(seq,k):
    if k==0:
        return [i for i in range(N)]
    elif k==1:
        return seq
    elif k%2==0:
        return expseq(times(seq,seq),k//2)
    else:
        return times(expseq(times(seq,seq),k//2),seq)
tmp=expseq(A,T)
ans=times(times(tmp,md[(K-1)%6]),inv(tmp))
print(" ".join([str(i+1) for i in ans]))