def solve(r,o,y,g,b,v):
    e={}
    e['rg']=2*g
    e['yv']=2*v
    e['bo']=2*o
    e['rb']=r+b-y-g-o+v
    e['by']=b+y-r-o-v+g
    e['yr']=y+r-b-v-g+o
    edges=list(e.keys())
    for k in edges:
        e[k[::-1]]=e[k]
    adj={'r':['y','b','g'], 'b':['r','y','o'], 'y':['b','r','v'], 'g':['r'], 'o':['b'], 'v':['y']}
    vs=adj.keys()
    if e['rb']<0 or e['by']<0 or e['yr']<0:
        return 'IMPOSSIBLE'

    if e['rg']>0 or e['rb']>0 or e['yr']>0:
        v1='r'
    elif e['bo']>0 or e['by']>0:
        v1='b'
    else:
        v1='y'
    ret=[]
    used_v=set([v1])
    used_e=set()
    while max(e.values())>0:
        find_v=False
        for v0 in vs:
            if v0 in used_v:
                for w in adj[v0]:
                    if e[v0+w]>0 and v0+w not in used_v:
                        find_v=True
                        route=[]
                        curr=v0
                        while max(e[curr+v] for v in adj[curr])>0:
                            for v in adj[curr]:
                                if e[curr+v]>0:
                                    e[curr+v]-=1
                                    e[v+curr]-=1
                                    route.append(v)
                                    used_v.add(v)
                                    used_e.add(v+curr)
                                    used_e.add(curr+v)
                                    curr=v
                                    break
                        if len(ret)==0:
                            ret=route
                        else:
                            idx=ret.index(v0)+1
                            ret=ret[:idx]+route+ret[idx:]
        if not find_v:
            return 'IMPOSSIBLE'
    return ret

with open('B-large.in','r') as f, open('out.txt','w') as fout:
    print('Input file:',f.name)
    t=int(f.readline().strip())
    for case in range(1,t+1):
        n,r,o,y,g,b,v=[int(s) for s in f.readline().strip().split()]
        ret=solve(r,o,y,g,b,v)
        print('Case #%d:'%case,''.join(ret).upper(),file=fout)
