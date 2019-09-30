def b_wonderland(B, N, A):
    dict_to_atcoder = {}  # ????AtCoder??????????
    dict_to_our = {}  # ???
    for k, b in enumerate(B):
        k = str(k)
        dict_to_atcoder[b] = k
        dict_to_our[k] = b

    # AtCoder???????????????????
    a_atcoder = []
    for a in A:
        tmp = ''
        for c in a:
            tmp += dict_to_atcoder[c]
        a_atcoder.append(int(tmp))

    a_atcoder.sort()

    # ??????????
    ans_tmp = []
    for a in a_atcoder:
        tmp = ''
        a = str(a)
        for c in a:
            tmp += dict_to_our[c]
        ans_tmp.append(tmp)
    ans = '\n'.join(ans_tmp)
    return ans

B = input().split()
N = int(input())
A = [input() for _ in range(N)]
print(b_wonderland(B, N, A))