n = int(input())
s = input().rstrip('.').split()
ans = 0
for i in range(n):
    if s[i] == 'TAKAHASHIKUN'\
    or s[i] == 'Takahashikun'\
    or s[i] == 'takahashikun':
        ans += 1
print(ans)