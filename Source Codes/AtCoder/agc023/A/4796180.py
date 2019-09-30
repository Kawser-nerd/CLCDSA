import collections
N = int(input())
A = list(map(int, input().split()))
summ = [0]
for i in range(N):
  summ.append(summ[-1]+A[i])
s = collections.Counter(summ)
s = s.most_common()
ans = 0
for i in range(len(s)):
    if s[i][1] >= 2:
        ans += s[i][1]*(s[i][1]-1)//2
print(ans)