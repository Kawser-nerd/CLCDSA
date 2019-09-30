n=int(input())
s=[input()[::-1]for i in range(n)]
s.sort()
for i in range(n):print(s[i][::-1])