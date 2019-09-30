def a_holidog(N):
    if N == 1:
        return 'BOWWOW'

    total = N * (N + 1) // 2
    ans = 'BOWWOW'
    for k in range(2, int(total**0.5) + 1):
        if total % k == 0:
            break
    else:
        ans = 'WANWAN'
    return ans

N = int(input())
print(a_holidog(N))