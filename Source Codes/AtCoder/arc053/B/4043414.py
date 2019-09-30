s = list(input())

cnt = [0]*26
for e in s:
    cnt[ord(e)-97]+=1

a = 0 #1??
b = 0 #2??
for i in range(26):
    a += cnt[i]%2
    b += cnt[i]//2

if a > 0:
    res = 1
    res += (b//a)*2
    print(res)
else:
    print(len(s))