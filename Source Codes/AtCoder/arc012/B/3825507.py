N,va,vb,L = (int(i) for i in  input().split())
#va:takahashi vb:kame

takahashi = 0
kame = L
for i in range(N):
    time = L / va
    takahashi += L
    kame += vb*time
    L = kame - takahashi

print(L)