N, R = map(int, input().split())
inputs = list(input())

remain = inputs.count('.')
ans = 0
for i in range(N-R+1):
    not_painted = inputs[i:i+R].count('.')
    if remain == 0:
        break
    if remain == not_painted:
        ans += 1
        break
    if inputs[i] == '.':
        for j in range(i, i+R):
            inputs[j] = 'o'
        remain -= not_painted
        ans += 1
    ans += 1                

print(ans)