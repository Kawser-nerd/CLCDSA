n, m = map(int, input().split())
n = n % 12
n_angle = n * 30 + m * 0.5
m_angle = m * 6
print(min(abs(n_angle - m_angle), 360 - abs(n_angle - m_angle)))