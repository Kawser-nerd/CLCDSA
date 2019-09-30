n, m = map(int, input().split())

n %= 12
n += m/60

n_theta = n/12*360
m_theta = m/60*360

theta = max(n_theta, m_theta) - min(n_theta, m_theta)
print(min(theta, 360 - theta))