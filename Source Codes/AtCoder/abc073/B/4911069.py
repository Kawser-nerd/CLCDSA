N=  int(input())

res = 0
for i in range(0,N):
    l,r = map(int,input().split())
    res += r - l + 1

print(res)