N = int(input())
max = 0
sum = 0
ans = ''
for i in range(N):
    tmp = input().split()
    sum += int(tmp[1])
    if int(tmp[1]) > max:
       ans =  tmp[0]
       max = int(tmp[1])
if max > sum / 2:
    print(ans)
else:
    print('atcoder')