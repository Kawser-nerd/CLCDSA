c=int(input())
info=[]
for i in range(c):
    info.append(list(map(int,input().split())))
    

n_max=0
m_max=0
l_max=0
for j in range(c):
    info[j].sort()
    if n_max<info[j][0]:
        n_max=info[j][0]
    if m_max<info[j][1]:
        m_max=info[j][1]
    if l_max<info[j][2]:
        l_max=info[j][2]
        
print(n_max*m_max*l_max)