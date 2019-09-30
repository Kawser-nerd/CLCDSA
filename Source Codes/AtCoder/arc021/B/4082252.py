def b_xored(L, B):
    a = [0] * L
    # x ^ x = 0 ???? B_k = A_k ^ A_{k+1} ? A_{k+1} = A_k ^ B_k
    # ??????A???????? A_1 = A_L ^ B_L ??????????
    # A_1 = 0 ???????
    for k in range(L - 1):
        a[k + 1] = B[k] ^ a[k]
    ans = '\n'.join(map(str, a)) if B[L - 1] ^ a[L - 1] == a[0] else '-1'
    return ans

L = int(input())
B = [int(input()) for _ in [0] * L]
print(b_xored(L, B))