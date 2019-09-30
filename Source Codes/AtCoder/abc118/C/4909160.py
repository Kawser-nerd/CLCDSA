def solve(m_list):
    m_val = m_list[0]
    for i in m_list:
        m_val = min(m_val,gcd(m_val,i))
    return m_val

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

def main():
    n = int(input())
    m_list = list(map(int,input().split()))

    ans = solve(m_list)
    print(ans)

main()