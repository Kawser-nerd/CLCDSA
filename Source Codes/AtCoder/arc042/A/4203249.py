def a_bbs(N, M, A):
    written_thread = set()
    ans = []
    for a in reversed(A):
        if a not in written_thread:
            written_thread.add(a)
            ans.append(a)
    remain_thread = set(range(1, N + 1)) - written_thread  # ?????????????
    ans.extend(sorted(remain_thread))
    ans = '\n'.join(map(str, ans))
    return ans

N, M = [int(i) for i in input().split()]
A = [int(input()) for _ in [0] * M]
print(a_bbs(N, M, A))