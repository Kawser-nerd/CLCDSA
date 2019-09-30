def solve(m_list):
    min_val = m_list[0]
    # time O(N log(A))
    for m in m_list:
        min_val = min(min_val, gcd(min_val, m))
    return min_val


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def main():
    n = int(input())
    m_list = list(map(int, input().split()))

    ans = solve(m_list)
    print(ans)


main()