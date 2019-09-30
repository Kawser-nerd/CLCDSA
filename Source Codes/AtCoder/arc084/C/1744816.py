def solve(k, n):
    if k & 1 == 0:
        return [k // 2] + [k] * (n - 1)
    ans = [k // 2 + 1] * n
    l = n
    for i in range((n - 2) // 2 + 1):
        if ans[-1] == 1:
            ans.pop()
            l -= 1
        else:
            ans[-1] -= 1
            if l < n:
                ans += [k] * (n - l)
                l = n
    return ans


k, n = map(int, input().split())

print(*solve(k, n))