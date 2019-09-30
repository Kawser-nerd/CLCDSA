ri = lambda: int(input())
rl = lambda: list(map(int,input().split()))
rr = lambda N: [ri() for _ in range(N)]
YN = lambda b: print('YES') if b else print('NO')
yn = lambda b: print('Yes') if b else print('No')
OE = lambda x: print('Odd') if x%2 else print('Even')
INF = 10**18

N,C=rl()
st = [[] for _ in range(C)]
TT1 = [0 for _ in range(10**5+2)]
for i in range(N):
    s,t,c = rl()
    TT1[s] += 1
    TT1[t+1] -= 1
    st[c-1].append([s,t])
for st_i in range(len(st)):
    st_ = st[st_i]
    if len(st_) <= 1: continue
    st_.sort(key=lambda x:x[0])
    l = []
    new = 0
    lst_ = len(st_)
    for i in range(lst_):
        if new == 0:
            s,t = st_[i]
            if i != lst_ -1 and t==st_[i+1][0]:
               new = 1
               continue
            else:
                l.append([s,t])
        else:
            t = st_[i][1]
            if i != lst_ -1 and t==st_[i+1][0]:
                new = 1
                continue
            else:
                l.append([s,t])
    st[st_i] = l


TT2 = [0 for _ in range(10**5+2)]

for st_ in st:
    if len(st_) == 0: continue
    for i in range(len(st_)):
        TT2[st_[i][0]] += 1
        TT2[st_[i][1]+1] -= 1

for i in range(1,len(TT1)):
    TT1[i] += TT1[i-1]
    TT2[i] += TT2[i-1]

print(min(max(TT1),max(TT2)))