N, R = map(int, input().split())
inputs = list(input())

not_painted = inputs.count('.')
ans = 0
if not_painted != 0:
    for i in range(N-R+1):
        target_counts = inputs[i:i+R].count('.')
        if not_painted == target_counts:
            ans += 1
            break
        if inputs[i] == '.':
            for j in range(i, i+R):
                inputs[j] = 'o'
            not_painted -= target_counts
            ans += 1
        ans += 1                

print(ans)