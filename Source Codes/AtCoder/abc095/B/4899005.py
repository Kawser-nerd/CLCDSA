N, X = map(int, input().split())

ans = 0
m_min = 10000
for i in range(N):
    m = int(input())
    X -= m
    ans += 1
    if m < m_min:
        m_min = m

ans += X//m_min
print(ans)