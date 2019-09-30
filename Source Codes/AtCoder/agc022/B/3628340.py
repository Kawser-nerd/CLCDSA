N = int(input())

if N == 3:
    ans = {2, 3, 25}
elif N == 4:
    ans = {2, 3, 4, 9}
elif N == 5:
    ans = {2, 3, 4, 6, 9}
else:
    ans = set()
    sumAns = 0
    num = 0
    # 2???????3??????????????
    for i in range(1, 30001):
        if i % 2 == 0 or i % 3 == 0:
            ans.add(i)
            sumAns += i
            num += 1

        if num == N: break

    # [???6???]??????????
    if sumAns % 6 == 2:
        ans.remove(8)
        ans.add(((i + 6) // 6) * 6) # ??6???
    elif sumAns % 6 == 3:
        ans.remove(9)
        ans.add(((i + 6) // 6) * 6) # ??6???
    elif sumAns % 6 == 5:
        ans.remove(9)
        ans.add(((i + 2) // 6) * 6 + 4) # ??6k+4????

print(' '.join(map(str, ans)))