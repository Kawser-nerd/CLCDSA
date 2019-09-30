N, M = map(int, input().split())
ab = []
cd = []
for i in range(N):
    a, b = map(int, input().split())
    ab.append([a, b])

for i in range(M):
    c, d = map(int, input().split())
    cd.append([c, d])

for i in range(N):
    m_min = 100000000000
    i_min = -1
    for j in range(M):
        m = abs(ab[i][0] - cd[j][0]) + abs(ab[i][1] - cd[j][1])
        if m < m_min:
            m_min = m 
            i_min = j
    print(i_min+1)