s = input()
n = int(input())
for _ in range(n):
    l, r = map(int, input().split())
    if l != 1:
        s = s[:l-1] + s[l-1:r][::-1] + s[r:]
    else:
        s = s[l-1:r][::-1] + s[r:]
print(s)