n,m = map(int,input().split())

if n > 12:
    n -= 12
    
n_k = 30*n+(0.5)*m
m_k = 6*m


print(min(360-abs(n_k-m_k),abs(n_k-m_k)))