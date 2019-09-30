import sys

def cv_base(n,base):
    "lowest to highest, [] when n==0"
    arr=[]
    while n>0:
        arr.append(n%base)
        n/=base
    
    return arr

def cv_base10(arr,base):
    n=0
    for x in reversed(arr):
        n*=base
        n+=x

    return n
    
def replace_by(ls,ma):
    return map(lambda k:ma[k],ls)

def calc(s):
    n,l_from,l_to=s.split()
    
    fw1=dict(map(lambda (x,y):(y,x),enumerate(l_from)))
    fw2=dict(enumerate(l_to))
    
    n_normal=cv_base10(replace_by(reversed(n),fw1),len(l_from))
    n_temp=cv_base(n_normal,len(l_to))
    
    if n_normal==0:
        return fw2[0]
    else:
        return ''.join(reversed(replace_by(n_temp,fw2)))

def fetch_lines(n):
    return map(lambda i:sys.stdin.readline().rstrip(),range(n))

def replace_all(ls,table):
    return map(lambda x:table[x],ls)

def proc_case():
    # parse
    n_s=int(sys.stdin.readline().rstrip())
    ss=fetch_lines(n_s)
    n_q=int(sys.stdin.readline().rstrip())
    qs=fetch_lines(n_q)

    if n_q==0: return '0'
        
    # assign id and replace queries
    table=dict(zip(ss,range(n_s)))
    qs=replace_all(qs,table)

    # extract co-ids
    all_ids=set(range(n_s))
    qs_co=map(lambda x:all_ids-set([x]),qs)
    
    # brute force (very low branching factor)
    def s_length(pos_from,s_id):
        cnt=0
        for ss in qs_co[pos_from:]:
            if s_id in ss:
                cnt+=1
            else:
                break
        return cnt
        
    def search(pos):
      #  print '*SEARCH:pos=%d'%pos
        if pos>=n_q: return -1
        
        runs=map(lambda x:(x,s_length(pos,x)),qs_co[pos])
        m_length=max(map(lambda x:x[1],runs))
        runs=filter(lambda x:x[1]==m_length,runs)
        
        s_id_next=map(lambda x:x[0],runs)
      #  print '=>%d,%s'%(m_length,s_id_next)
        
        return 1+min(map(lambda s_id_n:search(pos+m_length),s_id_next))
        
    return str(search(0))


def proc_all():
    n_case=int(sys.stdin.readline().rstrip())
    for i in range(n_case):
        print 'Case #%d: %s'%(i+1,proc_case())
    

sys.setrecursionlimit(1000*1000*500)
proc_all()
    

