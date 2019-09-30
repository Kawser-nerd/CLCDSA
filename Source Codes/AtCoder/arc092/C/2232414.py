def solve(n, aaa):
    odd_idx, even_idx = [], []
    odd_sum, even_sum = 0, 0

    for i in range(0, n, 2):
        if aaa[i] > 0:
            even_idx.append(i)
            even_sum += aaa[i]
    for i in range(1, n, 2):
        if aaa[i] > 0:
            odd_idx.append(i)
            odd_sum += aaa[i]

    if odd_sum < even_sum:
        ans = even_sum
        idx = even_idx
    else:
        ans = odd_sum
        idx = odd_idx
    if ans == 0:
        import numpy as np
        i = np.argmax(aaa)
        ans = aaa[i]
        buf = list(range(n, i + 1, -1)) + [1] * i
        return ans, buf

    j = idx[-1]
    buf = list(range(n, j + 1, -1))
    for i in idx[-2::-1]:
        buf.extend(range((i + j) // 2 + 1, i + 1, -1))
        j = i
    buf += [1] * idx[0]
    return ans, buf


n = int(input())
aaa = list(map(int, input().split()))
ans, buf = solve(n, aaa)
print(ans)
print(len(buf))
print('\n'.join(map(str, buf)))