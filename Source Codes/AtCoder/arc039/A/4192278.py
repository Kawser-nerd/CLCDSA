def a_problem(A, B):
    # A????????9??????B????????0(????1)?????
    ans = -float('inf')
    for i in range(3):
        a_str = str(A)
        a_mod = int(a_str[:i] + '9' + a_str[i + 1:])
        ans = max(ans, a_mod - B)
    for i in range(3):
        b_str = str(B)
        b_mod = int(b_str[:i] + ('1' if i == 0 else '0') + b_str[i + 1:])
        ans = max(ans, A - b_mod)
    return ans

A, B = [int(i) for i in input().split()]
print(a_problem(A, B))