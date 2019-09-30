def b_candy(N, A):
    right = 0
    ans = 0
    chosen_candy = set()

    # ???
    for left in range(N):
        # ??????????????
        while right < N and not(A[right] in chosen_candy):
            chosen_candy.add(A[right])
            right += 1

        chosen_candy.remove(A[left])  # ????????????
        ans = max(right - left, ans)  # 0???????????[l, r]?????r-l

    return ans

N = int(input())
A = [int(i) for i in input().split()]
print(b_candy(N, A))