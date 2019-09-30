L, N = list(map(int, input().split()))
X = [int(input()) for i in range(N)]

ans0 = X[0]
# 0, -1, 1, -2, ...
i = 0
j = N-1
direc = 1 # direction: left->1, right->-1
while i!=j:
    direc *= -1
    ans0 += L+X[i]-X[j]
    if direc==-1:
        i += 1
    elif direc==1:
        j -= 1
if N%2==0:
    i = N//2
    j = N//2
else:
    i = N//2
    j = N//2+1
tmp_ans = ans0
for k in range(N-1):
    tmp_ans += -L-2*X[k]+X[i]+X[j]
    if i==j:
        j += 1
    else:
        i += 1
    ans0 = max(ans0, tmp_ans)
 
 
''' Start at X[N-1] '''
''' In the case when turn first '''
ans1 = L-X[N-1]
i = 0
j = N-1
direc = -1 # direction: left->1, right->-1
while i!=j:
    direc *= -1
    ans1 += L+X[i]-X[j]
    if direc==-1:
        i += 1
    elif direc==1:
        j -= 1
if N%2==0:
    i = (N-2)//2
    j = (N-2)//2
else:
    i = (N-2)//2
    j = (N-2)//2+1
tmp_ans = ans1
for k in reversed(range(1, N)):
    tmp_ans += -L+2*X[k]-X[i]-X[j]
    if i==j:
        i -= 1
    else:
        j -= 1
    ans1 = max(ans1, tmp_ans)
 
print(max(ans0, ans1))