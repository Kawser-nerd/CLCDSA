with open('A-large.in','r') as f, open('out.txt','w') as fout:
    t=int(f.readline().strip())
    for case in range(1,t+1):
        d,n=[int(s) for s in f.readline().strip().split()]
        last_arrive=0
        for i in range(n):
            ki,si=[int(s) for s in f.readline().strip().split()]
            last_arrive=max(last_arrive,((d-ki)/si))
        print('Case #%d: %.6f'%(case, d/last_arrive),file=fout)
