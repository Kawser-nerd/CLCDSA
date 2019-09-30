n = int(input())
a = list(int(i) for i in input().split())
sa = [0] * (n+1)
num_cnt = {}    
for i in range(n):
    sa[i + 1] = sa[i] + a[i]

for num in sa:
    if num in num_cnt:
        num_cnt[num] += 1
    else:
        num_cnt[num] = 1


res = 0
for cnt in num_cnt.values():
    res += cnt*(cnt-1)//2

print(res)