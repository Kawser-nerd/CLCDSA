A = input()

length = len(A)
ans = 0
diff = 0 # ????????????????
if length != 1:
    for i in range(length // 2):
        if A[i] != A[-1 - i]:
            diff += 1
    ans = 25 * length
    if diff == 0 and length % 2 == 1:
        ans -= 25
    elif diff == 1:
        ans -= 2

print(ans)