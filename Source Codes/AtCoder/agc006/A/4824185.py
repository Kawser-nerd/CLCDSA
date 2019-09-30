n = int(input())
s = input()
t = input()
cnt = 0
for i in range(n):
    if s[n-1-i:] == t[0:i+1]:
        cnt = max(cnt, i+1)
print(2*n - cnt)