N = int(input())
s = input()
ans = 0
while 'bcabcab' in s:
    s = s.replace('bcabcab', 'b', 1)
    ans += 3
if s == 'b':
    pass
elif s == 'abc':
    ans += 1
elif s == 'cabca':
    ans += 2
else:
    print(-1)
    exit()
print(ans)