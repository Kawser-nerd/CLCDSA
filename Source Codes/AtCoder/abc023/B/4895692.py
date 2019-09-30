N = int(input())
S = input()
ans = -1
s = 'b'
for i in range(1, N + 1):
    if s == S:
        ans = i - 1
        break
    s = ['b', 'a', 'c'][i % 3] + s + ['b', 'c', 'a'][i % 3]
print(ans)