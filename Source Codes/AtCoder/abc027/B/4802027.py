n = int(input())
a = [int(i) for i in input().split()]

if sum(a) % n != 0:
    print(-1)
    exit()

ave = sum(a) / n

cnt = 0
sub_cnt = 0
sub_sum = 0
for i in range(n):
    sub_sum+=a[i]
    sub_cnt+=1
    if sub_sum / sub_cnt == ave:
        sub_sum=0
        sub_cnt=0
        continue

    cnt+=1

print(cnt)