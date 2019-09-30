N, X = map(int, input().split())
m_list = [int(input()) for i in range(N)]
ans = 0
for i in m_list:
    X -= i
    ans += 1
ans += X // min(m_list)
print(ans)