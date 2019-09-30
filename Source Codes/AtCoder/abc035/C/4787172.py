import sys
input = sys.stdin.readline
n, q = (int(i) for i in input().split())
lr = [[int(i)-1 for i in input().split()] for i in range(q)]

cnt = [0]*n

for l,r in lr:
    cnt[l] +=1
    if r<n-1:
        cnt[r+1] -=1
        
res = ""
c = 0
for x in cnt:
    c += x
    res+=str(c%2)

print(res)