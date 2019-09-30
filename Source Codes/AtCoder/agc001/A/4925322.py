n = int(input())
l = [int(i) for i in input().split()]
l.sort()

cnt=0
for i in range(n):
    cnt += l[2*i]

print(cnt)