def b_cd_case(N, M, Disk):
    ans = list(range(N + 1))  # 0?????????CD????
    for d in Disk:
        ans[ans.index(d)], ans[0] = ans[0], ans[ans.index(d)]
    ans = '\n'.join(map(str, ans[1:]))
    return ans

N, M = [int(i) for i in input().split()]
Disk = [int(input()) for _ in range(M)]
print(b_cd_case(N, M, Disk))