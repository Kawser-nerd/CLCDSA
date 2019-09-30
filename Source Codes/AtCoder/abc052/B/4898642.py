n = int(input())
s = input()
curr = 0
ans = 0
for i in s:
    if i == 'I': curr += 1
    if i == 'D': curr -= 1
    ans = max(curr, ans)
print(ans)