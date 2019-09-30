import sys
n,L = map(int,input().split())
p = []
for i in range(n):
    x,d = map(str,input().split())
    p.append([int(x),d])


res = 0
start = -1
for i in range(n):
    if p[i][1] == 'R':
        start = i
        break
    else:
        res += p[i][0]-1-i
end = n
for i in range(n-1,-1,-1):
    if p[i][1] == 'L':
        end = i
        break
    else:
        res += L-p[i][0]-(n-1-i)
if start == -1 or end == n:
    print(res)
    exit()


cnt_r = 0
cnt_l = 0
end_r = 0
start_l = 0
q = 0
for i in range(start,end+1):
    if p[i][1] == 'R':
        res += (p[i][0]-end_r-1)*cnt_r
        end_r = p[i][0]
        cnt_r += 1
    else:
        if cnt_l == 0:
            q = p[i][0]-end_r-1
            start_l = p[i][0]
        res += p[i][0]-start_l-cnt_l
        cnt_l += 1
        if i == end or p[i+1][1] == 'R':
            res += q*max(cnt_r,cnt_l) 
            cnt_r = 0
            cnt_l =0
print(res)