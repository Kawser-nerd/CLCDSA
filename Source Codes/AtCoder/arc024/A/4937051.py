L, R = map(int, input().split())
l = [int(i) for i in input().split()]
r = [int(i) for i in input().split()]

cnt = 0
for i in range(L):
    for j in range(len(r)):
        if l[i] == r[j]:
            del r[j]
            cnt += 1
            break
            
print(cnt)