import collections
MAX_N = 10**5+1
MOD = 1000000007

same_dist = [0]*(MAX_N+1)
same_dist[1] = 1
for i in range(2, MAX_N+1):
    same_dist[i] = same_dist[i-1]*pow(2, i-1, MOD)
    same_dist[i] %= MOD

n = int(input())
a = list(map(int, input().split()))

cnt_num = collections.Counter(a)

if not(cnt_num[0] == 1 and a[0] == 0):
    print(0)
    exit()

if len(a) == 1:
    print(1)
    exit()

ans = 1
cnt = 1

for i in range(1,n):
    if cnt_num[i] == 0:
        print(0)
        exit()
    else:
        ans *= same_dist[cnt_num[i]]
        ans %= MOD
        ans *= pow((2**cnt_num[i-1] - 1), cnt_num[i], MOD)
        ans %= MOD
    cnt += cnt_num[i]
    if cnt == len(a):
        print(ans)
        exit()