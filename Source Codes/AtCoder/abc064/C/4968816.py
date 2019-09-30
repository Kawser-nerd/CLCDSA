#13:27
N = int(input())
A = list(map(int,input().split()))
ex_red = [0]*8
red_cnt = 0

for i in range(8):#0-7
    for j in range(N):
        if 400*i<=A[j] and A[j]<400*(i+1):
            ex_red[i]+=1
n = 0
for i in range(N):
    if 3200 <= A[i]:
        n += 1
not_red_color = 0
c = 0
for i in range(8):
    if ex_red[i] > 0:
        c += 1
#print(c)#soreigai_count
#print(n)#red_count

max_ans = n + c

#min_ans
if c >= 1:
    min_ans = c
elif c == 0:
    min_ans = 1
print(min_ans, max_ans)