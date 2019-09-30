N,K = map(int,input().split(" "))
t = []
for i in range(N):
    t.append(int(input()))
#print(t)
flag = 0
for i in range(N-2):
    total = t[i] + t[i+1] + t[i+2]
    if total < K:
        print(i+3)
        flag = 1
        break
if flag == 0:
    print(-1)