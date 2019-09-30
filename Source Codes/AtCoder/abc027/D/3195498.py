S = input()
t = 0
arr = []
for c in S[::-1]:
    if c == '+':
        t += 1
    elif c == '-':
        t -= 1
    else:
        arr.append(t)
arr = sorted(arr)
ans = 0
for i in range(len(arr)):
    if i < len(arr) // 2:
        ans -= arr[i]
    else:
        ans += arr[i]
print(ans)