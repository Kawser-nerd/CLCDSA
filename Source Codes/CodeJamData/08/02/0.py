import sys

def time_to_minutes(s):
    return int(s[:2])*60+int(s[3:])
    
def fetch_lines(n):
    return map(lambda i:sys.stdin.readline().rstrip(),range(n))


def parse_trip(s):
    dep,arr=map(time_to_minutes,s.split())
    assert dep<arr
    return (dep,arr)
    
def proc_case():
    # parse
    t_ta=int(sys.stdin.readline().rstrip())
    na,nb=map(int,sys.stdin.readline().split())
    
    qa=map(parse_trip,fetch_lines(na))
    qb=map(parse_trip,fetch_lines(nb))

    qa.sort()
    qb.sort()
    
    # expand to events (A,B-departure,A,B-available)
    events=[]
    for (dep,arr) in qa:
        events.append((dep,'A-'))
        events.append((arr+t_ta,'B+'))

    for (dep,arr) in qb:
        events.append((dep,'B-'))
        events.append((arr+t_ta,'A+'))

    events.sort()
    
    # assume no trains on A and B at first, and compensate later.
    trs_a=0
    trs_b=0
    trs_a_log=[0]
    trs_b_log=[0]
    
    for (time,ev) in events:
        if ev=='A+':
            trs_a+=1
        elif ev=='A-':
            trs_a-=1
        elif ev=='B+':
            trs_b+=1
        elif ev=='B-':
            trs_b-=1
        else:
            assert False
        
        trs_a_log.append(trs_a)
        trs_b_log.append(trs_b)
    
    return '%d %d'%(-min(trs_a_log),-min(trs_b_log))
    


def proc_all():
    n_case=int(sys.stdin.readline().rstrip())
    for i in range(n_case):
        print 'Case #%d: %s'%(i+1,proc_case())
    

#sys.setrecursionlimit(1000*1000*500)
proc_all()
    

